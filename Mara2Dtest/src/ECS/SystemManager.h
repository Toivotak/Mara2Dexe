#pragma once

#include <array>
#include <bitset>
#include <functional>
#include <typeinfo>
#include <string>
#include <unordered_map>
#include <vector>

#include "Manager.h"

namespace Mara {

	using signature = std::bitset<MAXCOMPONENTTYPES>;

	class SystemManager
	{
	private:
		std::unordered_map<std::string, signature> m_systems;
		std::array<const char*, MAXCOMPONENTTYPES> m_types;

	public:
		SystemManager() : m_systems{}, m_types{} {}

		void setTypes(const std::array<ComponentTypeInfo, MAXCOMPONENTTYPES> const& types)
		{
			for (size_t i = 0; i < MAXCOMPONENTTYPES; i++)
			{
				m_types[i] = types[i].m_typeName;
			}
		}
		template<class... T>
		bool registerSystem(std::string systemName)
		{
			if (m_systems.find(systemName) != m_systems.end()) {
				std::cout << "This system has already been registered\n";
				return false;
			}
			std::vector<const char*> typeNames = { typeid(T).name()... };
			signature systemSignature{};
			for (size_t i = 0; i < typeNames.size(); i++)
			{
				std::cout << i << " " << typeNames.at(i) << '\n';
				for (size_t j = 0; j < MAXCOMPONENTTYPES; j++)
				{
					if (typeNames[i] == m_types[j])
					{
						systemSignature[j] = 1;
					}
				}
			}
			std::cout << systemSignature.to_string() << '\n';
			m_systems.emplace(systemName, systemSignature);
			return true;
		}
		void ValidateEntity(const Entity& entity)
		{

			signature entSignature = entity.getComponentTypes();
			for (auto iter = m_systems.begin(); iter != m_systems.end(); ++iter)
			{
				bool valid{ false };
				for (size_t j = 0; j < MAXCOMPONENTTYPES; j++)
				{
					if (iter->second[j])
					{
						if (iter->second[j] == entSignature[j])
						{
							valid = true;
						}
						else
						{
							valid = false;
							break;
						}
					}
				}
				if (valid)
				{
					std::cout << "Entity " << entity.getId() << " is valid for " << iter->first << '\n';
				}
			}
		}
	};
}

