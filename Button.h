#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <SFML/Graphics.hpp>

/*! Button class
* \brief this file contains Button class which defines outlook and properties of a button

* this class includes functions that define GUI of the button and also checks whether user clicks the button
*/
class Button{
    private:
        bool isDrawed;
        sf::Color backgoundColor;
        sf::Color textColor;
        sf::Font font;
        int fontSize;
        std::string textString;
        int height;
        int width;
        int xPosition;
        int yPosition;
    public:
        Button();
        /*! 
        * \brief constructor of Button class
        * \param textString - text shown on the button
        * \param height - height of the button
        * \param width - width of the button
        * \param xPosition - position of the button on x axis
        * \param yPosition - position of the button on y axis
        */
        Button(std::string textString, int height, int width, int xPosition, int yPosition);
       /*! 
        * create window for the button
        * \param window - size of the window
        */
        void draw(sf::RenderWindow * window);
        /*! 
        * check whether the player clicks the mouse
        * \param window - window of the button
        * \return True: if the player clicks the mouse; Flase: if the player does not click the mouse
        */
        bool isMouseClicked(sf::RenderWindow * window);
};

#endif BUTTON_H
