#pragma once
#include "Component.h"

class SpriteComponent :
	public Component
{
public:
	SpriteComponent(const char* path);
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	void draw(MathLibrary::Matrix3(transform));

private:
	Texture2D m_texture;
	int m_width;
	int m_height;
	float m_rotation;
};

