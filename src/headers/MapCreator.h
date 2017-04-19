#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Segments/TexturesPanelSegment.h"
#include "Button.h"

class MapCreator {
	static sf::RenderWindow window;
	static sf::ContextSettings settings;

	static void run();
	static void input();

	static int currentlyPlacingTexture;
public:
	MapCreator() = delete;
	MapCreator(const MapCreator &) = delete;
	void operator = (const MapCreator &) = delete;

	static void start(const std::string &name);
};


#endif