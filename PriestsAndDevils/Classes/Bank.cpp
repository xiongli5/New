#include "Bank.h"

Bank::Bank(bool lr)
{
	if(lr)
	{
		devilNum = 3;
		priestNum = 3;
	}
	else
	{
		devilNum = 0;
		priestNum = 0;
	}
}

Bank::~Bank()
{
}

void Bank::onEnter()
{
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(85,90));
	CCSprite *mainSprite = CCSprite::create("bank.png");
	addChild(mainSprite);
}

void Bank::onExit()
{
	CCNode::onExit();
}

bool Bank::isSafe()
{
	if(priestNum >= devilNum || priestNum == 0)
		return true;
	else
		return false;
}