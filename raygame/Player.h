#pragma once
#include "Actor.h"
class InputComponent;
class moveComponent;
class SpriteComponent;

class Player :
	public Actor
{
public:
	Player(float x, float y, const char* name) : Actor::Actor(x, y, name) {}

	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
	moveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

