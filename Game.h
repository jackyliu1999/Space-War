#pragma once
#include<map>
#include<string>
#include<sstream>
#include"Player.h"
#include"Weapon.h"
#include"Enemy.h"
#include <SFML/Audio.hpp>

/*! Game class
* \brief this file contains Game class which incorporates Player, Weapon and Enemy classes.
*
* this class includes functions which define sound the game plays when starting a game. Also, 
* include several private functions that update GUI of the character, weapon and enemies 
*/
class Game
{
public:
	/*!
	* \brief constructor that uses window property from SFML framework 
	* \param sf::RenderWindow* window - define window size of the game
	*/
	Game(sf::RenderWindow * window);
	/*!
	* deconstructor  
	*/
	virtual ~Game();
	/*!
	* update the status of the game when the character is still alive   
	*/
    int update();

private:
	// sound properties
    sf::SoundBuffer laser_buff;
    sf::Sound laser_wav;
    sf::SoundBuffer explo_buff;
    sf::Sound explo_wav;

    sf::RenderWindow * window;
	// image used for map 
	std::map<std::string, sf::Texture*> textures;
	std::vector<Weapon*> kunais;
	sf::Font font;
	// text shown on the map 
	sf::Text pointText;
	sf::Text hpText;
	sf::Text levelText;
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	// current points
	int points;
	// level of game 
	int level;
	// maximum level 
	int maxLevel;
	// enemy number
	int enemyNum;
	Player* player;
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	/*!
	* define image of the weapon
	*/
	void makeTextures();
	/*!
	* define GUI of HP bar and point bar 
	*/
	void GUIFunctions();
	/*!
	* load background image 
	*/
	void makeWorld();
	/*!
	* inialize game to level 1
	*/
	void initLevel();
	/*!
	* increase level by 1 
	*/
	void newLevel();
	/*!
	* increase level by 1 
	*/
	void pointsSystem();
	/*!
	* initalize a new player  
	*/
	void makePlayer();
	void spawnEnemies();
	void updatePollEvents();
	/*!
	* define control of character by the player    
	*/
	void updateInput();
	/*!
	* update GUI of killed counts    
	*/
	void updateGUI();
	/*!
	* update the status of the collision   
	*/
	void updateCollision();
	/*!
	* update the status of the weapon   
	*/
	void updateWeapon();
	/*!
	* update the status of enemies   
	*/
	void updateEnemies();
	/*!
	* update GUI of combat    
	*/
	void updateCombat();
	/*!
	* render GUI of the game    
	*/
	void renderGUI();
	/*!
	* render GUI of the game background   
	*/
	void renderWorld();
};

