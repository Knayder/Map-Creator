#ifndef BUTTON_H
#define BUTTON_H

#include "Segment.h"

class Button : public Segment {
	sf::Vector2f size;
public:
	Button(const sf::Vector2f &position, const sf::Vector2f &size) :
		Segment(position), size(size)
	{}
	virtual bool isClicked(const sf::Vector2i &clickPosition) {
		return sf::IntRect(getPosition().x, getPosition().y, size.x, size.y).contains(clickPosition);
	}
};

#endif BUTTON_H