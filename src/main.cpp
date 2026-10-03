#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>


using namespace geode::prelude;

// hook onto more game btn in main menu

// the hook id using node ids is more-games-button

class $modify(TuffMenuLayer, MenuLayer){
public:
    struct Fields{
        int popupText = 1;
    };

    
    bool init(){
        // CCMenu (id: more-games-menu) -> CCMenuItemSpriteExtra (id: more-games-button) -> CCSprite (No ID) so child of ccmenu then child of that, ez right :D:DD::D:D right?/f/f/d//f
        // im gonna kms
        CCMenu* moreMenu = static_cast<CCMenu*>(this->getChildByID("more-games-menu"));
        CCMenuItemSpriteExtra* btnNode = static_cast<CCMenuItemSpriteExtra*>(moreMenu->getChildByID("more-games-button"));
        CCSprite* sprite = CCSprite::create("res/MoreGames.png");
        btnNode->setSprite(sprite);
      // hopefully no eror now ;d
        return true;
    };
    void onMoreGames(CCObject* sender) {
        FLAlertLayer::create("no games lil bro", "There is no game. Do you understand?", "OK")->show();
    };
};