#include "Menu.h"
#include "Button.h"
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

<<<<<<< HEAD
//! @brief Generate a menu for the game.
/*!
Generates the game window, loads the font. Loads in button width and height with play button, how to play button and quit button.
Load in the sound files and play them. Set default volume.
=======
/*! constructor
* \param window - window of the game
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
*/
Menu::Menu(sf::RenderWindow * window){
	sf::Font font;
    font.loadFromFile("fonts/consola.ttf");
    // define the GUI of the menu
    this->window = window;
	this->font = font;
	this->borderColor = sf::Color::Black;
	this->titleFontSize = 70;
	this->bodyFontSize = 35;
	this->borderWidth = 5;
	this->titleYPosition = 100;
	this->buttonHeight = 80;
	this->buttonWidth = 300;
    // 4 options that menu displays 
	this->playButton = Button();
	this->howToPlayButton = Button();
	this->backButton = Button();
	this->quitButton = Button();
    // load sound of the game 
	click_buff.loadFromFile("sound/bzzzt.wav");
	click_wav.setBuffer(click_buff);

	tense.openFromFile("sound/tense.flac");
    tense.setVolume(50);
    sonata.openFromFile("sound/sonata.flac");
    sonata.setVolume(50);
    lose.openFromFile("sound/lose.flac");
    lose.setVolume(50);
}

<<<<<<< HEAD
//! @brief Draw a title.
/*! 
 *  given font and font size, generate title, set position outline color, and outline thickness.
 *	Then draw the title to the window.
 *  @param Font and Font Size
 */
=======
// defind title of the game 
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::drawTitle( std::string titleText) {
    sf::Text title(titleText, this->font, this->titleFontSize);
    int titleWidth = (int)title.getLocalBounds().width;
    // set position 
    title.setPosition(this->window->getSize().x / 2 - titleWidth / 2, this->titleYPosition);
    // define color
    title.setOutlineColor(this->borderColor);
    title.setOutlineThickness(this->borderWidth);
    this->window->draw(title);
}

//! @brief Draw body text
/*! 
 *  given font and font size, generate title, set position outline color, and outline thickness.
 *	Then draw the body text to the window.
 *  @param Font and Font Size
 */
void Menu::drawText(std::string bodyText, int yPosition) {
    sf::Text body(bodyText, this->font, this->bodyFontSize);
    int bodyWidth = (int)body.getLocalBounds().width;
    body.setPosition(this->window->getSize().x / 2 - bodyWidth / 2, yPosition);
    body.setOutlineColor(this->borderColor);
    body.setOutlineThickness(this->borderWidth);
    this->window->draw(body);
}

<<<<<<< HEAD
//! @brief Draw a title.
/*! 
 *  generate texture for the background image. Load the image using image location parameter. 
 *  Generate sprite of the image. Draw it to the window as baclground.
 *  @param image location
 */
=======
// display background of the game 
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::drawBackground(std::string imageLocation) {
    sf::Texture backgroundImage;
    backgroundImage.loadFromFile(imageLocation);
    sf::Sprite background(backgroundImage);
    this->window->draw(background);
}

//! @brief Draw a title.
/*! 
 *  generate texture for the background image. Load the image using image location parameter. 
 *  Generate sprite of the image. Draw it to the window as baclground.
 *  @param image location
 */
Button Menu::drawButton(std::string text, int yPosition) {
    int xCenter = this->window->getSize().x / 2 - this->buttonWidth / 2;
    Button button(text, this->buttonHeight, this->buttonWidth, xCenter, yPosition);
    button.draw(this->window);
    return button;
}
<<<<<<< HEAD

//! @brief Displayh main menu.
/*! 
 *  generate title text and background  
 *  Draw background, title and the play, hot to play and exit buttons.
 */
=======
// display main menu
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::displayMain(){
    this->clear();
    std::string titleText = "Space War";
    std::string backgroundLocation = "textures/menu.png";

    this->drawBackground(backgroundLocation);
    this->drawTitle(titleText);
    // start-the-game option
    this->playButton = this->drawButton("Play", 300);
    // how-to-play menu 
    this->howToPlayButton = this->drawButton("How To Play", 400);
    this->quitButton = this->drawButton("Quit", 500);
    this->window->display();
    tense.play();
}
<<<<<<< HEAD

//! @brief How to play menu.
/*! 
 *  Shows info of the how to menu option.
 *  Has a back button to go back to main menu.
 */
=======
// display how-to menu 
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::displayHowTo(){
    this->clear();
    // text to explain how to play the game 
    std::string titleText = "How To Play";
    std::string howToText[4] = {"- Use arrow keys to move",
                                "- Use spacebar to shooting",
                                "- Don't let enemies hit you",
                                "- Destroy enough enemies to win the game"};
    std::string backgroundLocation = "textures/menu.png";

    int howToTextYPosition = 200;

    this->drawBackground(backgroundLocation);
    this->drawTitle(titleText);
    for (int i = 0; i < 4; i++) {
        this->drawText(howToText[i], howToTextYPosition);
        howToTextYPosition += 100;
    }
    this->backButton = this->drawButton("Back", 600);
    this->window->display();
}
<<<<<<< HEAD

//! @brief Death screen.
/*! 
 *  Load in text to show alert for game over.
 *  Has a play again button to start over.
 */
=======
// display loss screen 
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::displayDeath(){
    this->clear();
    std::string titleText = "You Dead!";
    std::string backgroundLocation = "textures/death.png";

    this->drawBackground(backgroundLocation);
    this->drawTitle(titleText);
    // play again 
    lose.play();
    this->playButton = this->drawButton("Play Again", 300);
    this->window->display();
}

<<<<<<< HEAD
//! @brief End screen.
/*! 
 *  Load in text to show alert for game over.
 *  Loads in credits when you win the game.
 */
=======
// display the end screen 
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::displayEnd(){

    this->clear();
    std::string titleText = "Thank You For Playing";
    std::string madeByText = "Made by: ";
    std::string teamMembers[5] = {"Danish Amrohi", "Jadd Miguel Arriola", "Jacky Liu", "Ivan Zhang", "Zeyu Zhang"};
    std::string backgroundLocation = "textures/menu.png";

    int teamMembersTextYPosition = 280;
    this->drawBackground(backgroundLocation);
    this->drawTitle(titleText);
    this->drawText(madeByText, 200);
    for (int i = 0; i < 5; i++) {
        this->drawText(teamMembers[i], teamMembersTextYPosition);
        teamMembersTextYPosition += 50;
    }
    sonata.play();
    this->quitButton = this->drawButton("Quit", 600);

    this->window->display();
}

<<<<<<< HEAD
//! @brief clear the window.
/*! 
 *  clears up the window on call.
 */
=======
// clearn the menu 
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
void Menu::clear(){
    this->playButton = Button();
	this->howToPlayButton = Button();
	this->backButton = Button();
	this->quitButton = Button();
	this->window->clear();
}

<<<<<<< HEAD
//! @brief Update window.
/*! 
 *  Checks for if the buttons are clicked anbd updates accordingly
 */
=======
// update the status of the game based on which option the player chooses from the menu
>>>>>>> 9bc70c9d944b4ada36836cf850456688603bef91
bool Menu::update(){
    // if play option is chosen, play the sound and return true 
    if (this->playButton.isMouseClicked(this->window)) {
        tense.stop();
        lose.stop();
        click_wav.play();
        this->window->clear();
        return true;
    // if how-to-paly option is chosen, play the sound and display how-to menu 
    } else if (this->howToPlayButton.isMouseClicked(this->window)) {
        click_wav.play();
        this->displayHowTo();
    // if back option is chosen, play the sound and display main menu 
    } else if (this->backButton.isMouseClicked(this->window)) {
        click_wav.play();
        this->displayMain();
    // if quit option is chosen, close the window  
    } else if (this->quitButton.isMouseClicked(this->window)) {
        this->window->close();
    }
    return false;
}
