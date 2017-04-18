#include "..\headers\MapCreator.h"

sf::RenderWindow MapCreator::window;
sf::ContextSettings MapCreator::settings;

void MapCreator::run()
{
	while (window.isOpen()) {
		input();
		window.clear(sf::Color::Red);

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

	run();
}
