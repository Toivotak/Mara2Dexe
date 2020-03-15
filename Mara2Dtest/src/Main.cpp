#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "GameInstance.h"
#include "GameObject.h"
#include "GameObjects.h"
#include "GameObjects/PlayerObject.h"

int main(int argc, char* argv[]) {

	Mara::GameInstance gi;
	Mara::GameObject go;
	Mara::GameObject go1;
	Mara::GameObjects gos;
	Mara::GameObjects play;

	Mara::PlayerObject player;

	player.SetSurface("src/assets/Man1.png");
	player.SetDestinationRect(0, 0, 128, 64);
	player.SetSourceRect(0, 0, 128, 64);
	
	play.PushGameObject(player);

	go.SetSurface("src/assets/Ground/Grass1.png");
	go.SetSourceRect(0, 0, 32, 32);
	go.SetDestinationRect(0, 0, 32, 32);
	
	int o = 0;
	for (int i = 0; i < 39; i++) {
		Mara::GameObject object;
		object.SetSurface("src/assets/Ground/Grass1.png");
		object.SetSourceRect(0, 0, 32, 32);
		object.SetDestinationRect(-32 + 32 * i, 0 + 32 * o, 32, 32);
		if (i == 38) {
			i = 0;
			o++;
		}

		gos.PushGameObject(object);
		if (o == 27) {
			break;
		}
	}

	go1.SetSurface("src/assets/Ground/RockyGround.png");
	go1.SetSourceRect(0, 0, 32, 32);
	go1.SetDestinationRect(64, 64, 32, 32);
	go1.SetMoveable(true);
	go1.SetPlayable(true);
	
	gos.PushGameObject(go1);

	gi.SetGameObjects(gos);
	
	gi.Run();

	return 0;
}