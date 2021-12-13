#include "moveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

moveComponent::moveComponent()
	:Component::Component()
{
	
}

void moveComponent::setVelocity(Vector2 velocity)
{
	velocity = m_velocity;
}

void moveComponent::update(float deltaTime)
{
	getOwner()->getTransform()->getLocalPosition() = m_velocity + getOwner()->getTransform()->getLocalPosition();

}
