#pragma once
#include "Component.h"
#include <Vector2.h>
#include <raylib.h>

class InputComponent :
	public Component
{
public:
	void update(float deltaTime);
	Vector2 getMoveAxis();

private:
	int xDirection;
	int yDirection;
	MathLibrary::Vector2(moveDirection);
};

