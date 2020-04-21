#pragma once


namespace Mara {

	class Component {

	protected: 
		int componentID = 0;

	public:
		int GetComponentID();
		virtual void Init() {}
		virtual void Update() {}
		
		virtual ~Component() {}
	};
}
