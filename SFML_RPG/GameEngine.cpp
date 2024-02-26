#include "GameEngine.h"

void GameEngine::initWindow()
{
    std::ifstream ifs("Configs/window.ini");

    std::string title = "None";
    sf::VideoMode windowBounds(800, 600);
    unsigned frameRateLimit = 120;
    bool verticalSyncEnabled = false;
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> frameRateLimit;
        ifs >> verticalSyncEnabled;
    }
    ifs.close();

	this->window = new sf::RenderWindow(windowBounds, title);
    this->window->setFramerateLimit(frameRateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

GameEngine::GameEngine()
{
    this->initWindow();
}

GameEngine::~GameEngine() 
{
	delete this->window;
}

/*Update the deltaTime with the time it takes to update and render one frame*/
void GameEngine::updateDeltaTime()
{
    this->deltaTime = this->deltaTimeClock.restart().asSeconds();
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
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}
