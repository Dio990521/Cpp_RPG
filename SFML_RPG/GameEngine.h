#ifndef GAME_H
#define GAME_H

#include<ctime>
#include<cstdlib>
#include<iostream>

#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Network.hpp"

class GameEngine
{
private:

	sf::RenderWindow* window;
	sf::Event sfEvent;

	void initWindow();

public:
	GameEngine();
	virtual ~GameEngine();

	//Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif
