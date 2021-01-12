#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

/*! Player class
* \brief this file contains Player class which defines functionalities and status of the player  

* this class includes functions that define the position and boundary of the weapon 
* and also update the position of the weapon
*/
class Player
{
public:
	/*! constructor
	* \param window - window of the game 
	*/
	Player(sf::RenderWindow * window);
	/*! deconstructor
	*/
	virtual ~Player();
	/*! get updated position of the character
	* \return the position of the character on the map
	*/
	const sf::Vector2f& getPos() const;
	/*! get limitation of where the character can move on the map
	* \return the boundary of the character on the map
	*/
	const sf::FloatRect getBounds() const;
	/*! get updated HP of the character
	* \return the HP of the character
	*/
	const int& getHp() const;
	/*! get maximum HP of the character
	* \return maximum HP of the character
	*/
	const int& getHpMax() const;
	/*! set the position of the character
	*/
	void setPosition(const sf::Vector2f pos);
	/*! set the position of the character based on x and y axis
	* \param x - position of character on x axis
	* \param y - position of character on y axis
	*/
	void setPosition(const float x, const float y);
	/*! set the hp of the character 
	* \param hp - hp of the character in integer
	*/
	void setHp(const int hp);
	/*! set the hp that the character lost
	* \param value - hp of the character in integer
	*/
	void loseHp(const int value);
	/*! set the direction that character moves towards
	* \param dirX - direction on x axis
	* \param dirY - direction on y axis
	*/
	void move(const float dirX, const float dirY);
	/*! get whether the character can attack
	* \return True: if character can attack; False: if character cannot attack
	*/
	const bool canAttack();
	/*! update attack status of the character 
	*/
	void updateAttack();
	/*! call function updateAttack() to update attack status  
	*/
	void update();
	/*! set position of the character to the center of the map  
	*/
	void center();
	/*! draw the player  
	*/
	void render(sf::RenderTarget& target);
private:
    sf::RenderWindow * window;
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;
	int hp;
	int hpMax;
	void playerStats();
	void makeTexture();
	void makeSprite();

};

