#pragma once
#include "SDL.h"
#include "SDL_image.h"

namespace Mara {

	struct TextComp {
		
		int ID = 1;
		SDL_Rect d;
		SDL_Rect s;
		SDL_Surface* surf;
	};
};
