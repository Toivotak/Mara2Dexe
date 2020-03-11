#pragma once
#include "Entity.h"

namespace Mara {

	class Manager {

	private:
		Entity* entity;
		std::vector<std::unique_ptr<Entity>> entities;

	};
}
