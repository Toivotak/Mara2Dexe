#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <vector>

#include "Component.h"
#include "Entity.h"

namespace Mara {

	struct ComponentTypeInfo
	{
		size_t m_typeID{};
		const char* m_typeName{};

		ComponentTypeInfo() : m_typeID{}, m_typeName{} {}
		ComponentTypeInfo(size_t id, const char* name) : m_typeID{ id }, m_typeName{ name } {}
	};

	using componentVector = std::vector<std::unique_ptr<Component>>;

	class Manager
	{
	private:
		std::array<std::unique_ptr<Entity>, MAXENTITIES> m_entities;
		std::array<componentVector, MAXCOMPONENTTYPES> m_components;
		std::array<ComponentTypeInfo, MAXCOMPONENTTYPES> m_types;

	public:
		Manager() : m_entities{}, m_components{}, m_types{} {}

		void createEntity(const std::string& name = "")
		{
			size_t entityID = getEntityID();
			m_entities[entityID] = (std::make_unique<Entity>(entityID, name));
		}

		const Entity& getEntity(size_t entityID) const
		{
			return *m_entities[entityID].get();
		}

		template<typename T, typename... TArgs>
		bool createComponent(TArgs&&... mArgs)
		{
			ComponentTypeInfo typeInfo{ getTypeInfo<T>() };
			size_t typeID{ typeInfo.m_typeID };

			T* c(new T(std::forward<TArgs>(mArgs)...));
			m_components[typeID].emplace_back(std::make_unique<T>(*c));
			return true;
		}

		template<typename T, typename... TArgs>
		bool createComponentToEntity(size_t EntityId, TArgs&&... mArgs)
		{
			ComponentTypeInfo typeInfo{ getTypeInfo<T>() };
			size_t typeID{ typeInfo.m_typeID };
			if (m_entities.at(EntityId).get()->hasComponentType(typeID)) {
				return false;
			}
			T* c(new T(std::forward<TArgs>(mArgs)...));
			m_entities[EntityId].get()->addComponent(c, typeID);
			m_components[typeID].emplace_back(std::make_unique<T>(*c));
			return true;
		}

		template<class T>
		const T& getComponent(size_t id) const
		{
			int location{ -1 };
			ComponentTypeInfo typeInfo{ getType<T>() };
			size_t typeID{ typeInfo.m_typeID };
			for (size_t i = 0; i < m_components[typeID].size(); i++)
			{
				if (m_components[typeID][i].get()->getID() == id)
				{
					location = i;
					break;
				}
			}
			if (location < 0)
			{
				throw location;
			}
			return *static_cast<T*>(m_components[typeID][location].get());
		}

		const std::array<ComponentTypeInfo, MAXCOMPONENTTYPES> const& getTypes() const
		{
			return m_types;
		}

	private:
		std::size_t getEntityID() const
		{
			static std::size_t newID{ 0u };
			return newID++;
		}

		std::size_t getTypeNewID() const
		{
			static std::size_t newID{ 0u };
			return newID++;
		}

		template<typename T>
		ComponentTypeInfo getTypeInfo()
		{
			for (size_t i = 0; i < MAXCOMPONENTTYPES; i++)
			{
				if ((m_types[i].m_typeName == typeid(T).name()))
				{
					return m_types[i];
				}
			}
			size_t typeID{ getTypeNewID() };
			if (typeID > (MAXCOMPONENTTYPES - 1))
			{
				std::cerr << "Too many component types!\n";
				throw typeID;
			}
			m_types[typeID] = { typeID, typeid(T).name() };
			return m_types[typeID];
		}

		template<typename T>
		ComponentTypeInfo const& getType() const
		{
			for (size_t i = 0; i < MAXCOMPONENTTYPES; i++)
			{
				if ((m_types[i].m_typeName == typeid(T).name()))
				{
					return m_types[i];
				}
			}
		}
	};

}
