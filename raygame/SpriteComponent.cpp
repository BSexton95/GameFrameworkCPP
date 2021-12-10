#include "SpriteComponent.h"
#include <Matrix3.h>
#include "Transform2D.h"
#include "raylib.h"
#include <math.h>

SpriteComponent::SpriteComponent(const char* path)
{
	m_texture = LoadTexture(path);
}

void SpriteComponent::draw(MathLibrary::Matrix3(transform))
{
	//Finds the scale of the sprite
	m_width = new MathLibrary::Vector2(transform.m00, transform.m10)->getMagnitude();
	m_height = new MathLibrary::Vector2(transform.m01, transform.m11)->getMagnitude();

	//Sets the sprites center to the transform origin
	MathLibrary::Vector2(position) = MathLibrary::Vector2(transform.m02, transform.m12);
	MathLibrary::Vector2(forward) = MathLibrary::Vector2(transform.m00, transform.m10);
	MathLibrary::Vector2(up) = MathLibrary::Vector2(transform.m01, transform.m11);
	MathLibrary::Vector2(position) = MathLibrary::Vector2(forward).normalize() - position * m_width / 2;
	MathLibrary::Vector2(position) = MathLibrary::Vector2(up).normalize() - position * m_height / 2;

	//Find the transform rotation in radians
	m_rotation = atan2(transform.m10, transform.m00);

	//Draw the sprite
	DrawTextureEx(m_texture, position, m_rotation * 180 / PI, 1, WHITE);
}
