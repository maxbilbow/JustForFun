//
//  SDLLink.c
//  JustForFun
//
//  Created by Max Bilbow on 22/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#include <SDL2/SDL.h>
#include "SDLLink.h"
#define XRES 1000
#define YRES 1000

/*
void start(){
    SDL_Window * window;
    SDL_RendererFlags flags;
    SDL_Renderer * screen = SDL_CreateRenderer(window,-1, flags);
    SDL_Color *color;
    SDL_Rect r={0,0,XRES,YRES};
    
    SDL_SetRenderDrawBlendMode(screen,SDL_BLENDMODE_MOD);
    FillRect(screen,&r,color);
    Uint32 *pixels = (Uint32 *)screen->pixels;
    
    unsigned int x, y;
    
    for(y=0;y<screen->h;y++) {
        
        for(x=0;x<screen->w;x++) {
            
            // Code to edit each pixel here.
            
        }
        
    }
}*/

void SDLLink::Test(void) {
    SDL_Palette * palette = SDL_AllocPalette(1000);
    
    
    printf("palet initialized:\nncolors: %i, refcount: %i, version: %u\n", palette->ncolors, palette->refcount, palette->version);
    
    free(palette);
}

int SDLLink::Run(void) {
    
    SDL_Surface *surface;
    SDL_PixelFormat *fmt;
    SDL_Color *color;
    Uint8 index;

    /* Create surface */

    fmt=surface->format;
    
    /* Check the bitdepth of the surface */
    if(fmt->BitsPerPixel!=8){
        fprintf(stderr, "Not an 8-bit surface.\n");
        return(-1);
    }
    
    /* Lock the surface */
    SDL_LockSurface(surface);
    
    /* Get the topleft pixel */
    index=*(Uint8 *)surface->pixels;
    color=&fmt->palette->colors[index];
    
    /* Unlock the surface */
    SDL_UnlockSurface(surface);
    printf("Pixel Color-> Red: %d, Green: %d, Blue: %d. Index: %d\n",
           color->r, color->g, color->b, index);
    
    return 0;
    
}


int SDLLink::Run2(void) {
    
    /* Extracting color components from a 32-bit color value */
    SDL_PixelFormat *fmt;
    SDL_Surface *surface;
    Uint32 temp, pixel;
    Uint8 red, green, blue, alpha;
    
    fmt = surface->format;
    SDL_LockSurface(surface);
    pixel = *((Uint32*)surface->pixels);
    SDL_UnlockSurface(surface);
    
    /* Get Red component */
    temp = pixel & fmt->Rmask;  /* Isolate red component */
    temp = temp >> fmt->Rshift; /* Shift it down to 8-bit */
    temp = temp << fmt->Rloss;  /* Expand to a full 8-bit number */
    red = (Uint8)temp;
    
    /* Get Green component */
    temp = pixel & fmt->Gmask;  /* Isolate green component */
    temp = temp >> fmt->Gshift; /* Shift it down to 8-bit */
    temp = temp << fmt->Gloss;  /* Expand to a full 8-bit number */
    green = (Uint8)temp;
    
    /* Get Blue component */
    temp = pixel & fmt->Bmask;  /* Isolate blue component */
    temp = temp >> fmt->Bshift; /* Shift it down to 8-bit */
    temp = temp << fmt->Bloss;  /* Expand to a full 8-bit number */
    blue = (Uint8)temp;
    
    /* Get Alpha component */
    temp = pixel & fmt->Amask;  /* Isolate alpha component */
    temp = temp >> fmt->Ashift; /* Shift it down to 8-bit */
    temp = temp << fmt->Aloss;  /* Expand to a full 8-bit number */
    alpha = (Uint8)temp;
    
    printf("Pixel Color -> R: %d,  G: %d,  B: %d,  A: %d\n", red, green, blue, alpha);
    
    return 0;
}