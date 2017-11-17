#include "TestCircle.h"

TestCircle::TestCircle(const float& radius)
	:_circleShape(radius) {
	_circleShape.setFillColor(sf::Color::Green);
}

void TestCircle::update(std::vector<GameObject*>& gameObjects, const sf::Time& dt) {
	_elapsedTime += dt.asSeconds();
	_circleShape.setPosition(100 * sin(_elapsedTime) + 100, 100);
}
void TestCircle::draw(sf::RenderWindow& window) {
	window.draw(_circleShape);
}

const sf::Vector2f& TestCircle::getPosition() const {
	return _circleShape.getPosition();
}
const float& TestCircle::getRotation() const {
	return _circleShape.getRotation();
}
const sf::FloatRect& TestCircle::getBoundingBox() const {
	return _circleShape.getGlobalBounds();
}