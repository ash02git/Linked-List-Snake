#pragma once
#include "../../include/UI/UIElement/ImageView.h"
#include "Direction.h"

namespace Player
{
	class BodyPart
	{
	private:
		UI::UIElement::ImageView* bodypart_image;
		sf::Vector2i grid_position;
		Direction direction;
		float bodypart_width;
		float bodypart_height;

		Direction previous_direction;

		void createBodyPartImage();
		void initializeBodyPartImage();

		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();

		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionRight();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void updatePosition();
		void render();

		void setDirection(Direction dir);
		void setPosition(sf::Vector2i pos);

		sf::Vector2i getNextPosition();

		Direction getDirection();
		sf::Vector2i getPosition();

		sf::Vector2i getPrevPosition();

		Direction getPreviousDirection();

	};
}