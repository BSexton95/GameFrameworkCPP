#pragma once
#include "Component.h"

class moveComponent :
	public Component
{
public:
	moveComponent();
	void start();
	void update(float deltaTime);
	void draw();
	void end();

private:
	float m_speed;
	MathLibrary::Vector2(m_velocity);
};

