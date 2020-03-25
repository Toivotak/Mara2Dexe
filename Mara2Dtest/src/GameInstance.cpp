#include "GameInstance.h"

/*void Mara::GameInstance::SetManager(Manager *manager) {

	this->manager = *manager;
}*/

void Mara::GameInstance::SetObjectsRay(std::vector<GameObjects> objectRay) {

	this->objectRay = objectRay;
}

std::vector<Mara::GameObjects> Mara::GameInstance::GetObjectsRay() {
	
	return objectRay;
}

void Mara::GameInstance::Run() {

	Mara::Window *window = new Mara::Window();

	window->Init("aa", 3, false );/*,manager*/

	while(window->IsActive()) {

		frameStart = SDL_GetTicks();

		window->HandleEvents();
		window->Update();
		window->Render(GetObjectsRay());

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {

			SDL_Delay(frameDelay - frameTime);
		}
	}
	delete window;
}

Mara::GameInstance::~GameInstance() {
}
