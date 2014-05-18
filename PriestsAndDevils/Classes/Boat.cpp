#include "Boat.h"

Boat::Boat()
{
	bank = 1;
	passengerNum = 0;
	isLeftEmpty = true;
	isRightEmpty = true;
}

Boat::~Boat()
{
}

void Boat::onEnter()
{
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(85,90));
	CCSprite *mainSprite = CCSprite::create("a.png");
	addChild(mainSprite);
}

void Boat::onExit()
{
	CCNode::onExit();
}

void Boat::move()
{
	if(passengerNum > 0)
	{
		CCMoveTo *m = CCMoveTo::create(1,ccp(this->getPositionX()+(bank*100),this->getPositionY()));
		this->runAction(m);
		bank = -bank;
	}
}

void Boat::getOn()
{
	if(passengerNum < 2)
		passengerNum++;
}

void Boat::getOff()
{
	if(passengerNum > 0)
		passengerNum--;
}

int Boat::getBank()
{
	return bank;
}

int Boat::getPsNum()
{
	return passengerNum;
}