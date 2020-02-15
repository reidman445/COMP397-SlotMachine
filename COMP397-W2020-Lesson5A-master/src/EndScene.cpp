#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include "Slots.h"
#include "UpButton.h"
#include "DownButton.h"


EndScene::EndScene()
{
	EndScene::start();
	EndScene::update();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_pSlots->draw();
	m_Label->draw();
	m_LabelBet->draw();
	m_LabelScore->draw();
	m_pPlayButton->draw();
	m_pUpButton->draw();
	m_pDownButton->draw();
	
}

void EndScene::update()
{
	m_pPlayButton->setMousePosition(m_mousePosition);
	m_pPlayButton->ButtonClick();

	m_pUpButton->setMousePosition(m_mousePosition);
	m_pUpButton->ButtonClick();

	m_pDownButton->setMousePosition(m_mousePosition);
	m_pDownButton->ButtonClick();

	
	m_pPlayerBet = getBet();
	m_pPlayerBet = m_pUpButton->getBet();
	//m_pPlayerBet = m_pDownButton->getBet();
	
	m_LabelScore = new Label(std::to_string(m_pPlayerBet), "FinalFrontier", 20, { 255, 0, 255, 255 }, glm::vec2(430.0f, 440.0f));
	m_LabelScore->draw();
}

void EndScene::clean()
{
	delete m_Label;
	removeAllChildren();
}

void EndScene::handleEvents()
{


	
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pUpButton->setMouseButtonClicked(true);
				m_pDownButton->setMouseButtonClicked(true);
				m_pPlayButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pUpButton->setMouseButtonClicked(false);
				m_pDownButton->setMouseButtonClicked(false);
				m_pPlayButton->setMouseButtonClicked(false);
				break;
			}
			break;
		



			
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}



void EndScene::start()
{
	SDL_Color blue = { 0, 0, 255, 255 };
	m_Label = new Label("Reid's Slot-ORAMA", "FinalFrontier", 80, blue, glm::vec2(400.0f, 40.0f));
	m_Label->setParent(this);
	addChild(m_Label);

	m_LabelBet = new Label("Bet:", "FinalFrontier", 20, blue, glm::vec2(400.0f, 440.0f));
	m_LabelBet->setParent(this);
	addChild(m_LabelBet);

	

	m_LabelScore = new Label(std::to_string(m_pPlayerBet) , "FinalFrontier", 20, blue, glm::vec2(430.0f, 440.0f));
	m_LabelScore->setParent(this);
	addChild(m_LabelScore);

	m_pPlayButton = new PlayButton();
	m_pPlayButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.82f));
	addChild(m_pPlayButton);

	m_pSlots = new Slots(); // instantiates Slot Machine Background
	addChild(m_pSlots);

	m_pUpButton = new UpButton();
	m_pUpButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.72f, Config::SCREEN_HEIGHT * 0.82f));
	addChild(m_pUpButton);

	m_pDownButton = new DownButton();
	m_pDownButton->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.72f, Config::SCREEN_HEIGHT * 0.89f));
	addChild(m_pDownButton);

	m_pPlayerBet = getBet();

	update();

	
	
}

glm::vec2 EndScene::getMousePosition()
{
	return m_mousePosition;
}



