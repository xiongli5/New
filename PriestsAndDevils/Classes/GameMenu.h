#ifndef GAMEMENU_H
#define GAMEMENU_H
#include "cocos2d.h"
using namespace cocos2d;

class GameMenu : public cocos2d::CCLayer
{
public:
	bool issound;

	CCMenuItemImage *soundItem;

	virtual bool init();

	virtual void onExit();

	static cocos2d::CCScene* scene();

    void menuNewGameCallback(CCObject* pSender);
    
    //void menuContinueCallback(CCObject* pSender);
    
    //void menuAboutCallback(CCObject* pSender);
    
    //void menuSoundCallback(CCObject* pSender);
	
	CREATE_FUNC(GameMenu);
};

#endif