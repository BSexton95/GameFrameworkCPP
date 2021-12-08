#include "Component.h"

Component::Component(Actor* owner, const char* componentName)
{
	m_owner = owner;
	m_name = componentName;
}

Component::~Component()
{
}

void Component::start()
{
}

void Component::update(float deltaTime)
{
}

void Component::draw()
{
}

void Component::end()
{
}

void Component::onCollision(Actor* actor)
{
}
