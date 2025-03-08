#pragma once
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "UI/UIService.h"
#include "Sound/SoundService.h"
#include "Time/TimeService.h"
#include "../../include/Level/LevelService.h"
#include "../../include/Player/PlayerService.h"
#include "../../include/Element/ElementService.h"
#include "../../include/Food/FoodService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphics::GraphicService* graphic_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Level::LevelService* level_service;
        Player::PlayerService* player_service;
        Element::ElementService* element_service;
        Food::FoodService* food_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphics::GraphicService* getGraphicService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        Level::LevelService* getLevelService();
        Player::PlayerService* getPlayerService();
        Element::ElementService* getElementService();
        Food::FoodService* getFoodService();

        void deleteServiceLocator();
    };
}