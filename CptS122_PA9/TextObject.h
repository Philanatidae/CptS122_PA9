#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <string>

#define TEXT_OBJECT_DEFAULT_TEXT_SIZE 30

/**
A game object for displaying text.
*/
class TextObject : public GameObject {
public:
	/**
	Constructs a new text object.
	@param position Position of the object.
	@param content String content of the text.
	@param color Color of the text (default white).
	@param size Size of the text (default 30).
	*/
	TextObject(const sf::Vector2f& position, const std::string& content, const sf::Color& color = sf::Color::White, const unsigned int& size = TEXT_OBJECT_DEFAULT_TEXT_SIZE);

	/**
	Updates the object.
	@param gameObjects Global list of game objects.
	@param dt Time since last frame (change in time since last frame).
	*/
	void update(std::set<GameObject*>& gameObjects, const sf::Time& dt);
	/**
	Draws the object to the window.
	@param window SFML Window to draw to.
	*/
	void draw(sf::RenderWindow& window);

	/**
	Returns the position of the object.
	@return Position of the object.
	*/
	const sf::Vector2f& getPosition() const;
	/**
	Returns the rotation of the object, in degrees.
	@return Rotation of the object.
	*/
	const float& getRotation() const;
	/**
	Returns the bounding box of the object for collision
	detection.
	@return Bounding box of the object.
	*/
	sf::FloatRect getBoundingBox() const;

	/**
	Returns the current string content in the text object.
	@return String content in the text object.
	*/
	const std::string& getContent() const;
	/**
	Sets the string content within the text object.
	@param content String content to set the text object to.
	*/
	void setContent(const std::string& content);

private:
	sf::Text _textEntity;
	sf::Font _font; // Not ideal b/c it loads the font every time
};