#include "GameInstance.h"

void Mara::GameInstance::SetGameObjects(GameObjects gameObjects) {

	this->gameObjects = gameObjects;
}

void Mara::GameInstance::Run() {

	Mara::Window *window = new Mara::Window();

	window->Init("aa", 3, false, gameObjects);

	while(window->IsActive()) {

		frameStart = SDL_GetTicks();

		window->HandleEvents();
		window->Update();
		window->Render(gameObjects);

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	delete window;
}

Mara::GameInstance::~GameInstance() {
}
