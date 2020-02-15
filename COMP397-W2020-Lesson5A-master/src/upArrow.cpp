#include "PlayButton.h"
#include "Game.h"

PlayButton::PlayButton()
// call super constructor
	:Button(
		"../Assets/textures/spin.png",
		"playButton",
		PLAY_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

PlayButton::~PlayButton()
{
}

bool PlayButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{


			int playerBet = 0;


			//Game::Instance()->changeSceneState(END_SCENE);
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


