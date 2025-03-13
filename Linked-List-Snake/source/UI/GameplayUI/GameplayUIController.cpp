#include "../../include/UI/GameplayUI/GameplayUIController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Player/SnakeController.h"

namespace UI
{
	namespace GameplayUI
	{
		GameplayUIController::GameplayUIController()
		{
			createTexts();
		}
		GameplayUIController::~GameplayUIController()
		{
			delete(level_number_text);
			delete(score_text);
			delete(time_complexity_text);
			delete(operation_text);
		}
		void GameplayUIController::initialize()
		{
			initializeTexts();
		}
		void GameplayUIController::update()
		{
			updateLevelNumberText();
			updateScoreText();
			updateTimeComplexityText();
			updateOperationText();
		}
		void GameplayUIController::render()
		{
			score_text->render();
			level_number_text->render();
			operation_text->render();
			time_complexity_text->render();
		}
		void GameplayUIController::show()
		{
			score_text->show();
			level_number_text->show();
			operation_text->show();
			time_complexity_text->show();
		}
		void GameplayUIController::createTexts()
		{
			score_text = new UI::UIElement::TextView();
			level_number_text = new UI::UIElement::TextView();
			operation_text = new UI::UIElement::TextView();
			time_complexity_text = new UI::UIElement::TextView();
		}
		void GameplayUIController::initializeTexts()
		{
			initializeLevelNumberText();
			initializeScoreText();
			initializeOperationText();
			initializeTimeComplexityText();
		}
		void GameplayUIController::initializeLevelNumberText()
		{
			level_number_text->initialize("Level : 1", sf::Vector2f(level_number_text_x_position, text_y_position), UIElement::FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
		}
		void GameplayUIController::initializeScoreText()
		{
			score_text->initialize("Score : 0", sf::Vector2f(score_text_x_position, text_y_position), UIElement::FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
		}
		void GameplayUIController::updateLevelNumberText()
		{
			Level::LevelNumber level_number = Global::ServiceLocator::getInstance()->getLevelService()->getCurrentLevel();
			sf::String level_number_value = std::to_string(1 + static_cast<int>(level_number));

			level_number_text->setText("Level : " + level_number_value);
			level_number_text->update();
		}
		void GameplayUIController::updateScoreText()
		{
			int player_score = Global::ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();
			sf::String score_value = std::to_string(player_score);

			score_text->setText("Score : " + score_value);
			score_text->update();
		}
		void GameplayUIController::initializeTimeComplexityText()
		{
			time_complexity_text->initialize("Time Complexity : O(1)", sf::Vector2f(time_complexity_text_x_position, time_complexity_text_y_position), UIElement::FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
		}
		void GameplayUIController::initializeOperationText()
		{
			operation_text->initialize("Last Operation : Insert at Middle", sf::Vector2f(operations_text_x_position, operations_text_y_position), UIElement::FontType::BUBBLE_BOBBLE, operations_font_size, sf::Color::Black);
		}
		void GameplayUIController::updateTimeComplexityText()
		{
			Player::TimeComplexity time_complexity = Global::ServiceLocator::getInstance()->getPlayerService()->getTimeComplexity();
			sf::String time_complexity_value;

			switch (time_complexity)
			{
			case Player::TimeComplexity::NONE:
				time_complexity_value = "";
			case Player::TimeComplexity::ONE:
				time_complexity_value = "1";
				break;
			case Player::TimeComplexity::N:
				time_complexity_value = "N";
				break;
			}
			time_complexity_text->setText("Time Complexity : (" + time_complexity_value + ")");
			time_complexity_text->update();
		}
		void GameplayUIController::updateOperationText()
		{
			Player::LinkedListOperations operation = Global::ServiceLocator::getInstance()->getPlayerService()->getLastOperation();
			sf::String operation_value;

			switch (operation)
			{
			case Player::LinkedListOperations::NONE:
				operation_value = "";
			case Player::LinkedListOperations::INSERT_AT_HEAD:
				operation_value = "Insert at Head";
				break;
			case Player::LinkedListOperations::INSERT_AT_TAIL:
				operation_value = "Insert at Tail";
				break;
			case Player::LinkedListOperations::INSERT_AT_MID:
				operation_value = "Insert at Mid";
				break;
			case Player::LinkedListOperations::REMOVE_AT_HEAD:
				operation_value = "Remove at Head";
				break;
			case Player::LinkedListOperations::REMOVE_AT_TAIL:
				operation_value = "Remove at Tail";
				break;
			case Player::LinkedListOperations::REMOVE_AT_MID:
				operation_value = "Remove at Mid";
				break;
			case Player::LinkedListOperations::DELETE_HALF_LIST:
				operation_value = "Delete Half List";
				break;
			case Player::LinkedListOperations::REVERSE_LIST:
				operation_value = "Reverse List";
				break;

			}

			operation_text->setText("Last Operation : " + operation_value);
			operation_text->update();
		}
	}
}