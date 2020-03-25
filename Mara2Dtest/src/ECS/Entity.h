#pragma once
#include "Component.h"
#include <memory>
#include <vector>
#include <boost/any.hpp>

namespace Mara {

	class Entity {

	private:
		bool alive;
		std::vector<boost::any> components;

	public:
		Entity();

		void PushComponent(boost::any component);
		boost::any GetComponent(int i);
		std::vector<boost::any> GetComponentRay() const;
		int ComponentRaySize() const;

		void Update();
		void Init();

		bool IsAlive() const;
		void Destroy();

		~Entity();
	};
}
