#include <iostream>
#include <windows.h>
#include <string>

class Worker {

public:
	std::string name;
	int stage;//стаж
	int salary, hours;


	int Salary() {
		float premya = Premya();


		salary = salary * hours;
		salary = salary + salary * premya;
		return salary;

	}


	float Premya() {
		
		float premya;
	
		if (stage == 0) {
			premya = 0;
		}
		else if (stage > 5) {//более 5
			premya = 0.15;
		}
		else if (stage > 2) {//до пяти
			premya = 0.08;
		}
		else {
			premya = 0.05;//до 3 лет
		}
		return premya;
		Salary();
		
	}





	void Fill_worker() {
		std::cout << "Введите ФИО сотрудника: ";
		std::getline(std::cin,name);

		std::cout << "\nВведите стаж работника: ";
		std::cin >> stage;

		std::cout << "\nВведите зп работника за час: ";
		std::cin >> salary;

		std::cout << "\nВведите количество отработанных часов за месяц: ";
		std::cin >> hours;
		std::cin.ignore(32000, '\n');
		Premya();
		Cout_info();

	}




	void Cout_info() {
		
		system("cls");
		std::cout << "Работник: " << name;
		std::cout << "\n\nСтаж: " << stage<<" лет";
		std::cout << "\n\nКоличество отработанных часов: " << hours;
		std::cout << "\n\nПремия: " << Premya() * 100 << "%";
		std::cout << "\n\nЗарплата: " << Salary() << " рублей в месяц";
		std::cout << "\n";
	}


};



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Worker one;
	one.Fill_worker();



	return 0;
}

