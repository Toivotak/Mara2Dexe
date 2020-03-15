#pragma once
#include "GameObject.h"
#include <vector>

namespace Mara {

	class GameObjects {

	private:
		GameObject go;
		std::vector<GameObject> gameObjects;
		std::vector<GameObjects> objectsRay;

	public:
		
		std::vector<GameObject> GetGameObjects();
		void PushGameObject(GameObject gameObj);
		void PushGameObjects(GameObjects gameObjs);

		std::vector<GameObjects> GetObjectsRay();
		std::vector<GameObjects> GetObjectsRay(int i);
		GameObjects GetObjects(int i);
		GameObject GetObject(int i);
	};
}
