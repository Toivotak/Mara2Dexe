#include "Entity.h"
#include "../Window.h"



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
