#pragma once
#include "SDL.h"
#include "SDL_image.h"

namespace Mara {

	class TextureManager {

	public:
		SDL_Surface* LoadSurface(const char* fileName);
	};
};
