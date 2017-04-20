#include "..\..\headers\Segments\Surface.h"

void Surface::add(){

	sf::RectangleShape *background = new sf::RectangleShape({ 1280, 620 });
	background->setFillColor(sf::Color(255,0,255));
	addToDraw(background);
}



Surface::Surface(const sf::Vector2f &position) :
	Segment(position)
{
	add();
}

void Surface::update(const float & deltaTime)
{
}
