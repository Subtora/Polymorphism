#include <string>

class Position {
private:
	int x, y, z;
public:
	Position(): x(0), y(0), z(0){}
	void updatePos(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
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