#ifndef BALL_H
#define BALL_H

#include <cmath>

#include "pic.h"
#include "vec2d.h"

#include "player.h"

class ball{
	private:
		bool init = false;
		vec2d pos;
		vec2d vel = vec2d(0, 0);
		pic texture;
	public:
		ball();
		bool update();
};

#endif