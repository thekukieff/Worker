#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

class Worker {




public:



	int Salary() {
		float premya = Premya();


		salary = salary * hours;
		salary = salary + (salary * premya);
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
		

	}





	void Fill_worker() {
		std::cout << "Введите ФИО сотрудника: ";
		std::getline(std::cin, name);

		std::cout << "\nВведите стаж работника: ";
		std::cin >> stage;

		std::cout << "\nВведите зп работника за час: ";
		std::cin >> salary;

		std::cout << "\nВведите количество отработанных часов за месяц: ";
		std::cin >> hours;
		std::cin.ignore(32000, '\n');

		File_array();



		

	}

	void Print_file_info() {
		system("cls");
		std::string data;
		std::ifstream file_read;
		file_read.open("data.txt");
		while (!file_read.eof()) {
			data = "";
			std::getline(file_read, data);
			std::cout << data<<"\n";
		}
			
		file_read.close();
	}



	//void Print_info() {
	//	

	//	system("cls");
	//	std::cout << "Работник: " << name;
	//	std::cout << "\n\nСтаж: " << stage << " лет";
	//	std::cout << "\n\nКоличество отработанных часов: " << hours;
	//	std::cout << "\n\nПремия: " << Premya() * 100 << "%";
	//	std::cout << "\n\nЗарплата: " << salary << " рублей в месяц";
	//	std::cout << "\n";
	//}
	void File_array() {
		std::ofstream file;
		file.open("data.txt", file.app);
		if (!file.is_open()) {
			std::cerr << "Error";
		}
		else {
			salary = Salary();
			file << "ФИО: " << name << "\n";
			file << "Зарплата: " << salary << " руб/месяц\n";
			file << "Премия: " << Premya() * 100 << "%\n";
			file << "Стаж: " << stage << " лет\n";
			file << "Часы: " << hours << " часов/месяц\n\n";



		}
		file.close();

		Print_file_info();


	}

private:
	std::string name;
	int stage;//стаж
	int salary, hours;
};



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Worker one, two, three;
	one.Fill_worker();
	two.Fill_worker();
	three.Fill_worker();


	return 0;
}

