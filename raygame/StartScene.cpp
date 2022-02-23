#include "StartScene.h"
#include <iostream>
#include "Engine.h"
#include "MainScene.h"


void StartScene::start()
{
	//Displays players options
	std::cout << "Welcome to the battle simulation!" << std::endl;
	std::cout << "1. Sart" << std::endl;
	std::cout << "2. Exit" << std::endl;
}

void StartScene::draw()
{
	
}

void StartScene::update(float delatTime)
{
	char input;

	//Player input
	std::cin >> input;

	if (input == '1')
	{
		Engine::addScene(new MainScene());
	}
	else if (input == '2')
		Engine::CloseApplication();


	//m_currentSceneIndex = addScene(new MainScene());
}

