#include "Application.h"
#include "Globals.h"
#include "ModuleMusic.h"
#include <string>




ModuleMusic::ModuleMusic()
{
}


ModuleMusic::~ModuleMusic()
{
}

bool ModuleMusic::Init() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	music = Mix_LoadMUS("..\\Game\\S3TheLoop.wav");
	if (music == nullptr) { 
		LOG("Failed to load music");
		return false;
	}
	soundfx = Mix_LoadWAV("..\\Game\\pacman_eatfruit.wav");
	if (soundfx == nullptr) {
		LOG("Failed to load sound effect");
		return false;
	}
	return true;
}

bool ModuleMusic::Start() {
	if (Mix_PlayingMusic() == 0)
	{
		if (Mix_PlayMusic(music, -1) == -1)
		{
			LOG("Error failed to play the music.");
			return false;
		}
	}
	return true;
}

update_status ModuleMusic::PreUpdate() {
	return UPDATE_CONTINUE;
}

update_status ModuleMusic::Update() {
	return UPDATE_CONTINUE;

}

update_status ModuleMusic::PostUpdate() {
	return UPDATE_CONTINUE;

}


bool ModuleMusic::CleanUp() {
	Mix_FreeMusic(music);
	Mix_FreeChunk(soundfx);
	Mix_CloseAudio();
	return true;
}

void ModuleMusic::playSoundFX() {
	if (Mix_PlayChannel(-1, soundfx, 0) == -1) {
		LOG("Error failed to play the sound.");
	}
}

