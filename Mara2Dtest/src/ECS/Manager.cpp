#include "Manager.h"

Mara::Manager::Manager()
	: entities(NULL) {
}

void Mara::Manager::PushEntity(Entity entity) {

	entities.push_back(entity);
}

Mara::Entity Mara::Manager::GetEntity(int i) {

	return entities.at(i);
}

std::vector<Mara::Entity> Mara::Manager::GetEntityRay() {

	return entities;
}

int Mara::Manager::EntityRaySize() {

	return entities.size();
}

void Mara::Manager::Update() {
}

void Mara::Manager::Init() {
}

Mara::Manager::~Manager() {
}
