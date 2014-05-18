#ifndef BANK_H
#define BANK_H
#include "cocos2d.h"
#include <stack>
using namespace cocos2d;
using namespace std;

class Bank : public CCNode
{
public:
	Bank(bool lr);
	virtual ~Bank();
	virtual void onEnter();
	virtual void onExit();

	bool isSafe();
	int devilNum, priestNum;
};
#endif