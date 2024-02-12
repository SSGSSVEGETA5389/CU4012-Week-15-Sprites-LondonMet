#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	PlayerTex.loadFromFile("gfx/Goomba.png");

	playerSprite.setTexture(&PlayerTex);
	playerSprite.setSize(sf::Vector2f(100, 100)); 
	playerSprite.setVelocity(sf::Vector2f(100, 0));
	playerSprite.setPosition(300, 300); 

	//Loading enemy texture

	e1.loadFromFile("gfx/enemy.png");
	e2.loadFromFile("gfx/enemy2.png");

	Enemy1.setTexture(&e1);
	Enemy1.setSize(sf::Vector2f(100, 100));
	Enemy1.setPosition(500, 500);

	Enemy2.setTexture(&e2);

	Enemy2.setSize(sf::Vector2f(100, 100));
	Enemy2.setPosition(700, 500);

	move = sf::Vector2f(100, 0);
	move1 = sf::Vector2f(0, 100);

	Enemy1.setWindow(window);
	Enemy2.setWindow(window);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update(float dt)
{
	Enemy1.update(dt, move);
	Enemy2.update(dt, move1);

	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(testSprite);
	window->draw(playerSprite); 
	window->draw(Enemy1);
	window->draw(Enemy2); 

	endDraw();
}
