#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable {
	virtual void draw(sf::RenderTarget &target, sf::RenderStates status) const override = 0;
public:
	Entity(const sf::Vector2f &position) {
		sf::Transformable::setPosition(position);
	}
	virtual void update(const float &deltaTime) = 0;
};


#endif ENTITY_H