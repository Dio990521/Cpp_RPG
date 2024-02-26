#pragma once

#include<ctime>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Network.hpp"
class State
{
private:
	std::vector<sf::Texture> textures;
public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;
};
