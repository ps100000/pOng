#include "ball.h"

ball::ball(){
	texture.load("./Ball.png");
	texture.set_translation_point(vec2d(28,4));
	texture.set_rotation_point(vec2d(28,4));
	texture.set_visible(true);
	texture.set_layer(4);
};

bool ball::update(){
	if(!init){
		vel = vec2d(0, 5);
		vel.rotateBy(rand() / 10.0);
		init = true;
		pos = vec2d(200, rand() % 200 + 100);
	}
	pos += vel;
	texture.set_translation(pos);
	texture.set_rotation(vel.getAngleDeg());
	vec2d temp = (pos - vec2d(200,200));
	float angle = atan2(temp.y, temp.x) * 57.2957 + 360 + 90;
	while(angle > 360){
		angle -= 360;
	}
	//std::cout << pos.x << ' ' << pos.y << ' ' << angle << std::endl;
	if(temp.getLength() >= 190){
		if((abs(angle - players[0].get_rot()) < 26.5651)){
			vel.rotateBy(M_PI - 2 * (atan2(vel.y, vel.x) - atan2(temp.y, temp.x)));
			if(vel.getLength() < 3 * 5){
				vel *= 1.15;
			}
			temp.setLength(188);
			pos = temp + vec2d(200,200);
		}else{
			if(pos.x > 200){
				players[1].add_point();
				init = false;
				return true;
			}
		}
		if((abs(angle - players[1].get_rot()) < 26.5651) && (pos.x < 200)){
			vel.rotateBy(M_PI - 2 * (atan2(vel.y, vel.x) - atan2(temp.y, temp.x)));
			if(vel.getLength() < 3 * 5){
				vel *= 1.15;
			}
			temp.setLength(188);
			pos = temp + vec2d(200,200);
		}else{
			if(pos.x < 200){
				players[0].add_point();
				init = false;
				return true;
			}
		}
	}
	return false;
};
