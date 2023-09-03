#include "Replicator.hpp"

//Replication

void Replication::initReplication(bool isRepeated)
{
	clock.restart();
	this->isRepeated = isRepeated;
}

void Replication::addReplicationScanKey(sf::Keyboard::Key bindKey, int DIKEYBOARD_KEY)
{
	keyMap.push_back(std::make_pair(bindKey, DIKEYBOARD_KEY));
}

void Replication::updateRecording(sf::Keyboard::Key startRecordKey, sf::Keyboard::Key startReplicateKey)
{
	static Engine::SingleInput recInput;
	static Engine::SingleInput repInput;
	static Engine::SingleInput exitInput;

	static bool isRecording = false;
	static bool isReplicating = false;

	if (recInput.onClick(startRecordKey)) {
		clock.restart();
		isRecording = !isRecording;

		if (isReplicating) {
			isReplicating = false;
			std::cout << "Replica end" << std::endl;
		}

		if (isRecording) {
			frameScans.clear();
			std::cout << "Record start" << std::endl;
		}

		if (!isRecording) {
			std::cout << "Record end" << std::endl;
		}
	}

	if (repInput.onClick(startReplicateKey)) {
		clock.restart();
		isReplicating = !isReplicating;

		if (isRecording) {
			isRecording = false;
			std::cout << "Record end" << std::endl;
		}


		//On start replication
		if (isReplicating) {
			checkingCounter = 0;
			std::cout << "Replica start" << std::endl;
		}
		if (!isReplicating) {
			std::cout << "Replica end" << std::endl;
		}
	}

	if (exitInput.onClick(sf::Keyboard::Key::F2)) {
		exit(2);
	}

	if (isRecording) {
		//lockThreadRate(200.0f);
		performScanFrame();
	}

	if (isReplicating) {
		performParse();
	}

}

void Replication::setMouseMultiplicationFactor(float factor)
{
	this->mouseMultiplication = factor;
}

void Replication::setDirectionBased(bool value)
{
	this->isDirectionBased = value;
}

void Replication::addCustomScan(FrameScan scan)
{
	this->frameScans.push_back(scan);
}

void Replication::addCustomScan(double timing, sf::Vector2i mousePos)
{
	FrameScan scan;
	scan.timing = timing;
	scan.mousePos = mousePos;
	frameScans.push_back(scan);
}

void Replication::lockThreadRate(double frameTime)
{
	a = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> work_time = a - b;

	if (work_time.count() < frameTime)
	{
		std::chrono::duration<double, std::milli> delta_ms(frameTime - work_time.count());
		auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
		std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
	}

	b = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> sleep_time = b - a;
}

void Replication::performScanFrame()
{
	FrameScan frameScan;

	//Always scan mouse pos

	frameScan.mousePos.x = sf::Mouse::getPosition().x;
	frameScan.mousePos.y = sf::Mouse::getPosition().y;

	frameScan.timing = clock.getElapsedTime().asSeconds();

	//Scanning input, hold

	static std::vector<std::pair<sf::Keyboard::Key, bool>> latestInputs;

	for (int i = 0; i < keyMap.size(); i++) {
		latestInputs.push_back({ sf::Keyboard::Key::Unknown, false });
	}

	for (int i = 0; i < keyMap.size(); i++) {

		//Is holding keyboard key

		if (sf::Keyboard::isKeyPressed(keyMap[i].first)) {
			//Check if previous framescan already has it in holdings

			if (latestInputs[i].first == keyMap[i].first && latestInputs[i].second)
			{
				//Do nothing I guess
			}
			else {
				frameScan.holdingKeyboardKeys.push_back({ keyMap[i].second, 1 });

				latestInputs[i] = { keyMap[i].first, true };
			}
		}
		else {
			//Is NOT holding keyboard key

			if (latestInputs[i].first == keyMap[i].first && latestInputs[i].second) {
				frameScan.holdingKeyboardKeys.push_back({ keyMap[i].second, 2 });

				latestInputs[i].second = false;
			}
			else {
				frameScan.holdingKeyboardKeys.push_back({ keyMap[i].second, 0 });
			}

		}

	}
	frameScans.push_back(frameScan);

}

void Replication::performParse()
{
	if (frameScans.empty())
		return;

	if (checkingCounter == frameScans.size()) {
		return;
	}

	if (clock.getElapsedTime().asSeconds() >= frameScans[checkingCounter].timing) {

		FrameScan frameScan = frameScans[checkingCounter];

		Engine::Emulation::setMousePosition(frameScan.mousePos.x, frameScan.mousePos.y);

		for (int i = 0; i < frameScan.holdingKeyboardKeys.size(); i++) {

			if (frameScan.holdingKeyboardKeys[i].second == 1) {
				Engine::Emulation::holdKeyboardKey(frameScan.holdingKeyboardKeys[i].first);

			}
			if (frameScan.holdingKeyboardKeys[i].second == 2) {
				Engine::Emulation::releaseKeyboardKey(frameScan.holdingKeyboardKeys[i].first);
			}
		}

		checkingCounter++;

		if (checkingCounter == frameScans.size()) {
			if (!isRepeated)
				std::cout << "Reached the end of replication" << std::endl;

			if (isRepeated) {
				std::cout << "End. Repeating..." << std::endl;
				checkingCounter = 0;
				clock.restart();
			}

		}

	}



}