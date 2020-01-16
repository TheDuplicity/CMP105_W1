#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;
	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);
	//outter rect
	rect1.setSize(sf::Vector2f(300, 300));
	rect1.setPosition(300 - (rect1.getSize().x/2), 300 - (rect1.getSize().y/2));
	rect1.setFillColor(sf::Color::Red);
	//mid rect
	rect2.setSize(sf::Vector2f(200, 200));
	rect2.setPosition(300 - (rect2.getSize().x/2), 300 - (rect2.getSize().x/2));
	rect2.setFillColor(sf::Color::Green);
	//inner rect
	rect3.setSize(sf::Vector2f(100, 100));
	rect3.setPosition(300 - (rect3.getSize().x/2), 300 - (rect3.getSize().x/2));
	rect3.setFillColor(sf::Color::Blue);

	//bottom right rect
	rectBR.setSize(sf::Vector2f(40, 40));
	rectBR.setFillColor(sf::Color::Red);

	//middle circle
	circle.setPosition((window->getSize().x/2) - 50, (window->getSize().y/2) - 50);
	circle.setRadius(50);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(10);

	//render text
	try
	{ 
		font.loadFromFile("font/arial.ttf");
	}
	catch (int exceptionNum)
	{
		std::cout << "Looks like we couldnt find the file!";
	}

	text.setFont(font);
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(35);
	text.setOrigin(0, 0);
	text.setString("Hola");

}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u windowSize = window->getSize();
	rectBR.setPosition(windowSize.x - rectBR.getSize().x, windowSize.y - rectBR.getSize().y);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rectBR);
	window->draw(rect1);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect);
	window->draw(circle);
	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{

	window->display();
}