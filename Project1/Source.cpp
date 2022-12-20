#include <iostream>

//�������
//��� - �����������, ������������, ������������
//������ - ����� ������� � �����, ������� �������� ��� ����, ����� ���������������� �� ������ ��� �������
//���������� ����������� - ��������� � ���� ������ ������ �� ���� ��� � ����� (�������� ������ �� ������� ������)
//���������� ������������� � ������������
//���������� ������������
//���������� ��������� == ! [] . ->
//�������� ����� default
//������� ������ �� ��������� - ��������� - �� ����� �������������� ������� (Private, Public), ��������� - 
//����� - �-��� ������
//��������� RAII - 
class Vehicle {
public:
	//����������� (�����������������)
	Vehicle(int newMaxSpeed, const std::string& newColor, const std::string& newType) :
		maxSpeed(newMaxSpeed), color(newColor), type(newType) {}

		//std::cout << "Constructor Vehicle()\n";
		//maxSpeed = newMaxSpeed;
		//color = newColor;
		//type = newType;
		//s = new char[50];*/

	//����������� ���������, �������������
	Vehicle(int newMaxSpeed) : maxSpeed(newMaxSpeed), color("brown"), type("bicycle") {}


	//����������� �����������
	Vehicle(Vehicle& obj) {
		maxSpeed = obj.getMaxSpeed();
		color = obj.getColor();
		type = obj.getType();
	}



	Vehicle(int newMaxSpeed) { // Vehicle() = defauilt;
		maxSpeed = newMaxSpeed;
		color = "yellow";
		type = "bus";
	}
	Vehicle() = delete; //������� ��������� �����������

	//���������� - ���������� ������
	~Vehicle() {
		std::cout << "Destructor Vehicle()\n";
		delete[] s;
	}

	std::string getColor() {
		return color;
	}

	void setColor(const std::string& newColor) {
		color = newColor;
	}

	std::string& getType() {
		return type;
	}

	void setType(const std::string& newType){
		type = newType;
		}

	//������ - �-���, ������� ������ ��� ���������� ���� ������
	int getMaxSpeed() {
		//counter++;
		return maxSpeed;
	}

	//������ - �-���, ������� ������������� ����� �������� ��� ���� ������
	void setMaxSpeed(int newSpeed) {
		maxSpeed = newSpeed;
	}

	// ���������� ��������� == (���������������)
	bool operator ==(Vehicle& other) {
		if (maxSpeed == other.maxSpeed &&
			color == other.color &&
			type == other.type) {
			return true;
		}
		return false;
	}

	bool operator!() {
		if (maxSpeed < 0) {
			return true;
		}
		return false;
	}


private:
	int maxSpeed;
	
	std::string color;
	std::string type;
	char* s;
};

int main() {
	std::cout << "Start of main() \n";

	Vehicle car(20, "black", "van");
	std::string carColor = car.getColor();
	std::cout << " carColor:" << carColor << " car.getColor()" << car.getColor() << "\n";
	carColor = "green";
	std::cout << " carColor:" << carColor << " car.getColor()" << car.getColor() << "\n";

	const std::string& carType = car.getType();
	//carType = "randomType";
	std::cout << carType << " " << car.getType() << "\n";

	//car.setMaxSpeed(50);
	//std::cout << "Max speed is: " << car.getMaxSpeed() << "\n";

	//std::cout << "End of main) \n";

	Vehicle originalcar(15, "white", "bus");
	Vehicle newCar(originalcar);
	Vehicle foreignCar(15, "white", "abs");

	std::cout << originalcar.getMaxSpeed() << " " << originalcar.getType() << "\n";
	std::cout << " =====================\n";
	std::cout << newCar.getMaxSpeed() << " " << newCar.getColor() << " " << newCar.getType() << "\n";

	std::cout << (originalcar == newCar) << "\n";
	std::cout << " ==========\n";
	std::cout << (originalcar == foreignCar) << "\n";




}