#pragma once
#ifndef __DOWN_BUTTON__
#define __DOWN_BUTTON__

#include "Button.h"
//#include "UpButton.h"

class DownButton : public Button
{
public:
	DownButton();
	~DownButton();

	//int getPlayerBet();

	

	bool ButtonClick() override;
private:
	bool m_isClicked;

};

#endif /* defined (__DOWN_BUTTON__) */
