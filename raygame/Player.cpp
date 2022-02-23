#include "Player.h"
#include "InputComponent.h"
#include "moveComponent.h"
#include "SpriteComponent.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<moveComponent*>(addComponent(new moveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/player.png")));
	
	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * 100);

	//Test
}
