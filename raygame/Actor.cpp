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

Component* Actor::addComponent(Component* component)
{
    //If the component is null then return before running any other logic
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //Create a new temporary array that one size larger than the original
    Component** tempArray = new Component * [m_componentCount + 1];

    //Copy values from old array into new array
    for (int i = 0; i < m_componentCount; i++)
    {
        tempArray[i] = m_component[i];
    }

    //Sets the component at the new index to be the component passed in
    tempArray[m_componentCount] = component;
    if (m_componentCount > 1)
        //set old array to hold the values of the new array
        delete[] m_component;
    else if (m_componentCount == 1)
        delete m_component;
    //Set the old array to the tmeporary array
    m_component = tempArray;
    m_componentCount++;

    return component;
}

bool Actor::removeComponent(Component* component)
{
    //Check to see if the component was null
    if (!component)
        return false;

    bool componentRemoved = false;

    //Create a new array with a size one less than our old array
    Component** newArray = new Component * [m_componentCount - 1];

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
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        delete[] m_component;
        //Set the old array to the new array
        m_component = newArray;
        m_componentCount--;

        delete component;
    } 
    else
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}

void Actor::start()
{
    m_started = true;
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->onCollision(other);
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (m_component[i]->getStarted())
            m_component[i]->start();

        m_component[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->draw();
}

void Actor::end()
{
    m_started = false;

    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->end();
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componentCount; i++)
        m_component[i]->onDestroy();

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