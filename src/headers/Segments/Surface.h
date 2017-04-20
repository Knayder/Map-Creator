#ifndef SURFACE_H
#define SURFACE_H

#include "../Segment.h"


class Surface : public Segment {
	void add();
public:
	Surface(const sf::Vector2f &position);
	virtual void update(const float &deltaTime) override;

};

#endif SURFACE_H