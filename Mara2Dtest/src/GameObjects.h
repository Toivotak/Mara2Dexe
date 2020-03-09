#pragma once
#include "GameObject.h"
#include <vector>

namespace Mara {

	class GameObjects {

	private:
		GameObject go;
		std::vector<GameObject> gameObjects;

	public:
		void PushGameObject(GameObject gameObj);
		std::vector<GameObject> GetGameObjects();
		GameObject GetObjext(int i);
	};
}
