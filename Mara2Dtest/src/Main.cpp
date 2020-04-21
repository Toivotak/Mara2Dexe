#include <iostream>
#include <boost/any.hpp>
#include "SDL.h"
#include "Window.h"
#include "GameInstance.h"
#include "GameObject.h"
#include "GameObjects.h"
#include "GameObjects/PlayerObject.h"
#include "ECS/Manager.h"
#include "ECS/Components/TextureComponent.h"
#include "ECS/Components/TextComp.h"

struct Teko {

	SDL_Rect d;
	SDL_Rect s;
	SDL_Surface* surf;
};

int main(int argc, char** argv) {

	Mara::GameInstance gi;
	
	Mara::Manager *manager = new Mara::Manager();
	Mara::Entity entity;

	int o = 0;

	for (int i = 0; i < 39; i++) {
		Mara::TextComp* texComp = new Mara::TextComp;
		//texComp->surf = IMG_Load("src/assets/Ground/Grass1.png");
		texComp->s = { 0, 0, 32, 32 };
		texComp->d = { -32 + 32 * i, 0 + 32 * o, 32, 32 };
		if (i == 38) {
			i = 0;
			o++;
		}
		entity.PushComponent(texComp);
		//SDL_FreeSurface(texComp->surf);
		if (o == 27) {
			break;
		}
		std::cout << texComp->d.x << '\n';
		delete texComp;
		
	}
	manager->PushEntity(entity);
	Mara::Entity testany;
	Mara::TextComp t;
	t.d = { 30, 323, 32, 33 };
	t.s = { 60, 623, 62, 63 };
	t.surf = IMG_Load("src/assets/Ground/Grass1.png");
	testany.PushComponent(t);
	

	Mara::Entity test;
	test = (manager->GetEntity(0));
	Mara::TextComp testi00;
	try {
		testi00 = std::any_cast<Mara::TextComp>(test.GetComponent(0));
	}
	catch (const std::bad_any_cast & e) {
		std::cout << e.what() << '\n';
	}
	Mara::Entity test2;
	test2.PushComponent(t);
	try {
		testi00 = std::any_cast<Mara::TextComp>(test2.GetComponent(0));
	}
	catch (const std::bad_any_cast & e) {
		std::cout << e.what() << " 2\n";
	}

	
	std::cout << testi00.d.x;
	gi.SetManager(*manager);
	gi.Run();

	delete manager;
	/*
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
	gos.PushGameObjects(play);
	gos.PushGameObjects(gos);
	gi.SetObjectsRay(gos.GetObjectsRay());
	
	//gi.SetGameObjects(gos);
	*/
	

	//delete texComp;
	return 0;
}