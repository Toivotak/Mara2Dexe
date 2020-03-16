#include "Entity.h"
#include "../Window.h"

Mara::Entity::Entity()
	: alive(true), components(NULL) {
}

void Mara::Entity::PushComponent(Component component) {

	component.GetComponentID();
	for (int i = 0; i < components.size(); i++) {
		if (components.at(i).GetComponentID() == component.GetComponentID()) {
			std::cout << "Already has this type of component!\n";
		}
		else {
			components.push_back(component);
		}	
	}
}

Mara::Component Mara::Entity::GetComponent(int i) {

	Component* component = new Component();
	component = &components.at(i);
	return *component;
	delete component;
}

std::vector<Mara::Component> Mara::Entity::GetComponentRay() {

	return components;
}

int Mara::Entity::ComponentRaySize() {

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
