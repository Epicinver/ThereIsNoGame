#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <thread>
#include <chrono>

using namespace geode::prelude;

// hook onto more game btn in main menu

// the hook id using node ids is more-games-button

class $modify(TuffMenuLayer, MenuLayer){
public:
    struct Fields{
        int popupText = 1;
    };
    void onMoreGames(CCObject* sender) {
        if (m_fields->popupText==1){
            FLAlertLayer::create("no games lil bro", "There is no game. Do you understand?", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==2){
            FLAlertLayer::create("This isnt funny", "There is no game. I've told you this. Stop trying.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==3){
            FLAlertLayer::create("Stop", "There will never be more games. Do you want me to crash your game? Do this again and I will.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==4){
            FLAlertLayer::create("I warned you", "Stop it. This is your last chance.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==5){
            FLAlertLayer::create("You asked for it", "You have been warned. Goodbye.", "OK")->show();
            std::this_thread::sleep_for(std::chrono::seconds(4));
            m_fields->popupText = 1;
            exit(0);
        }
    };
};