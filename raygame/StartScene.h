#pragma once
#include "Scene.h"
class StartScene :
	public Scene
{
public:
	void start() override;
	void draw() override;
	void update(float deltaTime) override;
};

