#pragma once
#include "Component.h"
class Texture2D;

class SpriteComponent :
	public Component
{
public:
	/// <param name="texture">Sets the sprites image to be this textrue</param>
	/// <param name="name">The name of the component instance</param>
	SpriteComponent(Texture2D* texture);

	/// <param name="path">The path of the textrue to load</param>
	/// <param name="name"The name of the component instance></param>
	SpriteComponent(const char* path);
	 
	~SpriteComponent() override;

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

