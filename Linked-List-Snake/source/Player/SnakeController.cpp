#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Element/ElementService.h"
#include "../../include/Food/FoodService.h"
#include "LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "LinkedListLib/DoubleLinked/DoubleLinkedList.h"

namespace Player
{
	SnakeController::SnakeController()
	{
		linked_list = nullptr;
		//createLinkedList();
	}
	SnakeController::~SnakeController()
	{
		delete(linked_list);
	}
	void SnakeController::initializeLinkedList()
	{
		float width = Global::ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = Global::ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();
		linked_list->initialize(width, height, default_position, default_direction);
	}
	void SnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
			return;

		Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
		if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
	}
	void SnakeController::updateSnakeDirection()
	{
		linked_list->updateNodeDirection(current_snake_direction);
	}
	void SnakeController::moveSnake()
	{
		linked_list->updateNodePosition();
	}
	void SnakeController::processSnakeCollission()
	{
		processBodyCollission();
		processElementsCollission();
		processFoodCollission();
	}

	void SnakeController::processBodyCollission()
	{
		if (linked_list->processNodeCollission())
		{
			current_snake_state = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);//add snke dead sound
		}
	}

	void SnakeController::processElementsCollission()
	{
		Element::ElementService* element_service = Global::ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementsCollission(linked_list->getNodeHead()))
		{
			current_snake_state = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
		}
	}

	void SnakeController::processFoodCollission()
	{
		Food::FoodService* food_service = Global::ServiceLocator::getInstance()->getFoodService();
		Food::FoodType food_type;

		if (food_service->processFoodCollission(linked_list->getNodeHead(), food_type))
		{
			player_score++;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::PICKUP);

			//food_service->destroyFood();
			OnFoodCollected(food_type);
		}
	}

	void SnakeController::OnFoodCollected(Food::FoodType type)
	{
		switch (type)
		{
		case Food::FoodType::PIZZA:
			//Insert at TAIL
			linked_list->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_TAIL;
			break;

		case Food::FoodType::BURGER:
			//Insert at HEAD
			linked_list->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_HEAD;
			break;

		case Food::FoodType::CHEESE:
			//Insert at MIDDLE
			linked_list->insertNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_MID;
			break;

		case Food::FoodType::APPLE:
			//Delete at HEAD
			linked_list->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_HEAD;
			break;

		case Food::FoodType::MANGO:
			//Delete at MIDDLE
			linked_list->removeNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_MID;
			break;

		case Food::FoodType::ORANGE:
			//Delete at TAIL
			linked_list->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_TAIL;
			break;

		case Food::FoodType::POISON:
			//Delete half nodes
			linked_list->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::DELETE_HALF_LIST;
			break;

		case Food::FoodType::ALCOHOL:
			//Reverse Direction
			current_snake_direction = linked_list->reverse();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REVERSE_LIST;
			break;
		}
	}

	void SnakeController::handleRestart()
	{
		restart_counter += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}
	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.0f;
		restart_counter = 0.0f;
		player_score = 0;
	}
	void SnakeController::createLinkedList(Level::LinkedListType level_type)
	{
		switch (level_type)
		{
		case Level::LinkedListType::SINGLE_LINKED_LIST:
			linked_list = new LinkedListLib::SingleLinked::SingleLinkedList();
			break;
		case Level::LinkedListType::DOUBLE_LINKED_LIST:
			linked_list = new LinkedListLib::DoubleLinked::DoubleLinkedList();
			break;
		}

		initializeLinkedList();
	}
	void SnakeController::delayedUpdate()
	{
		elapsed_duration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollission();

			if (current_snake_state != SnakeState::DEAD)
				moveSnake();
			
			current_input_state = InputState::WAITING;
		}
	}
	
	void SnakeController::initialize()//code from initialize() moved to initializeLinkedList();
	{
		/*
		float width = Global::ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = Global::ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		linked_list->initialize(width, height, default_position, default_direction);
		*/
	}
	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;
		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}
	void SnakeController::render()
	{
		linked_list->render();
	}
	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++) 
		{
			linked_list->insertNodeAtTail();     // Insert nodes at tail to create the initial snake
		}
	}
	void SnakeController::respawnSnake()
	{
		linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}
	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}
	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}
	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return linked_list->getNodesPositionList();
	}
	int SnakeController::getPlayerScore()
	{
		return player_score;
	}
	TimeComplexity SnakeController::getTimeComplexity()
	{
		return time_complexity;
	}
	LinkedListOperations SnakeController::getLastOperation()
	{
		return last_linked_list_operation;
	}
	bool SnakeController::isSnakeDead()
	{
		if (current_snake_state == SnakeState::DEAD)
			return true;

		return false;
	}
}