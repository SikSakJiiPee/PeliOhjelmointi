/*
Lähtötaso tehtävä

-5 Luokkaa: GameObject, Player, Enemy, Projectile ja PickableItem (kaikki samaan fileen vaan tällä kertaa)
-Player ja Enemy, Projectile ja  PickableItem -luokat periytyvät GameObject luokasta
-GameObject -luokalla on virtuaalinen metodi void update(float deltaTime)
-Player, Enemy ja Projectile -luokat osaavat liikkua (ts. tee update -metodin toteutus luokille)
	-printti riittää
-Pääohjelmaan taulukko GameObjecteja, joita päivitetään ikuisessa loopissa (deltaTimen voi kovakoodata esim. 1 s) (Viive onnistuu win32 API Sleep-funktiolla)
-Pääloopissa luetaan käyttäjän näppäinten painalluksia (katso win32 API: GetAsyncKeyState):
	-Napit: 1,2,3,4 = tee uusi objekti (1=Player, 2=Enemy, 3=Projectile, 4=PickableItem)
	-Nappi: A = Ensimmäinen Projectile törmää ensimmäiseen Enemyyn -> enemyn energia vähenee yhdellä (aluksi 5) jos menee arvoon 0 -> Enemy pitää poistaa (Printti ruudulle)
	-Nappi B = Ensimmäinen Player törmää PickableItemiin -> PickableItem pitää poistaa (Printti ruudulle)

-Palautus 12.1. sähköpostilla: mikko.romppainen@kamk.fi
*/

#include "Windows.h"
#include <iostream>
#include <string>
#include <vector>

class GameObject
{
public:
	GameObject(/*int typeId, std::string n, int x, int spd*/);

	virtual void update(float deltaTime);
	virtual void move(int speed);
	virtual void printPosition(std::string name, int posX);

	int typeID;
	std::string name;
	int posX;
	int speed;
};

void GameObject::update(float deltaTime)
{
	
}

void GameObject::move(int speed)
{
	posX += speed;
}

void GameObject::printPosition(std::string name, int posX)
{
	std::cout << "Object:   " << name << std::endl;
	std::cout << "Position: " << posX << std::endl;
	std::cout << std::endl;
}


class Player : public GameObject
{
public:
	void move();

private:
	
};


class Enemy : public GameObject
{
public:
	void move();
	void loseHealth();
	void defeated() { delete this; }

private:
	int health = 5;
};

void Enemy::loseHealth()
{
	health -= 1;
}

class Projectile : public GameObject
{
public:
	void move();

private:

};


class PickableItem : public GameObject
{
public:
	void itemPicked() { delete this; }

private:

};


int main()
{
	std::vector<GameObject> gameObjects;

	bool gameLoop = true;

	while (gameLoop == true)
	{
		//joku viivytys
		Sleep(125);
		if (GetAsyncKeyState(VK_UP)) //1
		{
			std::cout << "Player Created" << std::endl;

		}
		if (GetAsyncKeyState(VK_LEFT)) //2
		{
			std::cout << "Enemy Created" << std::endl;

		}
		if (GetAsyncKeyState(VK_DOWN)) //3
		{
			std::cout << "Projectile Created" << std::endl;

		}
		if (GetAsyncKeyState(VK_RIGHT)) //4
		{
			std::cout << "PickableItem Created" << std::endl;

		}
		if (GetAsyncKeyState(VK_CONTROL)) //A
		{
			//-Nappi: A = Ensimmäinen Projectile törmää ensimmäiseen Enemyyn -> enemyn energia vähenee yhdellä (aluksi 5) jos menee arvoon 0 -> Enemy pitää poistaa (Printti ruudulle)
		}
		if (GetAsyncKeyState(VK_SPACE)) //B
		{
			//-Nappi B = Ensimmäinen Player törmää PickableItemiin -> PickableItem pitää poistaa (Printti ruudulle)
		}
	}

}