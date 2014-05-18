#include "Devil.h"

Devil::Devil()
{
	bank = 1;
	isOnBoat = false;
}

Devil::Devil(Boat *b, Bank *l, Bank *r)
{
	bank = 1;
	isOnBoat = false;
	boat = b;
	this->l = l;
	this->r = r;
}

Devil::~Devil()
{
}

void Devil::onEnter()
{
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(85,90));
	CCSprite *mainSprite = CCSprite::create("d.png");
	addChild(mainSprite);
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

void Devil::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
	CCNode::onExit();
}

void Devil::touchDelegateRetain()
{
    this->retain();
}

void Devil::touchDelegateRelease()
{
    this->release();
}

bool Devil::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCPoint touchLocation = touch->getLocation();
    CCPoint localPos = convertToNodeSpace(touchLocation);
    CCRect rc = rect();
    rc.origin = ccp(-getContentSize().width/2,-getContentSize().height/2);
    bool isTouched = rc.containsPoint(localPos);
    if(isTouched)
    {
		if(isOnBoat)
			offBoat();
		else
			onBoat();
        return true;
    }
	return false;
}
void Devil::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
}

void Devil::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
}

CCRect Devil::rect()
{
	return CCRectMake(getPositionX() - getContentSize().width * getAnchorPoint().x,
                      getPositionY() - getContentSize().height * getAnchorPoint().y,
                      getContentSize().width, getContentSize().height);
}

void Devil::onBoat()
{
	if(boat->getBank() == bank && boat->getPsNum() != 2)
	{
		CCMoveTo *m;
		if(boat->isLeftEmpty)
		{
			m = CCMoveTo::create(0.3,ccp(boat->getPositionX()-40,boat->getPositionY()+40));
			boat->isLeftEmpty = false;
		}
		else
		{
			m = CCMoveTo::create(0.3,ccp(boat->getPositionX()+40,boat->getPositionY()+40));
			boat->isRightEmpty = false;
		}
		this->runAction(m);
		isOnBoat = true;
		boat->getOn();
	}
}

void Devil::offBoat()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	if(this->getPositionX() == boat->getPositionX()-40)
		boat->isLeftEmpty = true;
	else
		boat->isRightEmpty = true;
	CCMoveTo *m;
	if(bank == 1)
		m = CCMoveTo::create(0.3,ccp(l->getPositionX()+tag*30-80,size.height/2-32));
	else
		m = CCMoveTo::create(0.3,ccp(r->getPositionX()+tag*30-80,size.height/2-32));
	this->runAction(m);
	isOnBoat = false;
	boat->getOff();
}

void Devil::move()
{
	CCMoveTo *m = CCMoveTo::create(1,ccp(this->getPositionX()+(bank*100),this->getPositionY()));
	this->runAction(m);
	bank = -bank;
}