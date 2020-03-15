#pragma once
#include <SDL.h>

namespace Mara {

	class InputManager {

	private:
		static InputManager* instance;
		const Uint8* keyboardStates;

	public:
		static InputManager* Instance();
		static void Release();
		bool KeyDown(SDL_Scancode scanCode);
		void Update();
	};
}
