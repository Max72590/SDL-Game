#include "Globals.h"
#include "ModuleScene.h"
#include "Application.h"
#include "SDL/include/SDL.h"

using namespace std;


ModuleScene::ModuleScene()
{
}


ModuleScene::~ModuleScene()
{
}


bool ModuleScene::Init() {
	renderer = App->renderer;
	if (renderer == nullptr) {
		LOG("Failed to init render module \n");
	}
	textures = App->textures;
	if (textures == nullptr) {
		LOG("Failed to init texture module \n");
	}
	return true;
}

bool ModuleScene::CleanUp() {
	LOG("Destroying renderer and texture refs");
	if (renderer != nullptr) {
		renderer = nullptr;
	}	
	if (textures != nullptr) {
		textures = nullptr;
	}	
	return true;
}

void ModuleScene::PaintScene() {
	
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 480;
	rect.w = 640;
	renderer->Blit(textures->sceneTexture,0,0,&rect);
	//SDL_RenderCopy(renderer->renderer,textures->sceneTexture,NULL,&rect);
}

update_status ModuleScene::PreUpdate() {
	return UPDATE_CONTINUE;
}

update_status ModuleScene::Update() {
	PaintScene();
	return UPDATE_CONTINUE;
}

update_status ModuleScene::PostUpdate() {
	return UPDATE_CONTINUE;
}