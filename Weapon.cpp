#include "Weapon.h"

/** @brief Weapon default constructor
 *	Default Constructor
 */
Weapon::Weapon() //default Weapon
{

}

/** @brief Weapon class constructor
 *	Gets the weapons's texture, position, direction and movement Speed.
 *	@param Weapon texture, x and y position, x and y direction, movement speed.
 */
Weapon::Weapon(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

/** @brief Weapon destructor
 *	Default destructor for the Weapon.
 */
Weapon::~Weapon()
{

}

/** @brief Weapon boundary
 *	Gives map boundary for the weapon
 *  @return Boundary for weapon
 */
const sf::FloatRect Weapon::getBounds() const
{
	return this->shape.getGlobalBounds(); //getting map boundary for weapon
}

/** @brief Weapon movement
 *	Gives movement speed and direction for the weapon.
 */
void Weapon::update()
{
	this->shape.move(this->movementSpeed * this->direction); //move weapon
}

/** @brief Draws the weapon
 * 	@param Render target
 *	Render the weapon using target
 */
void Weapon::render(sf::RenderTarget * target)
{
	target->draw(this->shape); //draws the weapon
}
