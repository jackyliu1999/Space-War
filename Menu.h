#ifndef MENU_H
#define MENU_H
#include "Button.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*! Menu class
* \brief this file contains Menu class which defines options of the menu 

* this class includes functions that define response to option including "Play", "How To Play" and "Quit"
*/
class Menu{
    private:
        sf::RenderWindow * window;
        sf::Font font;
        sf::Color borderColor;
        int titleFontSize;
        int bodyFontSize;
        int borderWidth;
        int titleYPosition;
        int buttonHeight;
        int buttonWidth;
        Button playButton;
        Button howToPlayButton;
        Button backButton;
        Button quitButton;
        void drawTitle(std::string titleText);
        void drawText(std::string bodyText, int yPosition);
        void drawBackground(std::string imageLocation);
        Button drawButton(std::string text, int yPosition);
        sf::SoundBuffer click_buff;
        sf::Sound click_wav;
        sf::Music tense;
        sf::Music sonata;
        sf::Music lose;

    public:
        /*! constructor
        * \param window - window of the game
        */
        Menu(sf::RenderWindow * window);
        /*! define GUI of main menu
        */
        void displayMain();
        /*! define "How to Play" option
        * explain how to control the game and how to end the game
        */
        void displayHowTo();
        /*! define the menu after the character is killed
        * the function includes option to restart the game and end the game 
        */
        void displayDeath();
        /*! define the menu after the player wins the game 
        * the function includes option to restart the game and end the game 
        */
        void displayEnd();
        /*! 
        * the function defines the option to quite the game 
        */
        void clear();
        /*! 
        * the function defines reponse based on which option player choooses  
        * \return True: if player clicks the mouse , False: if player does not clicks the mouse
        */
        bool update();
};
#endif MENU_H

