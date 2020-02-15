#pragma once
#ifndef __UP_BUTTON__
#define __UP_BUTTON__

#include "Button.h"

class PlayButton : public Button
{
public:
	PlayButton();
	~PlayButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__PLAY_BUTTON__) */#pragma once
