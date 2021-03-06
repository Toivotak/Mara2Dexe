#include "Window.h"

SDL_Texture *p, *pa;
Mara::GameObject go;
Mara::GameObject goo;
Mara::GameInstance instance;
Mara::Keyboard *key = new Mara::Keyboard();
Mara::InputManager inputmgr;

int i = 0;

std::vector<SDL_Texture*>tex;
SDL_Rect sRect;
SDL_Rect dRect;

Mara::Window::Window() {

	window = nullptr;
	renderer = nullptr;
	title = "";
	resolution = 1;
	fullscreen = false;
}

void Mara::Window::Init() {

	Uint32 flags = this->fullscreen | SDL_WINDOW_ALLOW_HIGHDPI;

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
	
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DefaultResolutions[2].x, DefaultResolutions[2].y, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		if (window) {	
		}
	}
}

void Mara::Window::Init(const char* title, int resolution, bool fullscreen, Mara::Manager manager) {/**/

	Uint32 fc = SDL_WINDOW_FULLSCREEN;
	if (!fullscreen) {
		fc = 0;
	}
	Uint32 flags = fc | SDL_WINDOW_ALLOW_HIGHDPI;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "ok\n";
	
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DefaultResolutions[resolution].x, DefaultResolutions[resolution].y, flags);
		if (window) {
			std::cout << "ok\n";
		}
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "ok\n";
		}
		
		active = true;
	}
	
	goo.SetDestinationRect(0, 0, 128, 64);
	goo.SetSourceRect(0, 0, 128, 64);
	goo.SetMoveable(true);

	goo.SetSurface("src/assets/Man1.png");

	p = SDL_CreateTextureFromSurface(renderer, goo.GetSurface());
	std::cout << manager.GetEntity(0).ComponentRaySize();
	Manager mgr = manager;
	std::cout << mgr.GetEntity(0).ComponentRaySize();

	TextComp uusi;
	Entity uusientity;
	uusientity = manager.GetEntity(0);
	std::cout << uusientity.ComponentRaySize();
	
	try {
		uusi = std::any_cast<TextComp>(uusientity.GetComponent(0));
	}
	catch (const std::bad_any_cast & e) {
		std::cout << e.what() << '\n';
	}

	std::cout << uusi.d.x;
	
	for (int j = 0; j < mgr.EntityRaySize(); j++) {
		
		Entity entity;
		entity = mgr.GetEntity(j);

		for (int i = 0; i < entity.ComponentRaySize(); i++) {
			TextComp component;// = new Component();
			component = std::any_cast<TextComp>(entity.GetComponent(i));

			if(component.ID == 1) {
				
				pa = SDL_CreateTextureFromSurface(renderer, component.surf);
				tex.push_back(pa);
				//delete texCom;
			}
			else {}
		}
		//delete entity;
	}
}

void Mara::Window::Draw(const char*) {
}

void Mara::Window::HandleEvents() {

	SDL_PollEvent(&event);
	
	switch (event.type) {
	case SDL_QUIT:
		active = false;
		break;
	
	default:
		break;
	}
}

void Mara::Window::Update() {

	goo.SetDestinationRect(i, i, i, i);
	std::cout << i << "\n";
	/*go.SetDestinationRect(i, i, i, i);
	go.SetSourceRect(i, i, i, i);
	
	//key.KeyEvent2();
	//SDL_PollEvent(&event);
	/*key->GetEvent(event);
	inputmgr.Update();
	dRect = key->KeyEvent(goo);

	goo.SetDestinationRect(key->KeyEvent(goo));
	//*/
	i++;
}

void Mara::Window::Render(std::vector<GameObjects> objectsRay) {

	SDL_RenderClear(renderer);
	
	/*instance.GetObjectsRay() = objectsRay;
	
	for (int j = 0; j < instance.GetObjectsRay().size(); j++) {

		GameObjects* gameObjects = new GameObjects();
		gameObjects = &instance.GetGameObjects(j);

		for (int i = 0; i < tex.size(); i++) {
			go = gameObjects->GetObject(i);
			SDL_RenderCopy(renderer, tex[i], &go.GetSourceRect(), &go.GetDestinationRect());
		}
		delete gameObjects;
	}*/
	SDL_RenderCopy(renderer, p, &goo.GetSourceRect(), &goo.GetDestinationRect());

	SDL_RenderPresent(renderer);
}

void Mara::Window::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete key;
}

bool Mara::Window::IsActive(){
	return active;
}

Mara::Window::~Window() {
}
