#include <iostream>
#include <windows.h>

int ReturnDifferenceBetweenDates(int currentDate[], int nextDate[], int size);
bool IsCorrectDate(int date[], int size);
bool IsLeapYear(int year);
int GetDaysInMonth(int month, int year);
int GetDaysInDate(int date[]);

void FillArray(int arr[], int size);
double GetAvg(int arr[], int size);

void GetNumberOfPosNegZeroNumbers(int arr[], int size);

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	const int size = 3, size2 = 10, formatDay = 0, formatMonth = 1, formatYear = 2;

	int currentDate[size], nextDate[size];
	int differenceInDays = 0;

	int arrForAvg[size2];

	int arrForPosNegZero[size2];

	int choice = 0;

	while (true)
	{
		std::cout << "1 задание\n";
		std::cout << "2 задание\n";
		std::cout << "3 задание\n";
		std::cout << "0 выход\n";

		std::cout << "Выберите задание: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			do
			{
				std::cout << "Введите первую дату (день, месяц, год): \n";
				std::cout << "Введите день: ";
				std::cin >> currentDate[formatDay];
				std::cout << "Введите месяц: ";
				std::cin >> currentDate[formatMonth];
				std::cout << "Введите год: ";
				std::cin >> currentDate[formatYear];
				system("pause");
				system("cls");
			} while (!IsCorrectDate(currentDate, size));

			do
			{
				std::cout << "Введите вторую дату (день, месяц, год): \n";
				std::cout << "Введите день: ";
				std::cin >> nextDate[formatDay];
				std::cout << "Введите месяц: ";
				std::cin >> nextDate[formatMonth];
				std::cout << "Введите год: ";
				std::cin >> nextDate[formatYear];
			} while (!IsCorrectDate(nextDate, size));

			differenceInDays = ReturnDifferenceBetweenDates(currentDate, nextDate, size);
			std::cout << "Разница между датами: " << differenceInDays << " дней.\n";
			system("pause");
			system("cls");

			break;
		case 2:
			FillArray(arrForAvg, size2);
			std::cout << "Среднее значение элементов массива: " << GetAvg(arrForAvg, size2) << "\n";
			system("pause");
			system("cls");
			break;
		case 3:
			FillArray(arrForPosNegZero, size2);
			GetNumberOfPosNegZeroNumbers(arrForPosNegZero, size2);
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		default:
			std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
		}
	}

	return 0;
}

bool IsLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int ReturnDifferenceBetweenDates(int currentDate[], int nextDate[], int size)
{
	const int formatDay = 0, formatMonth = 1, formatYear = 2;
	int DaysInCurrentDate = 0, DaysInNextDate = 0;

	if (IsCorrectDate(currentDate, size) && IsCorrectDate(nextDate, size))
	{
		DaysInCurrentDate = GetDaysInDate(currentDate);
		DaysInNextDate = GetDaysInDate(nextDate);

		if (DaysInNextDate >= DaysInCurrentDate)
		{
			return DaysInNextDate - DaysInCurrentDate;
		}
		else
		{
			return DaysInCurrentDate - DaysInNextDate;
		}
	}

	return 0;
}

bool IsCorrectDate(int date[], int size)
{
	const int formatDay = 0, formatMonth = 1, formatYear = 2;

	if (size != 3)
	{
		std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
		return false;
	}

	if (date[formatDay] <= 0 || date[formatDay] > 31 || date[formatMonth] <= 0 || date[formatMonth] > 12 || date[formatYear] < 1)
	{
		std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
		return false;
	}

	switch (date[formatMonth])
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (date[formatDay] > 31)
		{
			std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
			return false;
		}
		break;

	case 4: case 6: case 9: case 11:
		if (date[formatDay] > 30)
		{
			std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
			return false;
		}
		break;

	case 2:
		if (IsLeapYear(date[formatYear]))
		{
			if (date[formatDay] > 29)
			{
				std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
				return false;
			}
		}
		else
		{
			if (date[formatDay] > 28)
			{
				std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
				return false;
			}
		}
		break;

	default:
		std::cout << "Ошибка: Неверный формат даты. Пожалуйста, укажите дату в формате[день, месяц, год].\n";
		return false;
	}

	return true;
}

int GetDaysInMonth(int month, int year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (IsLeapYear(year))
			return 29;
		else
			return 28;
	default:
		return 0;
	}
}

int GetDaysInDate(int date[])
{
	const int formatDay = 0, formatMonth = 1, formatYear = 2;
	int numberOfDays = 0;

	for (int i = date[formatYear] - 1; i > 0; i--)
	{
		for (int j = 0; j < 12; j++)
		{
			numberOfDays += GetDaysInMonth(j + 1, i);
		}
	}

	for (int i = date[formatMonth] - 1; i > 0; i--)
	{
		numberOfDays += GetDaysInMonth(i, date[formatYear]);
	}

	numberOfDays += date[formatDay];
	return numberOfDays;
}

void FillArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Введите элемент массива [" << i << "]: ";
		std::cin >> arr[i];
	}
}

double GetAvg(int arr[], int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

void GetNumberOfPosNegZeroNumbers(int arr[], int size)
{
	int PositiveCount = 0, NegativeCount = 0, ZeroCount = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
			PositiveCount++;
		else if (arr[i] < 0)
			NegativeCount++;
		else
			ZeroCount++;
	}
	std::cout << "Количество положительных чисел: " << PositiveCount << "\n";
	std::cout << "Количество отрицательных чисел: " << NegativeCount << "\n";
	std::cout << "Количество нулей: " << ZeroCount << "\n";
}