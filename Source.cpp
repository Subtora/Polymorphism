#include <string>
#include <iostream>
enum coords{x = 1, y = 2, z = 3};
class Position {
private:
	int xyz[3];
public:
	Position(){}
	void updatePos(int X , int Y, int Z) {
		xyz[x] = X;
		xyz[y] = Y;
		xyz[z] = Z;
	}
	int* getPos() {
		return xyz;
	}
};

class Attack {
private:
	double power;
public:
	Attack() : power(0){}
	void setAttack(double power){
		this->power = power;
	}
	virtual void mkAttack() = 0;
};

class Entity : public Position, public Attack{
protected:
	std::string name;
	double health;
public:
	Entity() : name("ENT"), health(0){}

};

class Player : public Entity {
public:
	Player(std::string name = "player") {
		this->name = name;
		setAttack(0);
		updatePos(10, 0, 0);
	}
	void mkAttack() override{
		std::cout << "gunshot" << std::endl;
	}

};
class Enemy : public Entity {
	Enemy(std::string name = "enemy") {
		this->name = name;
		setAttack(0);
		updatePos(10, 10, 5);
	}

};

int main() {
	return 0;
}