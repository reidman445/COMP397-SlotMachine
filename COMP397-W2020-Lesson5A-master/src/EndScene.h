#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "PlayButton.h"
#include "Slots.h"
#include "UpButton.h"
#include "DownButton.h"

//#include "DownButton.h"

class EndScene : public Scene
{
public:
	
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();
	int m_pPlayerBet;
	Label* m_LabelBet;
	Label* m_LabelScore;

	int getPlayerBet();

	int playerbet = 0;

	void setBet(int newBet);
	

private:
	Label* m_Label;
	PlayButton* m_pPlayButton;
	UpButton* m_pUpButton;
	DownButton* m_pDownButton;
	Slots* m_pSlots;

	int m_currBet;
	
	
	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__END_SCENE__) */