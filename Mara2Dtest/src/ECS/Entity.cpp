#include "Entity.h"
#include "../Window.h"

Mara::Entity::Entity()
	: alive(true), components(NULL) {
}

void Mara::Entity::PushComponent(boost::any component) {

	components.push_back(component);
}

boost::any Mara::Entity::GetComponent(int i) {

	return components.at(i);
}

std::vector<boost::any> Mara::Entity::GetComponentRay() const {

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
