#include "Game.h"
#include "Menu.h"
#include <iostream>
#include <string>

//! @brief make the textures
/*!
 *  loads kunai texture from Textures/ folder
 */
void Game::makeTextures()
{
	this->textures["wep"] = new sf::Texture();
	this->textures["wep"]->loadFromFile("textures/laser.png");
}

//! @brief all of the GUI functions for the game
/*!
 * loads the consola font, sets default point text to show Kill Count
 * displays hp prompt at bottom left of the screen and hp bar set to bottom left of screen
 */
void Game::GUIFunctions()
{
	this->font.loadFromFile("Fonts/consola.ttf");
	this->pointText.setPosition(10.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(20);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Kill Count: ");
    this->hpText.setPosition(3.f, 650.f);
	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(20);
	this->hpText.setFillColor(sf::Color::White);
	this->hpText.setString("HP:");
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Green);
	this->playerHpBar.setPosition(sf::Vector2f(25.f, 650.f));
	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
	this->levelText.setFont(this->font);
	this->levelText.setCharacterSize(60);
	this->levelText.setFillColor(sf::Color::Green);
	this->levelText.setString("Level");
}

//! @brief makes the world
/*!
 *  loads background image from Textures/ folder
 */
void Game::makeWorld()
{
	this->worldBackgroundTex.loadFromFile("Textures/background.png");
	this->worldBackground.setTexture(this->worldBackgroundTex);
}

//! @brief the points system
/*!
 *  sets points to 0 whenever game is started
 */
void Game::pointsSystem()
{
	this->points = 0;
}

//! @brief level system of the game
/*!
 *  default level of the game
 */
void Game::initLevel()
{
	this->level = 1;
	this->enemyNum = 1;
	this->maxLevel = 3;
	std::string levelString = std::to_string(this->level);
	this->levelText.setString("Level " + levelString);
	this->levelText.setPosition(this->window->getSize().x / 2 - this->levelText.getGlobalBounds().width / 2, this->window->getSize().y / 2 - this->levelText.getGlobalBounds().height / 2);
	this->window->draw(this->levelText);
}

//! @brief new level of the game
/*!
 *  increment games level by one and increase enemy level
 */
void Game::newLevel()
{
    this->points = 0;
	this->level += 1;
	this->enemyNum += 1;
	std::string levelString = std::to_string(this->level);
	this->levelText.setString("Level " + levelString);
	this->levelText.setPosition(this->window->getSize().x / 2 - this->levelText.getGlobalBounds().width / 2, this->window->getSize().y / 2 - this->levelText.getGlobalBounds().height / 2);
	this->window->draw(this->levelText);
	this->player->center();
}

//! @brief makes the player
/*!
 *  creates the player
 */
void Game::makePlayer()
{
	this->player = new Player(this->window);
}

//! @brief spawns the enemies
/*!
 *  sets the spawn timer
 */
void Game::spawnEnemies()
{
	this->spawnTimerMax = 250.f;
	this->spawnTimer = this->spawnTimerMax;
}

//! @brief game method
/*!
 *  makes the window, then loads the weapon textures, then loads the gui functions,then sets the background image
 * then sets kill count = 0, then makes the player, then makes the player and finally spawns enemies
 *  @param window
 */
Game::Game(sf::RenderWindow *window)
{
    this->window = window;
	this->makeTextures();
	this->GUIFunctions();
	this->makeWorld();
	this->pointsSystem();
	this->makePlayer();
	this->spawnEnemies();
	this->initLevel();

    laser_buff.loadFromFile("sound/laser8.wav");
    laser_wav.setBuffer(laser_buff);

    explo_buff.loadFromFile("sound/explosion.wav");
    explo_wav.setBuffer(explo_buff);
}

//! @brief deleting game data
/*!
 *  deletes all data once game is over: textures, enemies
 */
Game::~Game()
{
	delete this->window;
	delete this->player;
	for (auto &i : this->textures)
	{
		delete i.second;
	}
	for (auto *i : this->kunais)
	{
		delete i;
	}
	for (auto *i : this->enemies)
	{
		delete i;
	}
}

//! @brief updates the game
/*!
 *  arrow keys for moving up, left, down, right, spacebar click for attack
 */
void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->kunais.push_back(new Weapon(this->textures["wep"],this->player->getPos().x + this->player->getBounds().width/2.f,this->player->getPos().y,0.f,-1.f,5.f));
        laser_wav.play();
	}
}

//! @brief updates the GUI
/*!
 *  updates points count gui and hp gui
 */
void Game::updateGUI()
{
	std::stringstream displayText;
	displayText << "Kill Count: " << this->points;
	this->pointText.setString(displayText.str());
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

//! @brief updates the collision
/*!
 *  consists of leftmost boundary, rightmost boundary, top boundary, bottom boundary
 */
void Game::updateCollision()
{
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}

/** @brief Update Weapon
 *	This method destory the laser when it reachs above the top of the screan.
 */
void Game::updateWeapon()
{
	unsigned counter = 0;
	for (auto *kunai : this->kunais)
	{
		kunai->update();
		if (kunai->getBounds().top + kunai->getBounds().height < 0.f)
		{
			delete this->kunais.at(counter); //removes the weapon once it has reached the top
			this->kunais.erase(this->kunais.begin() + counter);
		}
        counter = counter + 1;
	}
}

/** @brief Update Enemies
 *	This method spawns new enemies and destory enemies when hit by the laser.
 */
void Game::updateEnemies()
{
	this->spawnTimer += 0.5f; //spawn timer for enemies
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x-20.f, -100.f)); //spawns enemies
		this->spawnTimer = 0.f;
	}
	unsigned counter = 0;
	for (auto *enemy : this->enemies)
	{
		enemy->update();
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			delete this->enemies.at(counter); //deletes the enemy once it hits the bottom
			this->enemies.erase(this->enemies.begin() + counter);
		}
		else if(enemy->getBounds().intersects(this->player->getBounds())) //if enemy hits the player
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage()); //player loses hp
			delete this->enemies.at(counter); //enemy is removed
			this->enemies.erase(this->enemies.begin() + counter);
			explo_wav.play();
		}
        counter = counter + 1;
	}
}

/** @brief Update Combat
 *	This method checks if player's hit enemies.
 *  When player's hit enemies, destory the laser and update the score.
 */
void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->kunais.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->kunais[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints(); //adds points
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
				delete this->kunais[k]; //deletes the weapon
				this->kunais.erase(this->kunais.begin() + k);
				enemy_deleted = true;
				explo_wav.play();
			}
		}
	}
}

/** @brief Update
 *	This method is call every game loop.
 *  This method calls all other update method in this class to update everything.
 *  @return -1 if the player died.
 *  @return 1 if the player wins.
 *  @return 0 if the player has not won or died.
 */
int Game::update()
{
    //continues to update world as long as player is alive or has not won
    if(this->player->getHp() > 0 && this->points != this->enemyNum) {
        this->updateInput();
        this->player->update();
        this->updateCollision();
        this->updateWeapon();
        this->updateEnemies();
        this->updateCombat();
        this->updateGUI();
    }

    this->window->clear();
	this->renderWorld(); //draws the world
	this->player->render(*this->window);
	for (auto *kunai : this->kunais)
	{
		kunai->render(this->window);
	}
	for (auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	this->renderGUI();

	if (this->player->getHp() <= 0) { //if player's hp is 0 then draws the game over screen
        this->window->display();
        return -1;
	} else if (this->points == this->enemyNum && this->level == this->maxLevel) { //if kill count is 5 then draws the win screen
        this->window->display();
        return 1;
    } else if (this->points == this->enemyNum && this->level != this->maxLevel) {
        this->newLevel();
        this->window->display();
        sf::sleep(sf::seconds(1));
        return 0;
    } else {
        this->window->display();
        return 0;
    }

}

/** @brief Render GUI
 *	Draw all the GUI like hit point, score points, and etc.
 */
void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->hpText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

/** @brief Render World
 *	Draw the background sprite of the game world.
 */
void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}
