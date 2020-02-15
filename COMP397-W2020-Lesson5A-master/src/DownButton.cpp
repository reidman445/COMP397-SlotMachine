#include "DownButton.h"
//#include "UpButton.h"
#include "Game.h"
#include "EndScene.h"

DownButton::DownButton()
// call super constructor
	:Button(
		"../Assets/textures/downArrow.png",
		"downButton",
		DOWN_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

DownButton::~DownButton()
{
}




bool DownButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			//playerbet--;
			betMinus();
			
			std::cout << "Subtract " << getBet() << std::endl;

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

