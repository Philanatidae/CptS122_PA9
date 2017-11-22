#pragma once

#include"GameObject.h"

class Player : public GameObject
{
	public:
		Player();
		void update(std::vector<GameObject*>& gameObjects, const sf::Time& dt);
		void draw(sf::RenderWindow& window);
		const sf::Vector2f& getPosition() const;
		const float& getRotation() const;
		const sf::FloatRect& getBoundingBox() const;

	private:
		sf::RectangleShape _rectShape;

};