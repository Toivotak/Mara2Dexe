#pragma once
#include <vector>
#include "Window.h"
#include "GameObject.h"
#include "GameObjects.h"
#include "Vector2.h"


namespace Mara {

	class GameInstance {

	private:
		const int FPS = 60;						// managing frame rate 
		const int frameDelay = 1000 / FPS;
		Uint32 frameStart;
		int frameTime;

		
		std::vector<GameObjects> objectRay;

	public:

		void SetObjectsRay(std::vector<GameObjects> objectRay);
		
		std::vector<GameObjects> GetObjectsRay();
		GameObjects GetGameObjects(int i);
		void Run();

		~GameInstance();
	};
};
