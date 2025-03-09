#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"

namespace Player
{
	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}
	SnakeController::~SnakeController()
	{
		delete(single_linked_list);
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
		single_linked_list->updateNodeDirection(current_snake_direction);
	}
	void SnakeController::moveSnake()
	{
		single_linked_list->updateNodePosition();
	}
	void SnakeController::processSnakeCollission()
	{
		processBodyCollission();
		processElementsCollission();
		processFoodCollission();
	}

	void SnakeController::processBodyCollission()
	{
		if (single_linked_list->processNodeCollission())
		{
			current_snake_state = SnakeState::DEAD;
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);//add snke dead sound
		}
	}

	void SnakeController::processElementsCollission()
	{
	}

	void SnakeController::processFoodCollission()
	{
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
	}
	void SnakeController::createLinkedList()
	{
		single_linked_list = new LinkedList::SingleLinkedList();
		current_snake_state = SnakeState::ALIVE;
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
	
	void SnakeController::initialize()
	{
		float width = Global::ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = Global::ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
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
		single_linked_list->render();
	}
	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++) 
		{
			single_linked_list->insertNodeAtTail();     // Insert nodes at tail to create the initial snake
		}
	}
	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllNodes();
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
		return single_linked_list->getNodesPositionList();
	}
}