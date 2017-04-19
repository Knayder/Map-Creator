#ifndef SEGMENT_H
#define SEGMENT_H

#include "Entity.h"
#include <vector>

class Segment : public Entity {
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
		states.transform *= getTransform();
		for (auto obj : toDraw)
			target.draw(*obj, states);
	}
	std::vector<sf::Drawable *> toDraw;
public:
	virtual ~Segment() {
		for (auto obj : toDraw)
			delete obj;
	}
	Segment(const sf::Vector2f &position) :
		Entity(position)
	{}
	virtual void update(const float &deltaTime) override {}
	int getToDrawSize() {
		return toDraw.size();
	}
	sf::Drawable * addToDraw(sf::Drawable *object, const sf::Vector2f &position) {
		if (object != nullptr) {
			if (sf::Transformable *transObj = dynamic_cast<sf::Transformable*>(object)) 
				transObj->setPosition(position);

			toDraw.push_back(object);
		}
		return object;
	}
	sf::Drawable * addToDraw(sf::Drawable *object) {
		if (object != nullptr) 
			toDraw.push_back(object);

		return object;
	}
	void clearToDraw() {
		for (auto obj : toDraw)
			delete obj;
		toDraw.clear();
	}
};

#endif SEGMENT_H