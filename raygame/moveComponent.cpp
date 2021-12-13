#include "moveComponent.h"
#include "Transform2D.h"
#include "Actor.h"


void moveComponent::update(float deltaTime)
{
	//Add the new velocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	//Set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
