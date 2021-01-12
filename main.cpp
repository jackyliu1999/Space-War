#include "Menu.h"
#include <SFML/Graphics.hpp>

/** @brief Main Function
 *	This function first creates the main window.
 *  This function runs in a loop to keep the app open.
 *  Displays the menu at first, switchs to game when the player clicks play.
 */
int main()
{
    // Create the main window
    sf::RenderWindow* app = new sf::RenderWindow(sf::VideoMode(1000, 750), "Space War");

    app->setFramerateLimit(144); //setting max frame rate to 144
	app->setVerticalSyncEnabled(false); //disables vertical sync to maximize game performance

	bool isGameRunning = false;
    Menu* menu = new Menu(app);
    app->clear();
    menu->displayMain();
    srand(static_cast<unsigned>(time(0)));
    Game* game = new Game(app);

	// Start the game loop
    while (app->isOpen())
    {

        // Process events
        sf::Event event;
        while (app->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app->close();

        }
        if (isGameRunning == false && menu->update() == true){
            isGameRunning = true;
        } else if (isGameRunning == true) {
            int status = game->update();
            if (status == 1) {
                menu->displayEnd();
                isGameRunning = false;
            } else if (status == -1) {
                menu->displayDeath();
                isGameRunning = false;
                game = new Game(app);
            }
        }
    }
}
