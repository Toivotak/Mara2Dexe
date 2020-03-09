#include "Window.h"

SDL_Texture *p, *pa;
Mara::GameObject go;
Mara::GameObject goo;
Mara::GameInstance instance;
Mara::Keyboard keyboardInput;

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

void Mara::Window::Init(const char* title, int resolution, bool fullscreen, GameObjects gameObjects) {

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
	
	goo.SetDestinationRect(0, 0, 32, 32);
	goo.SetSourceRect(0, 0, 32, 32);

	goo.SetSurface("src/assets/Ground/RockyGround.png");

	p = SDL_CreateTextureFromSurface(renderer, goo.GetSurface());
	
	for (int i = 0; i < gameObjects.GetGameObjects().size(); i++) {

		go = gameObjects.GetObjext(i);
		
		pa = SDL_CreateTextureFromSurface(renderer, go.GetSurface());
		tex.push_back(pa);
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
	case SDL_KEYDOWN:
		keyboardInput.KeyEvent2(event.key.keysym.sym);
		/*
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:  std::cout << "Key LEFT "  << "\n"; SDL_Delay(100); break;
		case SDLK_RIGHT: std::cout << "Key RIGHT " << "\n"; SDL_Delay(100); break;
		case SDLK_UP:    std::cout << "Key UP "    << "\n"; SDL_Delay(100); break;
		case SDLK_DOWN:  std::cout << "Key DOWN "  << "\n"; SDL_Delay(100); break;
		}
		*/
		break;
	default:
		break;
	}
}

void Mara::Window::Update() {
	
	//std::cout << i << "\n";
	go.SetDestinationRect(i, i, i, i);
	go.SetSourceRect(i, i, i, i);
	
	goo.SetDestinationRect(i, i, 32, 32);
	
	//key.KeyEvent2();
	
	i++;
}

void Mara::Window::Render(GameObjects gameObjects) {

	SDL_RenderClear(renderer);
	
	for (int i = 0; i < tex.size(); i++) {
		go = gameObjects.GetObjext(i);
		SDL_RenderCopy(renderer, tex[i], &go.GetSourceRect(), &go.GetDestinationRect());
	}
	SDL_RenderCopy(renderer, p, &goo.GetSourceRect(), &goo.GetDestinationRect());

	SDL_RenderPresent(renderer);
}

void Mara::Window::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Mara::Window::IsActive(){
	return active;
}

Mara::Window::~Window() {
}
