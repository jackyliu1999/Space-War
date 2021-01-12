#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>

/*! Enemy class
* \brief this file contains Enemy class which defines how enemies act in the game and status of the enemy

* this class includes functions that define boundaries which limit where the enemy can go,
* how much damage the enemy can make and the points a player can get from killing each enemy
*/
class Enemy
{
public:
	/*! constructor
	* \param pos_x - define enemy position on x axis
	* \param pos_y - define enemy position on y axis
	*/
	Enemy(float pos_x, float pos_y);
	/*! deconstructor
	*/
	virtual ~Enemy();
	/*! 
	* \brief get boundary of where the enemy can go
	* \return the boundaries of the map
	*/
	const sf::FloatRect getBounds() const;
	/*! 
	* \brief  a getter function to return points enemy gives per kill
	* \return points enemy gives per kill
	*/
	const int& getPoints() const;
	/*! 
	* \brief  a getter function to return damage enemy can cause per kill
	* \return damage eney causes per kill
	*/
	const int& getDamage() const;
	/*! 
	* update the status of the enemies
	*/
	void update();
	/*! 
	* \brief  draws the enemy sprite
	* \param sf::RenderTarget* target - define the target of the enemy
	*/
	void render(sf::RenderTarget* target);
private:
	unsigned pointCount;
	sf::Sprite enemySprite;
	sf::Texture texture;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	void enemyStats();
	void makeEnemy();
};

#endif //!ENEMY_H
