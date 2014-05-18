#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "cocos2d.h"

class Gameover : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    void menuContinueCallback(CCObject* pSender);
    
	CREATE_FUNC(Gameover);
};

#endif