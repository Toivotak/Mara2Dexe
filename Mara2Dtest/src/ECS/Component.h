#pragma once
#include <functional>

namespace Mara {
	
	inline std::size_t GetComponentID() noexcept {

		static size_t componentID;
		componentID++;
		return componentID;
	}

	class Component {

	private: 
		static int componentID;

	public:
		int GetComponentID();
		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual ~Component();

	};
}
