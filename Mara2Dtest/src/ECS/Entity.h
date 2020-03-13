#pragma once
#include "Component.h"
#include <memory>
#include <vector>

namespace Mara {

	class Entity {

	private:
		const int ID;
		bool alive;
		std::vector<std::unique_ptr<Component>> components;

	public:
		

		void Update();
		void Init();

		bool IsAlive() const;
		void Destroy();

		~Entity();
	};
}
