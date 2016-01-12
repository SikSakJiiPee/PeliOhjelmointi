/*
L�ht�taso teht�v�

-5 Luokkaa: GameObject, Player, Enemy, Projectile ja PickableItem (kaikki samaan fileen vaan t�ll� kertaa)
-Player ja Enemy, Projectile ja  PickableItem -luokat periytyv�t GameObject luokasta
-GameObject -luokalla on virtuaalinen metodi void update(float deltaTime)
-Player, Enemy ja Projectile -luokat osaavat liikkua (ts. tee update -metodin toteutus luokille)
	-printti riitt��
-P��ohjelmaan taulukko GameObjecteja, joita p�ivitet��n ikuisessa loopissa (deltaTimen voi kovakoodata esim. 1 s) (Viive onnistuu win32 API Sleep-funktiolla)
-P��loopissa luetaan k�ytt�j�n n�pp�inten painalluksia (katso win32 API: GetAsyncKeyState):
	-Napit: 1,2,3,4 = tee uusi objekti (1=Player, 2=Enemy, 3=Projectile, 4=PickableItem)
	-Nappi: A = Ensimm�inen Projectile t�rm�� ensimm�iseen Enemyyn -> enemyn energia v�henee yhdell� (aluksi 5) jos menee arvoon 0 -> Enemy pit�� poistaa (Printti ruudulle)
	-Nappi B = Ensimm�inen Player t�rm�� PickableItemiin -> PickableItem pit�� poistaa (Printti ruudulle)

-Palautus 12.1. s�hk�postilla: mikko.romppainen@kamk.fi
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
			//-Nappi: A = Ensimm�inen Projectile t�rm�� ensimm�iseen Enemyyn -> enemyn energia v�henee yhdell� (aluksi 5) jos menee arvoon 0 -> Enemy pit�� poistaa (Printti ruudulle)
		}
		if (GetAsyncKeyState(VK_SPACE)) //B
		{
			//-Nappi B = Ensimm�inen Player t�rm�� PickableItemiin -> PickableItem pit�� poistaa (Printti ruudulle)
		}
	}

}