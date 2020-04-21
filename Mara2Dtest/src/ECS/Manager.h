#pragma once
#include "Entity.h"

namespace Mara {

	class Manager {

	private:
		std::vector<Entity> entities;

	public:
		Manager();

		void PushEntity(Entity &entity);
		Entity GetEntity(int i);
		std::vector<Entity> GetEntityRay();
		int EntityRaySize();

		void Update();
		void Init();

		~Manager();
	};
}
