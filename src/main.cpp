#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <thread>
#include <chrono>
#include <Geode/binding/FMODAudioEngine.hpp>

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
            FMODAudioEngine::get()->playEffect("./res/breh.mp3");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            FLAlertLayer::create("no games lil bro", "There is no more games. Sorry!", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==2){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            FLAlertLayer::create("This isnt funny", "There is no other games. I've told you this. Stop trying.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==3){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            FLAlertLayer::create("Stop", "There will never be more games. Do you want me to crash your game? Do this again and I will.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==4){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            FLAlertLayer::create("I warned you", "Stop it. This is your last chance. Do it again and your game goes bye bye!", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==5){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            FLAlertLayer::create("Just stop", "Please? I won't crash your game. Please. I'm begging you", "alr fine")->show();
            m_fields->popupText++;
        }
    };
};