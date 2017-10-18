#pragma once
#include "Module.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "Globals.h"

typedef unsigned __int8 Uint8;

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class ModuleScene :
	public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void PaintScene();


	

private:
	
	const char* filepath = "..\\Game\\sprites.png";
	ModuleRender* renderer;
	ModuleTextures* textures;
};