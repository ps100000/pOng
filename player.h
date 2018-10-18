#include <iostream>

#include "pic.h"
#include "vec2d.h"
#include "input.h"

#ifndef PLAYER_H
#define PLAYER_H

class player{
	private:
		float rot = 0;
		pic texture;
		bool in_up = false;
		bool in_down = false;
		bool init = false;
		static unsigned long id_counter;
		unsigned long id = id_counter++;
		unsigned int points = 0;
	public:
		void update();
		void add_point();
		void reset_rot();
		float get_rot();
};

extern player players[2];
#endif