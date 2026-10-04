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
            auto sfxpath = geode::Mod::get()->getResourcesDir() / "breh.mp3";
            FMODAudioEngine::get()->playEffect(sfxpath.string());
            FLAlertLayer::create("no games lil bro", "There is no more games. Sorry!", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==2){
            auto sfxpaath = geode::Mod::get()->getResourcesDir() / "huh.mp3";
            FMODAudioEngine::get()->playEffect(sfxpaath.string());
            FLAlertLayer::create("This isnt funny", "There is no other games. I've told you this. Stop trying.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==3){
            auto sfxpaaath = geode::Mod::get()->getResourcesDir() / "stopit.mp3";
            FMODAudioEngine::get()->playEffect(sfxpaaath.string());
            FLAlertLayer::create("Stop", "There will never be more games. Do you want me to crash your game? Do this again and I will.", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==4){
            auto sfxpaaaath = geode::Mod::get()->getResourcesDir() / "fart.mp3";
            FMODAudioEngine::get()->playEffect(sfxpaaaath.string());
            FLAlertLayer::create("I warned you", "Stop it. This is your last chance. Do it again and your game goes bye bye!", "OK")->show();
            m_fields->popupText++;
        } else if (m_fields->popupText==5){
            auto sfxpaaaaath = geode::Mod::get()->getResourcesDir() / "saywallahi.mp3";
            FMODAudioEngine::get()->playEffect(sfxpaaaaath.string());
            FLAlertLayer::create("Just stop", "Please? I won't crash your game. Please. I'm begging you. Just stop clicking the button. There are NO MORE GAMES. I'll even say it out loud for you", "alr fine")->show();
            m_fields->popupText = 1;
            auto sfxpaaaaaath = geode::Mod::get()->getResourcesDir() / "nomore.mp3";
            /* FMODAudioEngine::get()->playEffect(sfxpaaaaaath.string()); holy shit bro this is so ass*/
        }
    };
};