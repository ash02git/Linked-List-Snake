#include "../header/MainMenuUIController.h"
#include "../header/GameService.h"
#include "../header/GraphicService.h"
#include "../header/SoundService.h"
#include "../header/EventService.h"
#include "../header/ButtonView.h"
#include "../header/Config.h"
#include "../header/ImageView.h"

MainMenuUIController::MainMenuUIController()
{
    createImage();
    createButtons();
}

MainMenuUIController::~MainMenuUIController()
{
    destroy();
}

void MainMenuUIController::initialize()
{
    initializeBackgroundImage();
    initializeButtons();
    registerButtonCallback();
}

void MainMenuUIController::createImage()
{
    background_image = new ImageView();
}

void MainMenuUIController::createButtons()
{
    play_button = new ButtonView();
    instructions_button = new ButtonView();
    quit_button = new ButtonView();
}

void MainMenuUIController::initializeBackgroundImage()
{
    sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

    background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
    background_image->setImageAlpha(background_alpha);
}

void MainMenuUIController::initializeButtons()
{
    float x_position = calculateLeftOffsetForButton();

    play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(x_position, play_button_y_position));
    instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(x_position, instructions_button_y_position));
    quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(x_position, quit_button_y_position));
}

void MainMenuUIController::registerButtonCallback()
{
    play_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
    instructions_button->registerCallbackFuntion(std::bind(&MainMenuUIController::instructionsButtonCallback, this));
    quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
}

float MainMenuUIController::calculateLeftOffsetForButton()
{
    sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
}

void MainMenuUIController::playButtonCallback()
{
    // GameState will change to gameplay state.
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
    GameService::setGameState(GameState::LEVEL_SELECTION);
}

void MainMenuUIController::instructionsButtonCallback()
{
    ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
}

void MainMenuUIController::quitButtonCallback()
{
    ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
}

void MainMenuUIController::update()
{
    background_image->update();
    play_button->update();
    instructions_button->update();
    quit_button->update();
}

void MainMenuUIController::render()
{
    background_image->render();
    play_button->render();
    instructions_button->render();
    quit_button->render();
}

void MainMenuUIController::show() 
{
    background_image->show();
    play_button->show();
    instructions_button->show();
    quit_button->show();
}

void MainMenuUIController::destroy()
{
    delete (play_button);
    delete (instructions_button);
    delete (quit_button);
    delete (background_image);
}
