#pragma once
#include <functional>

namespace Mara {

	class Component {

	protected: 
		int componentID = 0;

	public:
		int GetComponentID();
		void Init();
		void Update();
		
		~Component(); 
	};
}
