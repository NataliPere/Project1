#include <iostream>

//История
//ООП - полиморфизм, наследование, инкапсуляция
//Классы - набор методов и полей, который создаётся для того, чтобы абстрагироваться от работы над данными
//Контруктор копирования - принимает в себя объект такого же типа как и класс (копирует данные из другого класса)
//Правильная инициализация в конструкторе
//Перегрузка конструктора
//Перегрузка оператора == ! [] . ->
//Ключевое слово default
//Отличие класса от структуры - структура - не имеет квалификаторов доступа (Private, Public), структура - 
//Метод - ф-ция класса
//Парадигма RAII - 
class Vehicle {
public:
	//Конструктор (параметризованный)
	Vehicle(int newMaxSpeed, const std::string& newColor, const std::string& newType) :
		maxSpeed(newMaxSpeed), color(newColor), type(newType) {}

		//std::cout << "Constructor Vehicle()\n";
		//maxSpeed = newMaxSpeed;
		//color = newColor;
		//type = newType;
		//s = new char[50];*/

	//Конструктор дефолтный, перегруженный
	Vehicle(int newMaxSpeed) : maxSpeed(newMaxSpeed), color("brown"), type("bicycle") {}


	//Конструктор копирования
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
	Vehicle() = delete; //Удаляем дефолтный конструктор

	//Деструктор - разрушение класса
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

	//геттер - ф-ция, которая каждый раз возвращает поле класса
	int getMaxSpeed() {
		//counter++;
		return maxSpeed;
	}

	//сеттер - ф-ция, которая устанавливает новое значение для поля класса
	void setMaxSpeed(int newSpeed) {
		maxSpeed = newSpeed;
	}

	// Перегрузка оператора == (эквивалентности)
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