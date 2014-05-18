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
	int bank; //1Ϊ���󰶣�-1Ϊ���Ұ�
	int passengerNum;
};
#endif