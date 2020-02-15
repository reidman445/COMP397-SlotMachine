#include "Slots.h"
#include "Game.h"

Slots::Slots()
{
	TheTextureManager::Instance()->load("../Assets/textures/slots.png",
		"slots", TheGame::Instance()->getRenderer());

	// measure size by querying the texture
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("slot_temp");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 220.0f));
	setIsColliding(false);
	setType(GameObjectType::SLOTS);
	//setVelocity(glm::vec2(0.0f, 0.0f));

	TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);

}

Slots::~Slots()
{
}

void Slots::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("slots", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Slots::update()
{
}

void Slots::clean()
{
}
