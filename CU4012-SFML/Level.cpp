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

	// Load player sprite
	PlayerTex.loadFromFile("gfx/Goomba.png");

	playerSprite.setTexture(&PlayerTex);
	playerSprite.setSize(sf::Vector2f(100, 100)); 
	playerSprite.setVelocity(sf::Vector2f(100, 0));
	playerSprite.setPosition(300, 300); 
	playerSprite.setInput(input);
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
	

	//Cursor Implementation

	cursorTex.loadFromFile("gfx/icon.png");

	mousePointer.setTexture(&cursorTex);
	mousePointer.setSize(sf::Vector2f(50, 50));
	mousePointer.setInput(input); 
	window->setMouseCursorVisible(false); 

	//Background stuff

	backgroundTex.loadFromFile("gfx/Level1_1.png");

	bg.setTexture(&backgroundTex); 
	bg.setSize(sf::Vector2f(11038,  675));
	bg.setInput(input);
	bg.setWindow(window); 

	
	
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
	//Player move with asigned 'WASD' controls on keyboard
	playerSprite.handleInput(dt);

	bg.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	//Enemy
	Enemy1.update(dt, move);
	Enemy2.update(dt, move1);
	//Mouse
	mousePointer.update(dt);
	// WIndow move left/right input
	window->getDefaultView();
	bg.handleInput(dt); 
	
}

// Render level
void Level::render()
{
	beginDraw();
	//Render background
	window->draw(bg);

	//Render test sprite

	window->draw(testSprite);
	//Render player

	window->draw(playerSprite); 
	//Render Enemy

	window->draw(Enemy1);
	window->draw(Enemy2); 
	//Render cursor

	window->draw(mousePointer);

	endDraw();
}
