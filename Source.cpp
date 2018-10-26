#include <string>
#include <iostream>
enum xyzPlane{x = 1, y = 2, z = 3};
int entityCount = 0;
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
	const int* getPos() {
		return xyz;
	}
	const void printPos() {
		for (int i = x; i <= z; i++)
			std::cout << xyz[i] << " ";
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
	//must be overriden within derived classes
	virtual const void mkAttack() = 0;
};
class Entity : public Position, public Attack{
private:
	int entID = entityCount;
protected:
	std::string name;
	double health;
public:
	Entity() : name("ENT"), health(0){}
	int getEntID() {
		entityCount += 1;
		return entID;
	}
	const std::string getName() {
		return name;
	}
};
class Player : public Entity {
private:
	int playerID;
public:
	Player(std::string name = "player") {
		this->name = name;
		playerID = getEntID();
		setAttack(10);
	}
	//polymorphism
	const void mkAttack() override{
		std::cout << "shoot" << std::endl;
	}

};
class Enemy : public Entity {
private:
	int EnemyID;
public:
	Enemy(std::string name = "enemy") {
		this->name = name;
		EnemyID = getEntID();
		setAttack(2);
	}
	//polymorphism
	const void mkAttack() override {
		std::cout << "bite" << std::endl;
	}
};



int main() {
	Player p1("subtora");
	Enemy g1("wolf");

	std::cin.get();

	return 0;
}