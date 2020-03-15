#include "GameObjects.h"

void Mara::GameObjects::PushGameObject(GameObject gameObj) {

	gameObjects.push_back(gameObj);
}

std::vector<Mara::GameObject> Mara::GameObjects::GetGameObjects() {

	return gameObjects;
}

void Mara::GameObjects::PushGameObjects(GameObjects gameObjs) {

	objectsRay.push_back(gameObjs);
}

std::vector<Mara::GameObjects> Mara::GameObjects::GetObjectsRay() {

	return objectsRay;
}

std::vector<Mara::GameObjects> Mara::GameObjects::GetObjectsRay(int i)
{
	Mara::GameObjects* ray = new Mara::GameObjects();
	ray = &objectsRay[i];
	return *ray;
	delete ray;
}

Mara::GameObjects Mara::GameObjects::GetObjects(int i) {

	Mara::GameObjects* gos = new Mara::GameObjects();
	gos = &objectsRay[i];
	return *gos;
	delete gos;
}

Mara::GameObject Mara::GameObjects::GetObject(int i) {

	Mara::GameObject *go = new Mara::GameObject();
	go = &gameObjects[i];
	return *go;
	delete go;
}
