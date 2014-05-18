#include "Gameover.h"
#include "GameMain.h"
using namespace cocos2d;

CCScene* Gameover::scene()
{
	CCScene *scene = CCScene::create();
    Gameover *layer = Gameover::create();
    scene->addChild(layer);
    return scene;
}

bool Gameover::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();    
    //创建背景
	CCSprite *bg1 = CCSprite::create("bg.png");
    bg1->setAnchorPoint(ccp(0,0));
	bg1->setPosition( ccp(0,0) );
	this->addChild(bg1);
	
	//创建continue按钮
	CCMenuItemImage *con = CCMenuItemImage::create("continueA.png", "continueB.png",
		this,menu_selector(Gameover::menuContinueCallback));
	con->setScale(0.3f);
	con->setPosition(ccp(size.width / 2,size.height-100));
    CCMenu* mainmenu = CCMenu::create(con,NULL);
    mainmenu->setPosition(ccp(0,0));
    this->addChild(mainmenu,1);

	CCLabelTTF* pLabel = CCLabelTTF::create("Game Over!!", "Arial", 24);
	pLabel->setPosition(ccp(size.width / 2,size.height-40));
	this->addChild(pLabel,1);
}

void Gameover::menuContinueCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameMain::scene());
}