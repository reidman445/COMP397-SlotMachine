#include "UpButton.h"
#include "Game.h"
#include "EndScene.h"

UpButton::UpButton()
// call super constructor
	:Button(
		"../Assets/textures/upArrow.png",
		"upButton",
		UP_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

UpButton::~UpButton()
{
}

//int UpButton::getPlayerBet()
//{
//	return playerbet;
//}


bool UpButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			
			betAdd();
			//playerbet++;
			std::cout << "Bet: " << getBet() << std::endl;

			//Game::Instance()->changeSceneState(START_SCENE);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}

