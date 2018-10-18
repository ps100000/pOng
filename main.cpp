#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "render.h"
#include "pic.h"
#include "vec2d.h"
#include "input.h"

#include "ball.h"
#include "player.h"


bool quit = false;
unsigned char delay;


int main(int argc, char* args[]){
	pic background;
	background.load("./Field.png");
	background.set_visible(true);
	input_controller.add_event(&quit, SDLK_ESCAPE);
	input_controller.clear();
	srand(time(NULL));
	srand(rand());
	
	ball ball1;
	while(!quit){
		input_controller.update();
		players[0].update();
		players[1].update();
		if(!delay){
			if(ball1.update()){
				delay = 50;
				ball1.update();
				players[0].reset_rot();
				players[1].reset_rot();
			}
		}else{
			delay--;
		}
		main_renderer.show();
		SDL_Delay(20);
	}
	SDL_Delay(2000);
}
