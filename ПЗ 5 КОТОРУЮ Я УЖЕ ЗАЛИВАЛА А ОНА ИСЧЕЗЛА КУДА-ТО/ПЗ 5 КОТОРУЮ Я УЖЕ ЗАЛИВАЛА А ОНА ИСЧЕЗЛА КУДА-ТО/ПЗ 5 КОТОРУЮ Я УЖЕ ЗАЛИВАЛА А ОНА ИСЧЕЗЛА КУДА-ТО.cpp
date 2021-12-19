#include <iostream>
#include <stdio.h>
#include <ctime>
#include <math.h>

using namespace std;

void Convert_To_String(int a)
{
    int SizeOfNumber = 0;
    int copy_a = a;
    while (copy_a > 0)
    {
        SizeOfNumber++;
        copy_a /= 10;
    }
    int del = pow(10, SizeOfNumber - 1);
    char* arr = new char[SizeOfNumber--];
    for (int i = 0; i <= SizeOfNumber; i++)
    {
        arr[i] = (a / del) % 10 + 48;
        del /= 10;
        cout << arr[i];
    }
    cout << endl;
    delete[]arr;
    arr = NULL;
}

void Convert_To_String(int a, int size)
{
    int Copy_a = a;
    int SizeOfNumber = 0;
    while (Copy_a > 0)
    {
        SizeOfNumber++;
        Copy_a /= 10;
    }
    int del = pow(10, SizeOfNumber - 1);
    char* arr = new char[SizeOfNumber--];
    if (size > SizeOfNumber + 1)
    {
        cout << "size>l" << endl;
    }
    else {
        for (int i = 0; i < size; i++)
        {
            arr[i] = (a / del) % 10 + 48;
            del /= 10;
            cout << arr[i];
        }
        cout << endl;
    }
    delete[]arr;
    arr = NULL;
}

void Find_Copy(int* arr, int size2)
{
    int max = 0;
    for (int i = 0; i < size2; i++)
    {
        int Del = 0;
        int ElementOfArray = arr[i];
        for (int j = 0; j < size2; j++)
        {
            if (ElementOfArray == arr[j]) Del++;
        }
        if (Del > max) max = Del;
    }
    cout << "Максимальное количество повторений : " << max << endl;
    delete[]arr;
    arr = NULL;
}

void Find_Copy(char* arr, int size2)
{
    int max = 0;
    for (int i = 0; i < size2; i++)
    {
        int Copies = 0;
        char ElemOfArray = arr[i];
        for (int j = 0; j < size2; j++)
        {
            if (ElemOfArray == arr[j]) Copies++;
        }
        if (Copies > max) max = Copies;
    }
    cout << "Максимальное количество повторений : " << max << endl;
    delete[]arr;
    arr = NULL;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    char choise;
    do {
        cout << "Менюшка" << endl;
        cout << "  1. Перевод всего числа в строку " << endl;
        cout << "  2. Перевод определенного количества элементов в строку " << endl;
        cout << "  3. Найти максимальное кол-во повторений символов в массиве (тип данных int) " << endl;
        cout << "  4. Найти максимальное кол-во повторений символов в массиве (тип данных char) " << endl;
        cout << "  5. Выход " << endl;
        cout << " Выберите действие : ";
        cin >> choise;
        switch (choise) {
        case '1':
        {
            int number;
            cout << "Введите число для перевода в массив char : ";
            cin >> number;
            Convert_To_String(number);
            break;
        }

        case '2':
        {
            int Number_2;
            cout << "Число для перевода : ";
            cin >> Number_2;
            cout << "Введите кол-во символов , которое нужно будет перевести в массив char : ";
            int size;
            cin >> size;
            Convert_To_String(Number_2, size);
            break;
        }

        case '3':
        {
            int size;
            cout << "Размер массива : ";
            cin >> size;
            int* arr1 = new int[size];
            cout << "Нажмите 1 для рандомной генерации чисел , иначе нужно будет вводить вручную" << endl;
            int choose;
            cin >> choose;

            if (choose == 1)
            {
                cout << "Сгенерированный массив : ";
                for (int i = 0; i < size; i++)
                {
                    arr1[i] = rand() % 10;
                    cout << arr1[i] << " ";
                }
                cout << endl;
            }
            else {
                for (int i = 0; i < size; i++)
                {
                    cin >> arr1[i];
                }
            }
            Find_Copy(arr1, size);
            break;
        }
        case '4':
        {
            int size;
            cout << "Размер массива : ";
            cin >> size;
            char* arr1 = new char[size];
            cout << "Нажмите 0 для рандомной генерации чисел , иначе нужно будет вводить вручную" << endl;
            int choose;
            cin >> choose;
                if (choose == 0)
                {
                    cout << "Сгенерированный массив : ";
                    for (int i = 0; i < size; i++)
                    {
                        arr1[i] = rand() % 10 + 48;
                        cout << arr1[i] << " ";
                    }
                    cout << endl;
                }
                else {
                    cout << "Введите значения массива вручную : ";
                    for (int i = 0; i < size; i++)
                    {
                        cin >> arr1[i];
                    }
                }
            Find_Copy(arr1, size);
            break;
        }
        case '5': break;
        }
    } while (choise != '5');
    system("pause>0");
    return 0;
}