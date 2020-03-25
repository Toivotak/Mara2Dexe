#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../Component.h"

namespace Mara {

	class TextureComponent{

	private:
		SDL_Surface* surface;
		SDL_Rect sourceRect;
		SDL_Rect destinationRect;
		int componentID;
	public:
		TextureComponent();

		SDL_Rect GetSourceRect();
		SDL_Rect GetDestinationRect();
		SDL_Surface* GetSurface();

		void SetSourceRect(int x, int y, int height, int width);
		void SetDestinationRect(int x, int y, int height, int width);
		void SetDestinationRect(SDL_Rect dRect);
		void SetSurface(const char* fileName);

		void Init();
		void Update();

		~TextureComponent();
	};
}
