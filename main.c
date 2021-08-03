//--------------------------------------
// Program Name: Star Trek Multplayer
// Author: Anthony Cagliano
// License:
// Description:
//--------------------------------------

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <intce.h>

/* Standard headers - it's recommended to leave them included */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Other available headers */
// stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h, debug.h
#include <fileioc.h>
#include <graphx.h>
#include <compression.h>
#include <keypadc.h>

// Game Data Types (Structure Definitions)

#include "classes/ships.h"
#include "classes/coords.h"
#include "classes/tech.h"
#include "statscreens.h"
#include "gfx/trekgui.h"
/* Put your function prototypes here */
void DrawFrame(unsigned char screen);

ship_t Ship = {0};

void main(void) {
    unsigned char screen = 0;
    bool loopgame = true;
    unsigned int i;
    gfx_sprite_t* gfx_sprites = malloc(trekgui_uncompressed_size);
    gfx_Begin();
    srandom(rtc_Time());
    if(!trekgui_init(gfx_sprites)) return;
    int_Disable();
    gfx_SetDefaultPalette(gfx_8bpp);
    gfx_SetDrawBuffer();
    gfx_SetTextTransparentColor(1);
    gfx_SetTextBGColor(1);
    for(i = 0; i < SYS_MAX; i++){
        Ship.system[i].techclass = MC_SYSTEM;
        Ship.system[i].online = true;
        Ship.system[i].techtype = i;
        module_SetHealthMax(&Ship.system[i].health);
        module_SetPowerMax(&Ship.system[i].power);
    }
    for(i = 0; i < SHIELD_MAX; i++){
        Ship.shield[i].techclass = MC_TACTICAL;
        Ship.shield[i].online = true;
        Ship.shield[i].techtype = SHIELD;
        module_SetHealthMax(&Ship.shield[i].health);
        module_SetPowerMax(&Ship.shield[i].power);
        Ship.shield[i].data.shields.resistance = 10;
    }
    do {
        unsigned char key = os_GetCSC();
        DrawFrame(screen);
        if(key == sk_Clear) loopgame = false;
        if(key == sk_Yequ) screen = (screen == 1) ? 0 : 1;
        if(key == sk_Window) screen = (screen == 2) ? 0 : 2;
        if(key == sk_Zoom) screen = (screen == 3) ? 0 : 3;
        if(key == sk_Trace) screen = (screen == 4) ? 0 : 4;
        if(key == sk_Graph) screen = (screen == 5) ? 0 : 5;
        if(key == sk_Square){
            char i;
            char modnum = randInt(0, SYS_MAX - 1);
            char randnum = randInt(5, 10);
            for(i = 0; i < SHIELD_MAX; i++){
                module_t *shield = &Ship.shield[i];
                if(shield->online){
                    int health = health_GetHealthPercent(&shield->health);
                    int drv = shield->data.shields.resistance;
                    drv = health * drv / 100;
                    health_DamageModule(&shield->health, -(randnum));
                    randnum -= drv;
                }
            }
            health_DamageModule(&Ship.system[modnum].health, -(randnum));
        }
        if(key == sk_Down) if(Ship.sys_selected < (SYS_MAX - 1)) Ship.sys_selected++;
        if(key == sk_Up) if(Ship.sys_selected > 0) Ship.sys_selected--;
    } while(loopgame == true);
    free(gfx_sprites);
    gfx_End();
    int_Enable();
    pgrm_CleanUp();
    return;
}

void DrawFrame(unsigned char screen){
    Screen_Background(screen);
    gfx_SetTextFGColor(255);
    switch(screen){
        case 0:
            // GUI
            break;
        case 1:
            Screen_UIShieldStats(&Ship.shield[0], &Ship.weapon[0]);
            break;
        case 2:
            
            break;
        case 3:
            Screen_UISystemStats(&Ship.system[0], SYS_MAX, Ship.sys_selected);
            break;
        case 4:
            //Screen_UIRepairSys(&Ship.system[0], SYS_MAX + TACT_MAX);
            break;
    }
    gfx_BlitBuffer();
    gfx_SetTextFGColor(0);
    return;
}
/* Put other functions here */
/* Draw text on the homescreen at the given X/Y location */
