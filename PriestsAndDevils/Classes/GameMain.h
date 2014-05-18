#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include "cocos2d.h"
#include "Boat.h"
#include "Bank.h"
#include "Devil.h"
#include "Priest.h"
#include "GameState.h"
using namespace std;

class GameMain : public cocos2d::CCLayer
{
public:
	virtual bool init(); 
	static cocos2d::CCScene* scene();

	void goMenuCallBack(CCObject *pSender);

	void helpMenuCallBack(CCObject *pSender);

	CREATE_FUNC(GameMain);

	void checkState();

	void timeCount(float dt);

	void move();
private:
	int gameState;	//-1为失败，0为游戏中，1为成功
	CCLabelTTF* pLabel;
	int countTime;
	GameState gameS;

	bool isControl;

	Boat *boat;
	Bank *bankl, *bankr;
	Devil *devils[3];
	Priest *priests[3];
};

#endif