#include <iostream>
#include <windows.h>
#include <string>

class Worker {

public:
	std::string name;
	int stage;//����
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
		else if (stage > 5) {//����� 5
			premya = 0.15;
		}
		else if (stage > 2) {//�� ����
			premya = 0.08;
		}
		else {
			premya = 0.05;//�� 3 ���
		}
		return premya;
		Salary();
		
	}





	void Fill_worker() {
		std::cout << "������� ��� ����������: ";
		std::getline(std::cin,name);

		std::cout << "\n������� ���� ���������: ";
		std::cin >> stage;

		std::cout << "\n������� �� ��������� �� ���: ";
		std::cin >> salary;

		std::cout << "\n������� ���������� ������������ ����� �� �����: ";
		std::cin >> hours;
		std::cin.ignore(32000, '\n');
		Premya();
		Cout_info();

	}




	void Cout_info() {
		
		system("cls");
		std::cout << "��������: " << name;
		std::cout << "\n\n����: " << stage<<" ���";
		std::cout << "\n\n���������� ������������ �����: " << hours;
		std::cout << "\n\n������: " << Premya() * 100 << "%";
		std::cout << "\n\n��������: " << Salary() << " ������ � �����";
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

