#include <SFML/Graphics.hpp>
#include "headers\MapCreator.h"
#include <iostream>

int main(int argc, char **argv) {
	if (argc > 1)
		MapCreator::start(argv[1]);
	else
		MapCreator::start("texture.png");
	return 0;
}