#include "Enemy.h"

//! @brief method that produces stats for enemies.
/*!
points count +1 kill count for every enemy kill. speed is the move speed for enemy and it is set to 1.
hp max is the max hp a player has and hp is current hp player has. damage is the damage taken by player every time it collides with an enemy.
point is the amount of points (kills) the player has.
*/
void Enemy::enemyStats()
{
	this->pointCount = 1; //+1 kill count for every enemy kill
	this->speed	= 1; //enemy move speed = 1
	this->hpMax	= static_cast<int>(this->pointCount); //max hp
	this->hp = this->hpMax; //hp count
	this->damage = 50; //damage per enemy collision
	this->points = this->pointCount; //points count
}

//! @brief method that makes enemies appear.
/*!
loads the enemy.png sprite in and then sets the texture while resizing the sprite
*/
void Enemy::makeEnemy()
{
    this->texture.loadFromFile("textures/enemy.png"); //loading enemy sprite in
    this->enemySprite.setTexture(this->texture);
	this->enemySprite.scale(0.3f, 0.3f); //resizing enemy sprite
}

//! @brief The enemy class.
/*!
  gets the stats of the enemies then creates of enemy, setting its position to pos_x, pos_y.
*/
Enemy::Enemy(float pos_x, float pos_y)
{
	this->enemyStats(); //call enemy stats then:
	this->makeEnemy(); //creates an enemy
	this->enemySprite.setPosition(pos_x, pos_y); //set enemy position
}

//! @brief Enemy Destructor
/*!
  Default destructor for the Enemy.
*/
Enemy::~Enemy()
{

}

//! @brief gets bounds of enemies
/*!
  global bounds for enemy to make sure they dont go off map
*/
//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds(); //global bounds for enemy to make sure they dont go off map
}

//! @brief get points that enemy gives
/*!
  getter method for points enemy gives per kill
*/
const int & Enemy::getPoints() const
{
	return this->points; //getter method for points enemy gives per kill
}

//! @brief get damages taken from enemies
/*!
  getter method for damage dealt per enemy
*/
const int & Enemy::getDamage() const
{
	return this->damage; //getter method for damage dealt per enemy
}

//! @brief updates enemy position
/*!
  updates enemy by moving sprite dependent on speed
*/
void Enemy::update()
{
	this->enemySprite.move(0.f, this->speed); //updates enemy by moving sprite dependent on speed
}

//! @brief renders the enemy sprite
/*!
  parameter 1 is a renderTarget variable.
  draws the enemy sprite
*/
void Enemy::render(sf::RenderTarget * target)
{
	target->draw(this->enemySprite); //draws the enemy sprite
}
