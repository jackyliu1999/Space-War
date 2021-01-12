/** @brief Button class
 *	Since SFML does not have buttons, this class is just a text in the center of a shape that have an effect when click.
 */
#include "Button.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

/** @brief Button
 *	Default button class with empty param.
 */
Button::Button(){
    this->isDrawed = false;
}

/** @brief Button
 *	Button class with 5 param that initize the text, style and position of the button.
 * @param the text string in center of the button, dimension, and postion.
 */
Button::Button(std::string textString, int height, int width, int xPosition, int yPosition){
    sf::Font font;
    font.loadFromFile("fonts/consola.ttf");

    this->backgoundColor = sf::Color::Blue;
	this->textColor = sf::Color::White;
	this->font = font;
	this->fontSize = 50;
	this->textString = textString;
	this->height = height;
	this->width = width;
	this->xPosition = xPosition;
	this->yPosition = yPosition;
}

/** @brief Draw
 *	Draw the button based on dimension, postion, text given.
 * @param the app window
 */
void Button::draw(sf::RenderWindow * window) {
    sf::RectangleShape shape(sf::Vector2f(this->width, this->height));
    shape.setFillColor(this->backgoundColor);
    shape.setPosition(this->xPosition, this->yPosition);
    sf::Text text(textString, this->font, this->fontSize);
    int textHeight = (int)text.getLocalBounds().height;
    int textWidth = (int)text.getLocalBounds().width;
    text.setFillColor(this->textColor);
    text.setPosition(this->xPosition + (this->width - textWidth) / 2, this->yPosition + (this->height - textHeight) / 6);

    window->draw(shape);
    window->draw(text);
    this->isDrawed = true;
}

/** @brief Is Mouse Clicked
 *	Check if user has clicked on this button.
 *  @param the app window
 */
bool Button::isMouseClicked(sf::RenderWindow * window) {

    int mouseXPosition = (int)sf::Mouse::getPosition(*window).x;
    int mouseYPosition = (int)sf::Mouse::getPosition(*window).y;

    bool isBetweenX = this->xPosition < mouseXPosition && mouseXPosition < (this->xPosition + this->width);
    bool isBetweenY = this->yPosition < mouseYPosition && mouseYPosition < (this->yPosition + this->height);
    return this->isDrawed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && isBetweenX && isBetweenY;
}
