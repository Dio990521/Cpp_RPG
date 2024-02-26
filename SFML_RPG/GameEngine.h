#ifndef GAME_H
#define GAME_H

#include "State.h"


class GameEngine
{
private:

	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock deltaTimeClock;
	float deltaTime;

	void initWindow();

public:
	GameEngine();
	virtual ~GameEngine();

	//Functions
	void updateDeltaTime();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif
