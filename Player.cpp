#include "Player.h"
#include <iostream>

/** @brief Get player stats
 *	Sets movement speed of player, attack cooldown of player and hp of player.
 */
void Player::playerStats()
{
	this->movementSpeed = 2.f; //movement speed of player
	this->attackCooldownMax = 10.f; //attack cooldown of player
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 100; //hp of player
	this->hp = this->hpMax;
}

/** @brief Make texture
 *	Loads player sprite from Textures/folder.
 *  @param file to load as a sprite.
 */
void Player::makeTexture()
{
	this->texture.loadFromFile("textures/player.png"); //loads player sprite from Textures/ folder
}

/** @brief Make Sprite
 *	Resize player sprite to (0.3f, 0.3f).
 */
void Player::makeSprite()
{
	sprite.setTexture(this->texture);
	this->sprite.scale(0.3f, 0.3f); //resize player sprite
}

/** @brief Set player in Center
 *	Sets player position to bottom center of the map. Gets local bounds then set its position to bottom center of map.
 *	@param the game window.
 */
void Player::center()
{
	int spriteWidth = (int)this->sprite.getLocalBounds().width;
	int spriteHeight = (int)this->sprite.getLocalBounds().height;
	this->sprite.setPosition(this->window->getSize().x / 2 - spriteWidth / 6, this->window->getSize().y - spriteHeight / 2); //then set its position to bottom center of map
}

/** @brief Player class
 *	Gets the player's stats, then loads the player.png file and turns it into a sprite. then move the sprite.
 *	@param the game window.
 */
Player::Player(sf::RenderWindow * window)
{
    this->window = window;
	this->playerStats();
	this->makeTexture();
	this->makeSprite();
	this->center();
}

/** @brief Player destructor
 *	Default destructor for the Player.
 */
Player::~Player()
{

}

/** @brief Player Posititon
 *	Method that gets position of player.
 */
const sf::Vector2f & Player::getPos() const
{
	return this->sprite.getPosition(); //get position of player
}

/** @brief Boundary of sprite
 *	Method that gets global boundaries of the sprite.
 */
const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

/** @brief Get Hp
 *	Method that gets the player's hp.
 */
const int & Player::getHp() const
{
	return this->hp; //getter method for hp
}

/** @brief Get Max HP
 *	Method that gets the max hp of the player.
 */
const int & Player::getHpMax() const
{
	return this->hpMax; //getter method for max hp
}

/** @brief Set Player Posititon
 *	Method that sets player position using vector.
 *	@param vector postion
 */
void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos); //setter method for position
}

/** @brief Set player Position
 *	Method that sets player position using x y values.
 *	@param float representing directions x and y
 */
void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y); //setter method for position
}

/** @brief Set Hp
 *	Method that sets the player HP.
 *	@param Hp value
 */
void Player::setHp(const int hp)
{
	this->hp = hp; //setter method for hp
}

/** @brief Lose HP
 *	Method that handles the player losing hp. If damaged player loses hp and if hp goes into the negatives just set it to 0.
 *	@param Hp value
 */
void Player::loseHp(const int value)
{
	this->hp -= value; //if damaged player loses hp
	if (this->hp < 0) //if hp goes into the negatives just set it to 0
    {
        this->hp = 0;
    }
}

/** @brief Sprtie Movement
 *	Method that moves the player sprite.
 *	@param float representing directions x and y
 * 	@return True if can attack otherwise false
 */
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY); //moving player sprite
}

/** @brief Can Player Attack
 *	Checks if the player can attack by checking attack Cooldown.
 * 	@return True if can attack otherwise false
 */
const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

/** @brief Update Attack Info
 * 	If the player attacks, update the attack cool down.
 */
void Player::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.05f;
}

/** @brief Update methods
 * 	Calls the update attack method
 */
void Player::update()
{
	this->updateAttack();
}

/** @brief Render player
 * 	Renders the player Sprite
 *	@param Target to render.
 */
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite); //draw the player
}
