#include "GameMain.h"
#include "Gameover.h"
#include "GameMenu.h"
using namespace cocos2d;

CCScene* GameMain::scene()
{
	CCScene *scene = CCScene::create();
    GameMain *layer = GameMain::create();
    scene->addChild(layer);
    return scene;
}

bool GameMain::init()
{
	if ( !CCLayer::init() )
    {
        return false;
    }
	gameState = 0;
	countTime = 60;
	isControl = false;

    CCSize size = CCDirector::sharedDirector()->getWinSize();    
    //创建背景
	CCSprite *bg1 = CCSprite::create("bg.png");
    bg1->setAnchorPoint(ccp(0,0));
	bg1->setPosition( ccp(0,0) );
	this->addChild(bg1);
	
	//创建go按钮
	CCMenuItemImage *goItem = CCMenuItemImage::create("newgameA.png", "newgameB.png",
		this,menu_selector(GameMain::goMenuCallBack));
	goItem->setScale(0.3f);
	goItem->setPosition(ccp(size.width / 2,size.height-40));
    
	//创建help按钮
	CCMenuItemImage *helpItem = CCMenuItemImage::create("aboutA.png", "aboutB.png",
		this,menu_selector(GameMain::helpMenuCallBack));
	helpItem->setScale(0.3f);
	helpItem->setPosition(ccp(size.width / 3 *2 ,size.height-40));

	CCMenu* mainmenu = CCMenu::create(goItem,helpItem,NULL);
    mainmenu->setPosition(ccp(0,0));
    this->addChild(mainmenu,1,3);

	//创建boat
	boat = new Boat();
	boat->setPosition(250,size.height/2-80);
	boat->setScale(0.2);
	addChild(boat,2,1);

	//创建bank
	bankl = new Bank(true);
	bankl->setPosition(ccp(97,size.height/2-80));
	addChild(bankl,2,2);

	bankr = new Bank(false);
	bankr->setPosition(ccp(503,size.height/2-80));
	addChild(bankr,2,3);

	//创建devil和priest
	for(int i = 0; i < 3; i++)
	{
		Devil *d = new Devil(boat,bankl,bankr);
		d->tag = i;
		d->setPosition(i*30+20,size.height/2-32);
		d->setScale(0.5);
		addChild(d,3,4+i);
		devils[i] = d;

		Priest *p = new Priest(boat,bankl,bankr);
		p->tag = i;
		p->setPosition((i+3)*30+20,size.height/2-32);
		p->setScale(0.5);
		addChild(p,3,7+i);
		priests[i] = p;
	}
	//创建倒计时
	pLabel = CCLabelTTF::create("60", "Arial", 24);
	pLabel->setPosition(ccp(size.width / 3 ,size.height-40));
	this->addChild(pLabel,1);

	this->schedule(schedule_selector(GameMain::timeCount),1);

    return true;
}

void GameMain::goMenuCallBack(CCObject *pSender)
{
	if(!isControl){
		isControl = true;
		move();
	}
	isControl = false;

	/*boat->move();
	for(int i = 0; i < 3; i++)
	{
		if(devils[i]->isOnBoat)
			devils[i]->move();
		if(priests[i]->isOnBoat)
			priests[i]->move();
	}

	int devilInLeft = 0, priestInLeft = 0;
	for(int i = 0; i < 3; i++)
	{
		if(devils[i]->bank == 1)
			devilInLeft++;
		if(priests[i]->bank == 1)
			priestInLeft++;
	}
	bankl->devilNum = devilInLeft;
	bankl->priestNum = priestInLeft;
	bankr->devilNum = 3 - devilInLeft;
	bankr->priestNum = 3 - priestInLeft;

	if(!bankl->isSafe() || !bankr->isSafe())
		gameState = -1;
	else if(bankr->devilNum == 3 && bankr->priestNum ==3)
		gameState = 1;
	else
		gameState = 0;
	checkState();*/
}

void GameMain::checkState()
{
	if(gameState == -1)
		CCDirector::sharedDirector()->replaceScene(Gameover::scene());
	else if(gameState == 1)
		CCDirector::sharedDirector()->replaceScene(GameMenu::scene());
}

void GameMain::timeCount(float dt)
{
	countTime--;
	char text[256];
	sprintf(text,"%d",countTime);
	if(countTime < 0 && gameState == 0)
		CCDirector::sharedDirector()->replaceScene(Gameover::scene());
	else{
		pLabel->setString(text);
	}
} 

void GameMain::helpMenuCallBack(CCObject *pSender)
{
	if(!isControl){
		isControl = true;
		string boatP;
		int priestL,devilL;
		//船上人员下船
		for(int i = 0;i <=2;i++){
			if(devils[i]->isOnBoat)
				devils[i]->offBoat();
			if(priests[i]->isOnBoat)
				priests[i]->offBoat();
		}

		if(boat->getBank() == 1 ){
			boatP = "left";
			priestL =  bankl->priestNum;
			devilL = bankl->devilNum;
		}
		else{
			boatP = "right";
			priestL = bankl->priestNum;
			devilL = bankl->devilNum;
		}

		gameS.setCurrentState(priestL,devilL,boatP);
		gameS.Help();

		if(boatP == "left"){
			int priestX =priestL - gameS.getLeftPriests();
			int devilX = devilL - gameS.getLeftDevils();
			for(int i = 0;i <=2 && priestX >0;i++){
				if(priests[i]->bank == 1){
					priests[i]->onBoat();
					priestX--;
				}
			}

			for(int i = 0;i<=2 && devilX > 0;i++){
				if(devils[i]->bank==1){
					devils[i]->onBoat();
					devilX--;
				}
			}
			move();

			/*for(int i = 0; i < 3; i++)
			{
				if(devils[i]->isOnBoat)
					devils[i]->offBoat();
				if(priests[i]->isOnBoat)
					priests[i]->offBoat();
			}*/
		}
		else{
			int priestX = gameS.getLeftPriests()- priestL ;
			int devilX = gameS.getLeftDevils()- devilL ;
			for(int i = 0;i <=2 && priestX >0;i++){
				if(priests[i]->bank == -1){
					priests[i]->onBoat();
					priestX--;
				}
			}

			for(int i = 0;i<=2 && devilX > 0;i++){
				if(devils[i]->bank==-1){
					devils[i]->onBoat();
					devilX--;
				}
			}
			move();
			/*for(int i = 0; i < 3; i++)
			{
				if(devils[i]->isOnBoat)
					devils[i]->offBoat();
				if(priests[i]->isOnBoat)
					priests[i]->offBoat();
			}*/
		}
	}
	isControl = false;
}

void GameMain::move()
{
	boat->move();
	for(int i = 0; i < 3; i++)
	{
		if(devils[i]->isOnBoat)
			devils[i]->move();
		if(priests[i]->isOnBoat)
			priests[i]->move();
	}

	int devilInLeft = 0, priestInLeft = 0;
	for(int i = 0; i < 3; i++)
	{
		if(devils[i]->bank == 1)
			devilInLeft++;
		if(priests[i]->bank == 1)
			priestInLeft++;
	}
	bankl->devilNum = devilInLeft;
	bankl->priestNum = priestInLeft;
	bankr->devilNum = 3 - devilInLeft;
	bankr->priestNum = 3 - priestInLeft;

	if(!bankl->isSafe() || !bankr->isSafe())
		gameState = -1;
	else if(bankr->devilNum == 3 && bankr->priestNum ==3)
		gameState = 1;
	else
		gameState = 0;
	checkState();
}