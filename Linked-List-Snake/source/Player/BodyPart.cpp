#include "../../include/Player/BodyPart.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"
#include "../../include/Level/LevelModel.h"
#include <iostream>

namespace Player
{
	
	BodyPart::BodyPart()
	{
		bodypart_image = nullptr;
		createBodyPartImage();

		grid_position = sf::Vector2i(0, 0);
	}
	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new UI::UIElement::ImageView();
	}
	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Global::Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}
	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = Level::LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = Level::LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}
	float BodyPart::getRotationAngle()
	{
		switch (direction)
		{
		case Direction::UP:
			return 270.f;
		case Direction::DOWN:
			return 90.f;
		case Direction::RIGHT:
			return 0;
		case Direction::LEFT:
			return 180.f;
		}
	}
	sf::Vector2i BodyPart::getNextPositionUp()
	{
		return sf::Vector2i(grid_position.x, (grid_position.y - 1 + (Level::LevelModel::number_of_rows)) % (Level::LevelModel::number_of_rows));
	}
	sf::Vector2i BodyPart::getNextPositionDown()
	{
		return sf::Vector2i(grid_position.x, (grid_position.y + 1) % (Level::LevelModel::number_of_rows));
	}
	sf::Vector2i BodyPart::getNextPositionLeft()
	{
		return sf::Vector2i((grid_position.x - 1 + Level::LevelModel::number_of_columns+1) % (Level::LevelModel::number_of_columns+1), grid_position.y);
	}
	sf::Vector2i BodyPart::getNextPositionRight()
	{
		return sf::Vector2i((grid_position.x + 1) % (Level::LevelModel::number_of_columns+1), grid_position.y);
	}
	sf::Vector2i BodyPart::getNextPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return getNextPositionUp();
			break;
		case Direction::DOWN:
			return getNextPositionDown();
			break;
		case Direction::LEFT:
			return getNextPositionLeft();
			break;
		case Direction::RIGHT:
			return getNextPositionRight();
			break;
		default:
			return grid_position;
			break;
		}
	}
	Direction BodyPart::getDirection()
	{
		return direction;
	}
	sf::Vector2i BodyPart::getPosition()
	{
		return grid_position;
	}
	sf::Vector2i BodyPart::getPrevPosition()
	{
		switch (direction)
		{
		case Direction::UP:
			return getNextPositionDown();
		case Direction::DOWN:
			return getNextPositionUp();
		case Direction::RIGHT:
			return getNextPositionLeft();
		case Direction::LEFT:
			return getNextPositionRight();
		default:
			return grid_position;
		}
	}
	Direction BodyPart::getPreviousDirection()
	{
		return previous_direction;
	}
	BodyPart::~BodyPart()
	{
		delete(bodypart_image);
	}
	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		direction = dir;
		grid_position = pos;

		std::cout << "Inside body part.cpp initialize"<< std::endl;
		std::cout << "Body part width is " << bodypart_width << std::endl;
		std::cout << "Body part height is " << bodypart_height << std::endl;

		initializeBodyPartImage();
	}
	void BodyPart::updatePosition()//updates position, rotation 
	{
		grid_position = getNextPosition();
		
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->update();
	}
	void BodyPart::render()
	{
		std::cout << "Body part images width = " << bodypart_width << std::endl;
		std::cout << "Body part images height = " << bodypart_height << std::endl;
		bodypart_image->render();
	}
	void BodyPart::setDirection(Direction dir)
	{
		previous_direction = this->direction;
		this->direction = dir;
	}
	void BodyPart::setPosition(sf::Vector2i pos)
	{
		grid_position = pos;
	}
}