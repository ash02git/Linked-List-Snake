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

		void createBodyPartImage();
		void initializeBodyPartImage();

		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void updatePosition();
		void render();

		void setDirection(Direction dir);
	};
}