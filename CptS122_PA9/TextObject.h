#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <string>

#define TEXT_OBJECT_DEFAULT_TEXT_SIZE 30

class TextObject : public GameObject {
public:
	TextObject(const sf::Vector2f& position, const std::string& content, const sf::Color& color = sf::Color::White, const unsigned int& size = TEXT_OBJECT_DEFAULT_TEXT_SIZE);

	void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
	void draw(sf::RenderWindow& window);

	const sf::Vector2f& getPosition() const;
	const float& getRotation() const;
	sf::FloatRect getBoundingBox() const;

	const std::string& getContent() const;
	void setContent(const std::string& content);

private:
	sf::Text _textEntity;
	sf::Font _font; // Not ideal b/c it loads the font every time
};