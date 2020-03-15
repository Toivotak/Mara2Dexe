#pragma once
#include "SDL.h"
#include "SDL_image.h"

namespace Mara {

	class GameObject {

	protected:
		SDL_Surface* surface;
		SDL_Rect sourceRect;
		SDL_Rect destinationRect;
		bool playable = false;
		bool moveable = false;
		
	public:
		GameObject();

		SDL_Rect GetSourceRect();
		SDL_Rect GetDestinationRect();
		SDL_Surface* GetSurface();
		bool IsPlayable();
		bool IsMoveable();


		void SetSourceRect(int x, int y, int height, int width);
		void SetDestinationRect(int x, int y, int height, int width);
		void SetDestinationRect(SDL_Rect dRect);
		void SetSurface(const char* filename);
		void SetPlayable(bool player);
		void SetMoveable(bool moving);

		~GameObject();
	};
}
