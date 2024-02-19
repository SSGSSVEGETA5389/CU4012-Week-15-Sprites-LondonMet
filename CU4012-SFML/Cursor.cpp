#include "Cursor.h"

Cursor::Cursor()
{
}

Cursor::~Cursor()
{
}

void Cursor::update(float dt)
{


	float mouseX = input->getMouseX();
	float mouseY = input->getMouseY();

	setPosition(sf::Vector2f(mouseX, mouseY)); 

	
}
