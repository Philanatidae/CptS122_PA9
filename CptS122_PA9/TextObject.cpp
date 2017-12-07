#include "TextObject.h"

/**
Constructs a new text object.
@param position Position of the object.
@param content String content of the text.
@param color Color of the text (default white).
@param size Size of the text (default 30).
*/
TextObject::TextObject(const sf::Vector2f& position, const std::string& content, const sf::Color& color, const unsigned int& size) {
	_textEntity.setPosition(position);
	_textEntity.setString(content);
	_textEntity.setCharacterSize(size);
	_textEntity.setColor(color);

	_font.loadFromFile("Roboto-Regular.ttf");
	_textEntity.setFont(_font);
}

/**
Updates the object.
@param gameObjects Global list of game objects.
@param dt Time since last frame (change in time since last frame).
*/
void TextObject::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {
}
/**
Draws the object to the window.
@param window SFML Window to draw to.
*/
void TextObject::draw(sf::RenderWindow& window) {
	window.draw(_textEntity);
}

/**
Returns the position of the object.
@return Position of the object.
*/
const sf::Vector2f& TextObject::getPosition() const {
	return _textEntity.getPosition();
}
/**
Returns the rotation of the object, in degrees.
@return Rotation of the object.
*/
const float& TextObject::getRotation() const {
	return _textEntity.getRotation();
}
/**
Returns the bounding box of the object for collision
detection.
@return Bounding box of the object.
*/
sf::FloatRect TextObject::getBoundingBox() const {
	return _textEntity.getGlobalBounds();
}

/**
Returns the current string content in the text object.
@return String content in the text object.
*/
const std::string& TextObject::getContent() const {
	return _textEntity.getString();
}
/**
Sets the string content within the text object.
@param content String content to set the text object to.
*/
void TextObject::setContent(const std::string& content) {
	_textEntity.setString(content);
}