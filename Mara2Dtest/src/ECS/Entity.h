#pragma once
#include "Component.h"
#include <memory>
#include <vector>
#include <boost/any.hpp>
#include <any>

namespace Mara {

	class Entity {

	private:
		bool alive;
		std::vector<std::any> components;

	public:
		Entity();
		Entity(const Entity& e);

		void PushComponent(std::any component);
		std::any GetComponent(int i);
		std::vector<std::any> GetComponentRay() const;
		int ComponentRaySize() const;

		void Update();
		void Init();

		bool IsAlive() const;
		void Destroy();

		~Entity();
	};
}
