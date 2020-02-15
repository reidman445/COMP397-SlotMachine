#pragma once
#ifndef __SLOTS__
#define __SLOTS__
#include "DisplayObject.h"

class Slots : public DisplayObject
{
public:
	Slots();
	~Slots();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__SLOTS__) */