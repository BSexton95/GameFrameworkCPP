#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
}

void Actor::update(float deltaTime)
{
}

void Actor::draw()
{
}

void Actor::end()
{
    m_started = false;
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}

Component* Actor::addComponent(Component* component)
{
    //Create a new array with a size one greater than our old array
    Component** appendedArray = new Component * [m_componentCount + 1];

    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedArray[i] = m_component[i];
    }

    //Set the last value in the new array to be the component we want to add
    appendedArray[m_componentCount] = component;
    //Set old array to hold the values of the new array
    m_component = appendedArray;
    m_componentCount++;
}

bool Actor::removeComponent(Component* component)
{
    //Check to see if the actor was null
    if (!component)
    {
        return false;
    }

    bool actorRemoved = false;

    //Create a new array with a size one less than our old array
    Component** newArray = new Component* [m_componentCount - 1];

    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_component[i])
        {
            newArray[j] = m_component[i];
            j++;
        }
        else
        {
            actorRemoved = true;
        }
    }
    //Set the old array to the new array
    if (actorRemoved)
    {
        m_component = newArray;
        m_componentCount--;
    }
    //Return whether or not the removal was successful
    return actorRemoved;
}

bool Actor::removeComponent(const char* componentName)
{
    //Check to see if the index is outside the bounds of our array
    if (componentName != m_name)
    {
        return false;
    }

    bool actorRemoved = false;

    //Create a new array with a size one less than our old array 
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        //If the current index is not the index that needs to be removed,
        //add the value into the old array and increment j
        if (componentName != m_component[i]->getName())
        {
            newArray[j] = m_component[i];
            j++;
        }
        else
        {
            delete m_component[i];
            actorRemoved = true;
        }
    }

    //Set the old array to be the tempArray
    m_component = newArray;
    m_componentCount--;
    return actorRemoved;
}

Component* Actor::getComponent(const char* componentName)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (componentName != m_component[i]->getName())
            return nullptr;
    }

}