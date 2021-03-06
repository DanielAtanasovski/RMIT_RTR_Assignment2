// Daniel Atanasovski
#include "MainApp.h"

int MainApp::Init() {
	// Error Check
	if (int err = App::Init() != 0) {
		return err;
	}

	_input = std::make_shared<Input>();
	_input->Init();

	_game = std::make_unique<Game>();
	_game->Init(_windowWidth, _windowHeight, _input);

	return 0;
}

bool MainApp::Tick(unsigned int td_milli) {
	_quitApp = false;

	CheckInput();
	CheckEvents();
	Update(td_milli);
	Draw();

	// FPS Count
	_fps++;
	_timeCount += td_milli;
	if ((_timeCount / (float)1000) >= 1.0) {
		_timeCount = 0;
		std::cout << _fps << std::endl;
		_fps = 0;
	}

	return _quitApp;
}

void MainApp::CheckInput() {
	_input->Update();

	if (_input->IsKeyReleased(SDL_SCANCODE_ESCAPE))
		_quitApp = true;
}

void MainApp::CheckEvents()
{
	SDL_Event windowEvent;
	while (SDL_PollEvent(&windowEvent)) {
		if (windowEvent.type == SDL_QUIT) _quitApp = true;
		if (windowEvent.type == SDL_MOUSEMOTION) {
			_input->SetLastMouseMotion(windowEvent.motion.xrel, windowEvent.motion.yrel);
		}
		_game->OnEvent(windowEvent);
	}
}

void MainApp::Update(unsigned int td_milli) {
	float step = td_milli / 1000.0f;
	_game->Update(step);
}

void MainApp::Draw() {
	glClearColor((GLfloat)0.1, (GLfloat)0.1, (GLfloat)0.1, (GLfloat)1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_game->Render();

	SDL_GL_SwapWindow(_window);
}

void MainApp::Done() {
	App::Done();
}

