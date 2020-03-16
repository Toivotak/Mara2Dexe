#pragma once
#include "Component.h"
#include <memory>
#include <vector>

namespace Mara {

	class Entity {

	private:
		bool alive;
		std::vector<Component> components;

	public:
		Entity();

		void PushComponent(Component component);
		Component GetComponent(int i);
		std::vector<Component> GetComponentRay();
		int ComponentRaySize();

		void Update();
		void Init();

		bool IsAlive() const;
		void Destroy();

		~Entity();
	};
}
