#ifndef BOAT_H
#define BOAT_H
#include "cocos2d.h"
using namespace cocos2d;

class Boat : public CCNode
{
public:
	Boat();
	virtual ~Boat();
	virtual void onEnter();
	virtual void onExit();

	void move();
	void getOn();
	void getOff();
	int getBank();
	int getPsNum();
	bool isLeftEmpty;
	bool isRightEmpty;
private:
	int bank; //1为在左岸，-1为在右岸
	int passengerNum;
};
#endif