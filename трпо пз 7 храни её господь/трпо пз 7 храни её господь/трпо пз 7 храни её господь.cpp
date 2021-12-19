#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	string name;
	string surname;
	string city;
	int day, month, year;

	string AddName();
	string AddSurname();
	string AddCity();
	int AddDayOfBirth();
	int AddMonthOfBirth();
	int AddYearOfBirth();
};

string Student::AddName() 
{
	cout << "Введите имя : ";
	cin >> name;
	return name;
}

string Student::AddSurname() 
{
	cout << "Введите фамилию : ";
	cin >> surname;
	return surname;
}

string Student::AddCity() 
{
	cout << "Введите город : ";
	cin >> city;
	return city;
}

int Student::AddDayOfBirth() 
{
	cout << "Введите день рождения : ";
	cin >> day;
	return day;
}

int Student::AddMonthOfBirth() 
{
	cout << "Введите номер месяца рождения : ";
	cin >> month;
	return month;
}

int Student::AddYearOfBirth() 
{
	cout << "Введите год рождения : ";
	cin >> year;
	return year;
}

int AddNumberOfStudents() 
{
	cout << "Введите количество студентов : ";
	int size;
	cin >> size;
	return size;
}


void AddInfo(Student* arr, int size)
{
	for (int i = 0; i <= size; i++)
	{
		arr[i].AddName();
		arr[i].AddSurname();
		arr[i].AddCity();
		arr[i].AddDayOfBirth();
		arr[i].AddMonthOfBirth();
		arr[i].AddYearOfBirth();
	}
}

void GetInfo(Student* arr, int size) {
	for (int i = 0; i <= size; i++)
	{
		cout << "Имя [" << i + 1 << "] студента : " << arr[i].name << endl;
		cout << "Фамилия [" << i + 1 << "] студента : " << arr[i].surname << endl;
	}
}

string FindPopularName(Student* arr, int size)
{
	int max = 0;
	string PopularName;
	for (int i = 0; i < size; i++)
	{
		string Name = arr[i].name;
		int times = 0;
		for (int j = 0; j < size; j++)
		{
			if (Name == arr[j].name) times++;
		}
		if (times > max)
		{
			max = times;
			PopularName = arr[i].name;
		}
		return PopularName;
	}
}

void ShowAllInfo(Student* arr, int size)
{
	for (int i = 0; i <= size; i++)
	{
		cout << "Студент [" << i + 1 << "]" << endl;
		cout << "Имя : " << arr[i].name << endl;
		cout << "Фамилия : " << arr[i].surname << endl;
		cout << "Город : " << arr[i].city << endl;
		cout << "Дата рождения : " << arr[i].day << "." << arr[i].month << "." << arr[i].year << endl;
	}
}

void DeleteArray(Student* arr)
{
	delete[]arr;
	arr = NULL;
}

void sort(Student* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char element1;
			char element2;
			element1 = arr[j].surname[0];
			element2 = arr[j + 1].surname[0];
			if (element1 > element2)
			{
				string copyname;
				copyname = arr[j].name;
				string copysurname;
				copysurname = arr[j].surname;
				arr[j].name = arr[j + 1].name;
				arr[j + 1].name = copyname;
				arr[j].surname = arr[j + 1].surname;
				arr[j + 1].surname = copysurname;
			}
		}
	}
	cout << "Студенты : " << endl;
	for (int i = 0; i <= size; i++)
	{
		cout << "Имя [" << i + 1 << "] студента : " << arr[i].name << endl;
		cout << "Фамилия [" << i + 1 << "] студента : " << arr[i].surname << endl;
	}
}

int MediumAge(Student* arr, int size)
{
	int TDay = 25, TMonth = 11, TYear = 2021;
	double medage = 0;
	size++;
	for (int i = 0; i < size; i++)
	{
		int RY = arr[i].year, RM = arr[i].month, RD = arr[i].day;
		int Years = TYear - RY;
		int Days = 0;
		double Month = 0;
		if (TDay > RD)
		{
			Days = TDay - RD;
		}
		else if (RD > TDay) {
			Days = abs((RD - TDay) - 30);
			Month--;
		}
		if (TDay == RD) Days = 0;

		if (RM < TMonth)
		{
			Month = TMonth - RM;
		}
		else if (RM == TMonth)
		{
			Month = Month + RM - TMonth;
		}
		else if (TMonth < RM) {
			Years--;
			Month = 12 - abs(TMonth - RM);
		}
		double age = Years + (Month / 12) + Days / 365;
		medage += age;
	}
	medage /= size;
	return medage;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int size = AddNumberOfStudents();
	Student* arr = new Student[size--];
	int choose;
	do {
		cout << "Меню" << endl;
		cout << "  1. Добавить студентов " << endl;
		cout << "  2. Показать имена и фамилии студентов " << endl;
		cout << "  3. Найти наиболее популярное имя " << endl;
		cout << "  4. Показать всю информацию про студентов " << endl;
		cout << "  5. Очистить массив студентов " << endl;
		cout << "  6. Отсортировать студентов по первой букве фамилии " << endl;
		cout << "  7. Показать средний возраст студентов" << endl;
		cout << "  8. Завершить работу " << endl;
		cout << "  Выберете опцию (1-8)  " << endl;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			AddInfo(arr, size);
			break;
		}
		case 2:
		{
			GetInfo(arr, size);
			break;
		}
		case 3:
		{
			cout << "The most popular name : " << FindPopularName(arr, size) << endl;
			break;
		}
		case 4:
		{
			ShowAllInfo(arr, size);
			cout << "Completed." << endl;
			break;
		}
		case 5:
		{
			DeleteArray(arr);
			break;
		}
		case 6:
		{
			sort(arr, size);
			break;
		}
		case 7:
		{
			cout << "Medium age = " << MediumAge(arr, size) << endl;
			break;
		}
		case 8:
			break;
		default:
			cout << "Please enter (1-8) : " << endl << endl;
		}
	} while (choose != 8);
	system("pause>0");
	return 0;
}