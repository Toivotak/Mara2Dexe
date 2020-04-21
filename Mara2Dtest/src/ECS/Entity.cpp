#include "Entity.h"
#include "../Window.h"

Mara::Entity::Entity()
	: alive(true), components(NULL) {
}

Mara::Entity::Entity(const Entity& e) {
	alive = e.alive;
	components = e.components;
}

void Mara::Entity::PushComponent(std::any component) {

	components.push_back(component);
}

std::any Mara::Entity::GetComponent(int i) {

	return components.at(i);
}

std::vector<std::any> Mara::Entity::GetComponentRay() const {

	return components;
}

int Mara::Entity::ComponentRaySize() const {

	return components.size();
}

void Mara::Entity::Update() {
}

void Mara::Entity::Init() {
}

bool Mara::Entity::IsAlive() const {

	return alive;
}

void Mara::Entity::Destroy() {

	alive = false;
}

Mara::Entity::~Entity()
{
}
