#ifndef WEAPON_H
#define WEAPON_H
#include<SFML/Graphics.hpp>
#include<iostream>

/*! Weapon class
* \brief this file contains Weapon class which defines the position and status of the weapon  

* this class includes functions that define the position and boundary of the weapon 
* and also update the position of the weapon
*/
class Weapon
{
public:
	Weapon();
	/*! constructor
	* \param texture
	* \param pos_x - position of the weapon on x axis
	* \param pos_y - position of the weapon on y axis
	* \param dir_x - direction of the weapon on x axis
	* \param dir_y - direction of the weapon on y axis
	* \param movement_speed - speed of weapon movement 
	*/
	Weapon(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	/*! deconstructor
	*/
	virtual ~Weapon();
	/*! get the boundary of the weapon on the map 
	* \return the boudary on the map
	*/
	const sf::FloatRect getBounds() const;
	/*! update position of the weapon 
	*/
	void update();
	/*! define GUI when the character draws the weapon
	* \param target - the target of the weapon
	*/
	void render(sf::RenderTarget* target);
private:
	sf::Sprite shape;
	sf::Vector2f direction;
	float movementSpeed;
};

#endif // !Weapon_H

