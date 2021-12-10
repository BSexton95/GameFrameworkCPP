#include "InputComponent.h"
#include "raylib.h"

void InputComponent::update(float deltaTime)
{
	xDirection = -(int)(IsKeyDown(KEY_A))
				 +(int)(IsKeyDown(KEY_D));
	yDirection = -(int)(IsKeyDown(KEY_W))
				 + (int)(IsKeyDown(KEY_S));

	moveDirection = MathLibrary::Vector2(xDirection, yDirection);
}
