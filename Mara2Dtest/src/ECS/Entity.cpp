#include "Entity.h"
#include "../Window.h"

bool Mara::Entity::IsAlive() const {
	return alive;
}

void Mara::Entity::Destroy() {
	alive = false;
}
