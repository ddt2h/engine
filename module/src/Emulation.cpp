#include "Emulation.hpp"

void Engine::Emulation::holdLeftMouseButton()
{
	DWORD mouse_down = MOUSEEVENTF_LEFTDOWN;
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = mouse_down;
	::SendInput(1, &Input, sizeof(INPUT));
}

void Engine::Emulation::holdRightMouseButton()
{
	DWORD mouse_down = MOUSEEVENTF_RIGHTDOWN;
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = mouse_down;
	::SendInput(1, &Input, sizeof(INPUT));
}

void Engine::Emulation::releaseLeftMouseButton()
{
	DWORD mouse_up = MOUSEEVENTF_LEFTUP;
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = mouse_up;
	::SendInput(1, &Input, sizeof(INPUT));
}

void Engine::Emulation::releaseRightMouseButton()
{
	DWORD mouse_up = MOUSEEVENTF_RIGHTUP;
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = mouse_up;
	::SendInput(1, &Input, sizeof(INPUT));
}

void Engine::Emulation::clickLeftMouseButton(int delayMs)
{
	std::thread impl(&Engine::Emulation::clickLeftMouseButtonImpl, delayMs);
	impl.detach();
}

void Engine::Emulation::clickRightMouseButton(int delayMs)
{
	std::thread impl(&Engine::Emulation::clickRightMouseButtonImpl, delayMs);
	impl.detach();
}

void Engine::Emulation::scroll(int value)
{
	INPUT in;
	in.type = INPUT_MOUSE;
	in.mi.dwFlags = MOUSEEVENTF_WHEEL;
	in.mi.mouseData = value;
	in.mi.time = 0;
	SendInput(1, &in, sizeof(in));
}

void Engine::Emulation::holdKeyboardKey(int keyCode)
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.wVk = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.dwFlags = KEYEVENTF_SCANCODE;
	ip.ki.wScan = keyCode;

	SendInput(1, &ip, sizeof(INPUT));
}

void Engine::Emulation::releaseKeyboardKey(int keyCode)
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.wVk = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	ip.ki.wScan = keyCode;

	SendInput(1, &ip, sizeof(INPUT));
}

void Engine::Emulation::clickKeyboardKey(int keyCode, int delayMs)
{
	std::thread impl(&Engine::Emulation::clickKeyboardKey, keyCode, delayMs);
	impl.detach();
}

void Engine::Emulation::setMousePosition(int x, int y)
{
	SetCursorPos(x, y);
}

void Engine::Emulation::clickLeftMouseButtonImpl(int delayMs)
{
	holdLeftMouseButton();
	Sleep(delayMs);
	releaseLeftMouseButton();
}

void Engine::Emulation::clickRightMouseButtonImpl(int delayMs)
{
	holdRightMouseButton();
	Sleep(delayMs);
	releaseRightMouseButton();
}

void Engine::Emulation::clickKeyboardKeyImpl(int keyCode, int delayMs)
{
	holdKeyboardKey(keyCode);
	Sleep(delayMs);
	releaseKeyboardKey(keyCode);
}

