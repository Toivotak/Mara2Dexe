#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Vector2.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "GameObjects.h"
#include "GameInstance.h"
#include "EventHandling/Keyboard.h"
#include "EventHandling/InputManager.h"

namespace Mara {

	static const std::vector<Mara::Vector2> DefaultResolutions = {
		{  640,  480 },
		{  800,  600 },
		{ 1024,  768 },
		{ 1152,  864 },
		{ 1280,  800 },
		{ 1280,  960 },
		{ 1280, 1024 },
		{ 1400, 1050 },
		{ 1600, 1200 },
		{ 1680, 1050 },
		{ 1920, 1080 },
		{ 1920, 1200 }
	};

	class Window {

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Event event;
		int resolution;
		bool fullscreen;
		bool active = true;
		const char* title;
		
	public:
		Window();

		void Init();
		void Init(const char* title, int resolution, bool fullscreen, GameInstance objectsRay);
		void Draw(const char*);
		void HandleEvents();
		void Update();
		void Render(GameInstance objectsRay);
		void Clean();
		bool IsActive();

		~Window();
	};

};