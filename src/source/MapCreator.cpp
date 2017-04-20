#include "..\headers\MapCreator.h"

sf::RenderWindow MapCreator::window;
sf::ContextSettings MapCreator::settings;
int MapCreator::currentlyPlacingTexture;

void MapCreator::run()
{
	TexturesPanelSegment segment({ 0,620 });
	Button *buttons[16];
	for (int i = 0; i < 16; i++)
		buttons[i] = new Button({ 8.f + i*(4 * 16 + 16), 636 }, { 16.f * 4, 16 * 4 });
	Surface surface({ 0,0 });

	while (window.isOpen()) {
		input();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			for (int i = 0; i < 16; i++)
				if (buttons[i]->isClicked(mouse))
					currentlyPlacingTexture = i + segment.getStartValue();
		}

		segment.update(0);
		window.clear(sf::Color::Red);
		window.draw(segment);
		window.draw(surface);
		
		window.display();
	}
	for (int i = 0; i < 16; i++)
		delete buttons[i];
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
	currentlyPlacingTexture = 0;
	window.create(sf::VideoMode(1280, 720), "Map Creator", sf::Style::Close, settings);
	TextureManager::setTexture(name);
	TextureManager::splitTexture(sf::IntRect(0,0,TextureManager::getTextureSize().x, TextureManager::getTextureSize().y), sf::Vector2u(16,16));
	run();
}
