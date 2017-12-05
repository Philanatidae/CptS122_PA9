#include "TextObject.h"

TextObject::TextObject(const sf::Vector2f& position, const std::string& content, const sf::Color& color, const unsigned int& size) {
	_textEntity.setPosition(position);
	_textEntity.setString(content);
	_textEntity.setCharacterSize(size);
	_textEntity.setColor(color);

	_font.loadFromFile("Roboto-Regular.ttf");
	_textEntity.setFont(_font);
}

void TextObject::update(std::set<GameObject*>& gameObjects, const sf::Time& dt) {
}
void TextObject::draw(sf::RenderWindow& window) {
	window.draw(_textEntity);
}

const sf::Vector2f& TextObject::getPosition() const {
	return _textEntity.getPosition();
}
const float& TextObject::getRotation() const {
	return _textEntity.getRotation();
}
sf::FloatRect TextObject::getBoundingBox() const {
	return _textEntity.getGlobalBounds();
}

const std::string& TextObject::getContent() const {
	return _textEntity.getString();
}
void TextObject::setContent(const std::string& content) {
	_textEntity.setString(content);
}