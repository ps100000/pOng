#include "player.h"

unsigned long player::id_counter = 0;

void player::update(){
	if(!init){
		init = true;
		texture.load("./Player.png");
		texture.set_translation_point(vec2d(200, 200));
		texture.set_rotation_point(vec2d(200, 200));
		texture.set_visible(true);
		texture.set_layer(3);
		switch(id){
			case 0:
				rot = 90;
				input_controller.add_event(&in_up, SDLK_UP);
				input_controller.add_event(&in_down, SDLK_DOWN);
			break;
			case 1:
				rot = 270;
				input_controller.add_event(&in_down, SDLK_s);
				input_controller.add_event(&in_up, SDLK_w);
			break;
			default:
				std::cout << "err" << std::endl;
		}
	}
	switch(id){
		case 0:
			if(in_up && (rot >= 0 + 26.5651)){
				rot -= 3.5;
			}
			if(in_down && (rot <= 180 - 26.5651)){
				rot += 3.5;
			}
		break;
		case 1:
			if(in_down && (rot >= 180 + 26.5651)){
				rot -= 3.5;
			}
			if(in_up && (rot <= 360 - 26.5651)){
				rot += 3.5;
			}
		break;
		default:
			std::cout << "err" << std::endl;
	}
	
	texture.set_rotation(rot);
};

void player::add_point(){
	points++;
	std::cout << "Player" << id << " has " << points << " Points!" << std::endl;
};

void player::reset_rot(){
	switch(id){
		case 0:
			rot = 90;
		break;
		case 1:
			rot = 270;
		break;
		default:
			std::cout << "err" << std::endl;
	}
};

float player::get_rot(){
	return rot;
};

player players[2];