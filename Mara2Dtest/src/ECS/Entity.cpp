#include "Entity.h"
#include "src/Window.h"

bool Mara::Entity::IsAlive() const {
	return alive;
}

void Mara::Entity::Destroy() {
	alive = false;
}
