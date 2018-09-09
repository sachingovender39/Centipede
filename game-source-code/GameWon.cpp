#include "GameWon.h"
#include "GamePlay.h"
#include "DEFINITIONS.h"

namespace GameEngine
{
	GameWon::GameWon(DataPtr data):
	_data(data)
	{
		//_data->resources.LoadTexture("Game Win Screen Background", GAME_WIN_BACKGROUND_FILEPATH);
		//_background.setTexture(_data->resources.GetTexture("Game Win Screen Background"));
		_data->resources.LoadTexture("Game Win Sprite", GAME_WON);
		_data->resources.LoadTexture("Press F12 Restart", GAME_WIN_RESTART_FILEPATH);
		_gameWon.setTexture(_data->resources.GetTexture("Game Win Sprite"));
		_pressF12ToRestart.setTexture(_data->resources.GetTexture("Press F12 Restart"));
	}

	void GameWon::Initialise()
	{
		_gameWon.setPosition(SCREEN_WIDTH/2 -_gameWon.getGlobalBounds().width/2,
			SCREEN_HEIGHT/2 - _gameWon.getGlobalBounds().height);

		_pressF12ToRestart.setPosition(SCREEN_WIDTH/2 - _pressF12ToRestart.getGlobalBounds().width/2,
			SCREEN_HEIGHT/2);
	}

	void GameWon::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))||
				(event.type == sf::Event::Closed))
			{
				_data->window.close();
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F12))
			{
				// if player presses space after winning, start a new instance of the game 
				_data->statehandler.AddState(StatePtr(new GamePlay(_data)));
			}
		}
	}

	void GameWon::Update(float dt)
	{
		
	}

	void GameWon::Draw()
	{
		// clear screen to update data
		_data->window.clear();
		// draw background sprite with background texture loaded
		//_data->window.draw(_background);
		_data->window.draw(_gameWon);
		_data->window.draw(_pressF12ToRestart);
		// display updated data
		_data->window.display();
	}
}