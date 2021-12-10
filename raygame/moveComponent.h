#pragma once
#include "Component.h"
#include <Vector2.h>

class moveComponent :
	public Component
{
public:
	moveComponent();
	void setVelocity(Vector2 velocity);
	void start();
	void update(float deltaTime);
	void draw();
	void end();

private:
	float m_speed;
	MathLibrary::Vector2(m_velocity);
};

