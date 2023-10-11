

//--------------------------------------------------


#include "../hpp/graphics.hpp"
#include "../../lib/logs.hpp"


//--------------------------------------------------


Return_code init_sdl (void) {

    if (SDL_Init (SDL_INIT_VIDEO) < 0){

        LOG_MESSAGE ("SDL could not initialize!\n");
        return LIB_ERR;
    }


    if (!SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "1")) {

        LOG_MESSAGE ("Error: Linear texture filtering not enabled!");
        return LIB_ERR;
    }


    return SUCCESS;
}


Return_code quit_sdl (void) {

    SDL_Quit ();


    return SUCCESS;
}


SDL_Texture* Graphic_Window::load_texture
        (const char* path, bool transparent_flag, My_RGB clr) const {

    SDL_Surface* temp_surface = IMG_Load (path);

    if(!temp_surface) {

        LOG_MESSAGE ("Unable to load image!\n");
        return nullptr;
    }

//--------------------------------------------------

    if (transparent_flag) {

        Uint32 sdl_clr = SDL_MapRGB (temp_surface->format, clr.r, clr.g, clr.b);
        SDL_SetColorKey (temp_surface, SDL_TRUE, sdl_clr);
    }

//--------------------------------------------------

    SDL_Texture* texture = SDL_CreateTextureFromSurface (renderer_, temp_surface);
    SDL_FreeSurface (temp_surface);

    if (!texture) LOG_MESSAGE ("Unable to create texture!");


    return texture;
}

