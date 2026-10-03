#include <Geode/Geode.hpp>
#include <Geode/binding/MenuLayer.hpp>

using namespace geode::prelude;

// hook onto more game btn in main menu

// the hook id using node ids is more-games-button

class $modify(TuffMenuLayer, MenuLayer){
public:
    int popupText = 1;
    
    bool init(){
        CCMenuItemSpriteExtra* btn = this->getChildByID("more-games-button");
        CCSprite* sprite = CCSprite::create("res/MoreGames.png");
        btn->setNormalImage(sprite);

        void onMoreGames(CCObject* sender) {
            FLAlertLayer::create("no games lil bro", "There is no game. Do you understand?", "OK")->show();
        };
    };
    
};