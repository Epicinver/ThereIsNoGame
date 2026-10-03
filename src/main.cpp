#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>


using namespace geode::prelude;

// hook onto more game btn in main menu

// the hook id using node ids is more-games-button

class $modify(TuffMenuLayer, MenuLayer){
public:
    int popupText = 1;
    
    bool init(){
        CCNode* btnNode /*bc c++ FUcking hates me*/ = this->getChildByID("more-games-button");
        CCMenuItemSpriteExtra* btn = dynamic_cast<CCMenuItemSpriteExtra*>(btnNode);
        CCSprite* sprite = CCSprite::create("res/MoreGames.png");
        if (btn){
            btn->setSprite(sprite);
        }
    };
    void onMoreGames(CCObject* sender) {
        FLAlertLayer::create("no games lil bro", "There is no game. Do you understand?", "OK")->show();
    };
    
};