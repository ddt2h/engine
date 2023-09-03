#ifndef REPLICATOR_HPP
#define REPLICATOR_HPP

#include "SFML/Graphics.hpp"
#include <cstdio>
#include <chrono>
#include <dinput.h>
#include <iostream>

#include "../src/Emulation.hpp"

struct FrameScan {
	sf::Vector2i mousePos;

	double timing;

	//Mouse ->
	std::vector<std::pair<int, int>> holdingKeyboardKeys; //0 - not active, 1 - holding, 2 - released
	std::vector<int> holdingMouseButtons;
};


class Replication {
public:
	Replication() = default;

	void initReplication(bool repeated = false);

	void addReplicationScanKey(sf::Keyboard::Key bindKey, int DIKEYBOARD_KEY);

	void updateRecording(sf::Keyboard::Key startRecordKey, sf::Keyboard::Key startReplicateKey);

	void setMouseMultiplicationFactor(float factor);

	void setDirectionBased(bool value);

	void addCustomScan(FrameScan scan);

	void addCustomScan(double timing, sf::Vector2i mousePos);

private:
	sf::Clock clock;

	std::vector<std::pair<sf::Keyboard::Key, int>> keyMap;
	int checkingCounter = 0;

	std::vector<FrameScan> frameScans;

	std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

	float mouseMultiplication{ 1.0f };

	bool isRepeated{ false };
	bool isDirectionBased{ false };

	void lockThreadRate(double frameTime);

	void performScanFrame();

	void performParse();

};

#endif // !REPLICATOR_HPP
