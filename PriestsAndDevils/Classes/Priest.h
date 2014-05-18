#ifndef PRIEST_H
#define PRIEST_H
#include "cocos2d.h"
#include "Boat.h"
#include "Bank.h"
using namespace cocos2d;

class Priest :  public CCNode, public CCTargetedTouchDelegate
{
public:
	Priest();
	Priest(Boat *b, Bank *l, Bank *r);
	virtual ~Priest();
	virtual void onEnter();
	virtual void onExit();

	//触摸事件及触摸托管
	//触摸事件
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    //触摸拖动时间
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    //触摸结束时间
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    
    virtual void touchDelegateRetain();
    virtual void touchDelegateRelease();

	void move();
	void onBoat();
	void offBoat();

	bool isOnBoat;
	int bank;
	int tag;
private:
	CCRect rect();
	Boat *boat;
	Bank *l, *r;

};

#endif