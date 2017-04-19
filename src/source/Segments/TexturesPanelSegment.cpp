#include "..\..\headers\Segments\TexturesPanelSegment.h"

TexturesPanelSegment::TexturesPanelSegment(const sf::Vector2f &position):
	Segment(position),
	startValue(0)
{
	sf::RectangleShape *background = dynamic_cast<sf::RectangleShape*>( addToDraw(new sf::RectangleShape({ 1280,100 })) );
	background->setFillColor(sf::Color(37, 37, 38));
	sf::RectangleShape *bar = dynamic_cast<sf::RectangleShape*>(addToDraw(new sf::RectangleShape({ 30,10 })));
	bar->setFillColor(sf::Color(137, 137, 138));
	bar->setOrigin(15, 5);
	bar->setPosition(40 + 1280 / 100 * (100 * ((float)startValue / (TextureManager::getContainerSize() - 16))), 90);
	for (unsigned int i = startValue; i < TextureManager::getContainerSize() && i<16+startValue; i++) {
		sf::Texture *texture = TextureManager::getTexture(i);
		sf::Sprite *sprite = new sf::Sprite(*texture);
		float scale = 4;
		sprite->setScale(scale, scale);
		int sizeX = texture->getSize().x;
		int sizeY = texture->getSize().y;
		sprite->setPosition(8 + (i-startValue)*(scale*sizeX+16), 8);
		addToDraw(sprite);
	}
}

void TexturesPanelSegment::update(const float & deltaTime)
{
	bool isChanged = false;
	if (lastChange.getElapsedTime().asSeconds() >= 0.1f) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			isChanged = true;
			lastChange.restart();
			--startValue;
			if (startValue < 0) 
				startValue = TextureManager::getContainerSize() - 15;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			isChanged = true;
			lastChange.restart();
			++startValue;
			if (startValue > TextureManager::getContainerSize() - 16) 
				startValue = 0;
		}
		if (isChanged) {
			clearToDraw();
			sf::RectangleShape *background = dynamic_cast<sf::RectangleShape*>(addToDraw(new sf::RectangleShape({ 1280,100 })));
			background->setFillColor(sf::Color(37, 37, 38));
			sf::RectangleShape *bar = dynamic_cast<sf::RectangleShape*>(addToDraw(new sf::RectangleShape({ 30,10 })));
			bar->setFillColor(sf::Color(137, 137, 138));
			bar->setOrigin(15, 5);
			bar->setPosition(40 + 1280/100 *( 100 * ((float)startValue / (TextureManager::getContainerSize() - 16))), 90);
			for (unsigned int i = startValue; i < TextureManager::getContainerSize() && i < 16 + startValue; i++) {
				sf::Texture *texture = TextureManager::getTexture(i);
				sf::Sprite *sprite = new sf::Sprite(*texture);
				float scale = 4;
				sprite->setScale(scale, scale);
				int sizeX = texture->getSize().x;
				int sizeY = texture->getSize().y;
				sprite->setPosition(8 + (i - startValue)*(scale*sizeX + 16), 8);
				addToDraw(sprite);
			}
		}
	}
}

