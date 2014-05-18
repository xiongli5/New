#include "GameMenu.h"
#include "GameMain.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameMenu::scene()
{
	CCScene *scene = CCScene::create();
	GameMenu *layer = GameMenu::create();
	scene->addChild(layer);
	return scene;
}

bool GameMenu::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//添加背景
	CCSprite *bg = CCSprite::create("bg.png");
	bg->setPosition( ccp(size.width/2,size.height/2) );
	this->addChild(bg,0,0);

	CCSprite*bgstar = CCSprite::create("moon.png");
    bgstar->setAnchorPoint(ccp(0.5,0));
    bgstar->setScale(0.5);
    bgstar->setPosition(ccp(size.width/3 * 2, 0));
    this->addChild(bgstar,1,1);

	//添加标题
	CCNode *title = CCNode::create();
    title->setContentSize(CCSizeMake(size.width-40,50));
    CCSprite *ptmLabel = CCSprite::create("meowstar.png");
    ptmLabel->setScale(0.5);
    ptmLabel->setPosition( ccp(0,30) );
    title->addChild(ptmLabel);
    CCSprite *ptbLabel = CCSprite::create("battle.png");
    ptbLabel->setScale(0.5);
    ptbLabel->setPosition( ccp(0,-30) );
    title->addChild(ptbLabel);
    title->setPosition(ccp(size.width / 2, size.height - 80));
    this->addChild(title,2,2);

	//添加newgame按钮
	CCMenuItemImage *newGameItem = CCMenuItemImage::create("newgameA.png", "newgameB.png",
		this,menu_selector(GameMenu::menuNewGameCallback));
	newGameItem->setScale(0.7f);
	newGameItem->setPosition(ccp(size.width / 2,size.height / 2 - 20));
	//newGameItem->setEnabled(true);
	
	////添加continue按钮
	//CCMenuItemImage *continueItem = CCMenuItemImage::create("continueA.png", "continueB.png",
	//	this,menu_selector(GameMenu::menuContinueCallback));
 //   continueItem->setScale(0.7f);
 //   continueItem->setPosition(ccp(size.width / 2,size.height / 2 - 80));
 //   //continueItem->setEnabled(false);

	////添加about按钮
 //   CCMenuItemImage *aboutItem = CCMenuItemImage::create("aboutA.png", "aboutB.png",
	//	this,menu_selector(GameMenu::menuAboutCallback));
 //   aboutItem->setScale(0.7f);
 //   aboutItem->setPosition(ccp(size.width / 2,size.height / 2 - 140));
 // //  aboutItem->setEnabled(false);

	////添加sound按钮
 //   soundItem = CCMenuItemImage::create("sound-on-A.png", "sound-on-B.png",
	//	this,menu_selector(GameMenu::menuSoundCallback));
 //   soundItem->setScale(0.7f);
 //   //soundItem->setEnabled(false);
 //   soundItem->setPosition(ccp(40,40));

    //使用按钮创建菜单
    CCMenu* mainmenu = CCMenu::create(newGameItem,NULL);
    mainmenu->setPosition(ccp(0,0));
    this->addChild(mainmenu,1,3);

	/*issound = true;
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
		std::string(CCFileUtils::sharedFileUtils()->fullPathForFilename("background.mp3")).c_str(),true);*/
    return true;
}



void GameMenu::onExit(){
    CCLayer::onExit();
}
void GameMenu::menuNewGameCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(GameMain::scene());
}
//void GameMenu::menuContinueCallback(CCObject* pSender)
//{
//   // CCDirector::sharedDirector()->replaceScene(GameMain::scene());
//}
//void GameMenu::menuAboutCallback(CCObject* pSender)
//{
//   // CCDirector::sharedDirector()->replaceScene(GameAbout::scene());
//}
//void GameMenu::menuSoundCallback(CCObject* pSender)
//{
//    if(! issound){
//        soundItem->setNormalImage(CCSprite::create("sound-on-A.png"));
//        soundItem->setDisabledImage(CCSprite::create("sound-on-B.png"));
//       SimpleAudioEngine::sharedEngine()->playBackgroundMusic(std::string(
//		   CCFileUtils::sharedFileUtils()->fullPathForFilename("background.mp3")).c_str(),true);
//       issound = true;
//    }else{
//        soundItem->setNormalImage(CCSprite::create("sound-off-A.png"));
//        soundItem->setDisabledImage(CCSprite::create("sound-off-B.png"));
//         SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
//       issound = false;
//    }
//}