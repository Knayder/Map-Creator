#ifndef TEXTURESPANELSEGMENT_H
#define TEXTURESPANELSEGMENT_H

#include "../Segment.h"
#include "../TextureManager.h"


class TexturesPanelSegment : public Segment {
	int startValue;
	sf::Clock lastChange;
	
	void add();
public:
	TexturesPanelSegment(const sf::Vector2f &position);
	virtual void update(const float &deltaTime) override;
	int getStartValue() { return startValue; }
};


#endif TEXTURESPANELSEGMENT_H