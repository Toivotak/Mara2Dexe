#pragma once


namespace Mara {

	constexpr int MAXCOMPONENTTYPES = 8;

	static size_t getComponentID()
	{
		static size_t newID{ 0u };
		return newID++;
	}

	class Component
	{
	private:
		const size_t m_id;

	public:
		Component() : m_id{ getComponentID() } {}

		size_t getID() const { return m_id; }

		virtual ~Component() {}
	};
}
