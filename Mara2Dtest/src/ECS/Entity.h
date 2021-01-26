#pragma once

#include <array>
#include <bitset>
#include <string>
#include <string_view>

#include "Component.h"
#include "Manager.h"

namespace Mara {

	constexpr int MAXENTITIES = 5000;

	class Entity
	{
	private:
		const size_t m_id;
		const std::string m_name;
		std::array<size_t, MAXCOMPONENTTYPES> m_componentIDs; //??
		std::array<Component*, MAXCOMPONENTTYPES> m_componentPointers; // ????
		std::bitset<MAXCOMPONENTTYPES> m_componentTypes;
		bool m_active; //??

	public:
		Entity(size_t id, std::string name = "") : m_id{ id }, m_name{ name }, m_componentIDs{},
			m_componentTypes{}, m_active{ true } {}

		size_t getId() const { return m_id; }
		std::string_view getName() const { return m_name; }
		//std::array<size_t, MAXCOMPONENTTYPES> const& getComponentIDs() const { return m_componentIDs; } //?????
		std::bitset<MAXCOMPONENTTYPES> const& getComponentTypes() const { return m_componentTypes; }
		bool isActive() const { return m_active; }

		void activate() { m_active = true; }
		void disable() { m_active = false; }

		bool hasComponentType(size_t compType) { return m_componentTypes[compType]; }
		void addComponent(/*size_t compID,*/ Component* componentPointer, size_t compType)
		{
			//m_componentIDs[compType] = compID;
			m_componentPointers[compType] = componentPointer;
			m_componentTypes[compType] = 1;
		}
		Component* getComponent(size_t compType) const { return m_componentPointers[compType]; }
		~Entity() {}
	};
}
