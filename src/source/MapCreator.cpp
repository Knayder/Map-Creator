#include "..\headers\MapCreator.h"

sf::RenderWindow MapCreator::window;
sf::ContextSettings MapCreator::settings;

void MapCreator::run()
{
	TexturesPanelSegment segment({ 0,0 });
	while (window.isOpen()) {
		input();
		segment.update(0);
		window.clear(sf::Color::Red);
		window.draw(segment);
		window.display();
	}
}

void MapCreator::input()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void MapCreator::start(const std::string &name)
{
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(1280, 720), "Map Creator", sf::Style::Close, settings);
	TextureManager::setTexture(name);
	TextureManager::splitTexture(sf::IntRect(0,0,TextureManager::getTextureSize().x, TextureManager::getTextureSize().y), sf::Vector2u(16,16));
	run();
}
