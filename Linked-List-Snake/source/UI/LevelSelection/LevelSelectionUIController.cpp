#include "../../include/UI/LevelSelection/LevelSelectionUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace UI
{
	namespace LevelSelection
	{
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        LevelSelectionUIController::LevelSelectionUIController()
        {
            createImage();
            createButtons();
        }

        LevelSelectionUIController::~LevelSelectionUIController()
        {
            destroy();
        }

        void LevelSelectionUIController::initialize()
        {
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void LevelSelectionUIController::createImage()
        {
            background_image = new ImageView();
        }

        void LevelSelectionUIController::createButtons()
        {
            level_one_button = new ButtonView();
            level_two_button = new ButtonView();
            menu_button = new ButtonView();
        }

        void LevelSelectionUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void LevelSelectionUIController::initializeButtons()
        {
            level_one_button->initialize("Level One", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(0, levelone_button_y_position));
            level_two_button->initialize("Level Two", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(0, leveltwo_button_y_position));
            menu_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

            level_one_button->setCentreAlinged();
            level_two_button->setCentreAlinged();
            menu_button->setCentreAlinged();
        }

        void LevelSelectionUIController::registerButtonCallback()
        {
            level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelOneButtonCallback, this));
            level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::levelTwoButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::menuButtonCallback, this));
        }

        void LevelSelectionUIController::levelOneButtonCallback()
        {
            GameService::setGameState(GameState::GAMEPLAY);
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            Global::ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::ONE);
        }

        void LevelSelectionUIController::levelTwoButtonCallback()
        {
            GameService::setGameState(GameState::GAMEPLAY);
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            Global::ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::TWO);
        }

        void LevelSelectionUIController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void LevelSelectionUIController::update()
        {
            background_image->update();
            level_one_button->update();
            level_two_button->update();
            menu_button->update();
        }

        void LevelSelectionUIController::render()
        {
            background_image->render();
            level_one_button->render();
            level_two_button->render();
            menu_button->render();
        }

        void LevelSelectionUIController::show()
        {
            background_image->show();
            level_one_button->show();
            level_two_button->show();
            menu_button->show();
        }

        void LevelSelectionUIController::destroy()
        {
            delete (level_one_button);
            delete (level_two_button);
            delete (menu_button);
            delete (background_image);
        }
	}
}