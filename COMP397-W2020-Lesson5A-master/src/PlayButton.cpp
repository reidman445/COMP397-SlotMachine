#include "PlayButton.h"
#include "Game.h"
#include "UpButton.h"

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
			if( getBet() == 0)
			{
				std::cout << "no $$$ :*(" << std::endl;
			}
			else
			{


				std::cout << "C'mon Money money money... Betting: " << std::endl;
			}

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


