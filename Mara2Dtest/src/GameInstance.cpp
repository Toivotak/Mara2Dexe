#include "GameInstance.h"

void Mara::GameInstance::SetManager(Manager manager) {

	this->manager = manager;
}

void Mara::GameInstance::SetObjectsRay(std::vector<GameObjects> objectRay) {

	this->objectRay = objectRay;
}

std::vector<Mara::GameObjects> Mara::GameInstance::GetObjectsRay() {
	
	return objectRay;
}

void Mara::GameInstance::Run() {

	Mara::Window *window = new Mara::Window();
	std::cout << manager.GetEntity(0).GetComponent(0).has_value() << '\n';
	std::cout << manager.GetEntity(0).ComponentRaySize() << '\n';

	Mara::TextComp nn;
	try {
		nn = std::any_cast<Mara::TextComp>(manager.GetEntity(0).GetComponent(0));
	}
	catch (const std::bad_any_cast & e) {
		std::cout << e.what() << '\n';
	}
	std::cout << nn.s.x << '\n';
	window->Init("aa", 3, false, manager);/**/

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
