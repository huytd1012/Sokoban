#include"music.h"
void Playsound()
{
    if (Mix_OpenAudioDevice(22050, MIX_DEFAULT_FORMAT, 2, 2048,"Speakers (Realtek(R) Audio)",0) == -1)
    {
        printf("%s", Mix_GetError());
        std::cout << '\n';
        return;
    }
    Mix_Chunk* chunk;
    chunk = Mix_LoadWAV("walk.wav");
    if( chunk == NULL )
    {
        printf("%s", Mix_GetError());
        std::cout << '\n';
    }
    Mix_PlayChannel(-1, chunk, 0);
    Mix_CloseAudio();
}
