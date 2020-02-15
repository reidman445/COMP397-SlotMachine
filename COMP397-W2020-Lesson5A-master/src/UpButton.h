#pragma once
#ifndef __UP_BUTTON__
#define __UP_BUTTON__

#include "Button.h"

class UpButton : public Button
{
public:
	UpButton();
	~UpButton();

	//int getPlayerBet();

	int playerbet = 0;

	bool ButtonClick() override;
private:
	bool m_isClicked;
	
};

#endif /* defined (__UP_BUTTON__) */
