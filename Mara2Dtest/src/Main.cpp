#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "GameInstance.h"
#include "GameObject.h"
#include "GameObjects.h"

int main(int argc, char* argv[]) {

	Mara::GameInstance gi;
	Mara::GameObject go;
	Mara::GameObject go1;
	Mara::GameObjects gos;

	std::vector<int> test;
	
	
	for (int i = 0; i < 10; i++) {
		test.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << test[i];
	}

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
	

	go1.SetSurface("src/assets/Man1.png");
	go1.SetSourceRect(0, 0, 128, 64);
	go1.SetDestinationRect(64, 64, 128, 64);
	go1.SetMoveable(true);
	go1.SetPlayable(true);
	
	gos.PushGameObject(go1);

	gi.SetGameObjects(gos);
	gi.Run();

	return 0;
}