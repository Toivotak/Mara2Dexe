#include "GameObjects.h"

void Mara::GameObjects::PushGameObject(GameObject gameObj) {

	gameObjects.push_back(gameObj);
}

std::vector<Mara::GameObject> Mara::GameObjects::GetGameObjects() {

	return gameObjects;
}

Mara::GameObject Mara::GameObjects::GetObjext(int i) {

	Mara::GameObject *go = new Mara::GameObject();
	go = &gameObjects[i];
	return *go;
	delete go;
}
