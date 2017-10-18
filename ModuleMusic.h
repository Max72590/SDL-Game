#pragma once
#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_mixer.h"

typedef unsigned __int8 Uint8;


class ModuleMusic :
	public Module
{
public:
	ModuleMusic();
	~ModuleMusic();
	bool Init();
	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void playSoundFX();

public:

	Mix_Music* music = nullptr;
	Mix_Chunk* soundfx = nullptr;

};

