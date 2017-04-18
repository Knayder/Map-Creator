#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

class TextureManager final {
public:
	typedef std::vector<sf::Texture *> TextureContainer;

	TextureManager(const TextureManager &) = delete;
	void operator=(const TextureManager &) = delete;
	~TextureManager();

	static sf::Texture * setTexture(const std::string &name);
	static void splitTexture(const sf::IntRect &area, const sf::Vector2u &segment);
	static sf::Vector2u getTextureSize();
	static sf::Texture * getTexture(const unsigned int &index);
	static void clearContainer();

private:
	TextureManager(){}
	static TextureManager &getInstance();

	sf::Texture *texture;
	TextureContainer texturesContainer;

};

#endif TEXTUREMANAGER_H