#include "Input.h"

#include <cstring>

void Input::Init() {
	memset(_previousInput, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
	memcpy(_currentInput, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);
};

void Input::Update() {
	memcpy(_previousInput, _currentInput, sizeof(Uint8) * SDL_NUM_SCANCODES);
	memcpy(_currentInput, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);

	// Reset Mouse Motion
	_lastMotion.x = 0;
	_lastMotion.y = 0;
};

bool Input::IsKeyReleased(const SDL_Scancode keyCode) const
{
	return _previousInput[keyCode] == 0 && _currentInput[keyCode] == 1;
}

bool Input::IsKeyPressed(const SDL_Scancode keyCode) const {
	return _currentInput[keyCode] == 1;
};

bool Input::IsKeyTriggered(const SDL_Scancode keyCode) const {
	return _currentInput[keyCode] == 1 && _previousInput[keyCode] == 0;
};


void Input::SetLastMouseMotion(float lastMotionX, float lastMotionY) { 
	_lastMotion.x = lastMotionX;
	_lastMotion.y = lastMotionY; 
}