#include "..\headers\TextureManager.h"

TextureManager::~TextureManager(){
	delete texture;
	for (auto txtr : texturesContainer)
		delete txtr;
}


sf::Texture * TextureManager::setTexture(const std::string &name){
	TextureManager &instance = TextureManager::getInstance();

	if(instance.texture == nullptr)
		instance.texture = new sf::Texture();

	if (!instance.texture->loadFromFile(name))
		instance.texture = nullptr;

	return instance.texture;
}

void TextureManager::splitTexture(const sf::IntRect & area, const sf::Vector2u & segment){
	TextureManager &instance = TextureManager::getInstance();

	sf::Image image = instance.texture->copyToImage();

	for (unsigned int y = area.top; y < area.top + area.height; y += segment.y)
		for (unsigned int x = area.left; x < area.left + area.width; x += segment.x) {
			sf::Texture *texture = new sf::Texture;
			texture->loadFromImage(image, sf::IntRect(x, y, segment.x, segment.y));
			instance.texturesContainer.push_back(texture);
		}

}

sf::Vector2u TextureManager::getTextureSize(){
	return TextureManager::getInstance().texture->getSize();
}

unsigned int TextureManager::getContainerSize()
{
	return TextureManager::getInstance().texturesContainer.size();
}

sf::Texture * TextureManager::getTexture(const unsigned int & index){
	TextureManager &instance = TextureManager::getInstance();
	if (index < instance.texturesContainer.size()) 
		return instance.texturesContainer[index];

	else
		return nullptr;
}

void TextureManager::clearContainer()
{
	TextureContainer &container = TextureManager::getInstance().texturesContainer;
	for (auto texture : container)
		delete texture;
	container.clear();
}


TextureManager & TextureManager::getInstance(){
	static TextureManager instance;
	return instance;
}
