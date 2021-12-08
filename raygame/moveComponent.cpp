#include "moveComponent.h"
#include "Transform2D.h"

moveComponent::moveComponent() : Component :: Component()
{
	
}

void moveComponent::update(float deltaTime)
{
	m_velocity = ownerPosition.getNormalized() * m_speed * deltaTime;

	getOwner() += m_velocity;
	
}
