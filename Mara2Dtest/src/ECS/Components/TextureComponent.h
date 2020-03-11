#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../Component.h"

namespace Mara {

	struct TextureComponent : public Component {

		SDL_Surface* surface;
		SDL_Rect sourceRect;
		SDL_Rect destinationRect;

		void Init() override;
		void Update() override;

		~TextureComponent();
	};
}
