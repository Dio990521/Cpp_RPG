#include "GameEngine.h"

void GameEngine::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Chengzhang Dong's mini C++ RPG");
}

GameEngine::GameEngine()
{
    this->initWindow();
}

GameEngine::~GameEngine() 
{
	delete this->window;
}

void GameEngine::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent)) 
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void GameEngine::update()
{
    this->updateSFMLEvents();
}

void GameEngine::render()
{
    this->window->clear();

    this->window->display();
}

void GameEngine::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
