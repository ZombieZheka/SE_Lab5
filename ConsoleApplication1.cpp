#include <iostream>
#include "windows.h"
using namespace std;

double getDouble()
{
    while (true)
    {
        double value;
        cin >> value;

        if (cin.fail()) // якщо попередня спроба отримати значення виявилась невдалою,
        {
            cin.clear(); // то повертаємо cin в 'звичайний' режим роботи
            cin.ignore(32767, '\n'); // і видаляємо значення попереднього вводу з вхідного буфера
            cout << "Введіть значення типу double: ";
        }
        else // якщо все дообре, то повертаємо значення
        {
            return value;
        }
    }
}

int getInt()
{
    while (true)
    {
        double value;
        cin >> value;

        if (cin.fail() || value != floor(value)) // якщо попередня спроба отримати значення виявилась невдалою,
        {
            cin.clear(); // то повертаємо cin в 'звичайний' режим роботи
            cin.ignore(32767, '\n'); // і видаляємо значення попереднього вводу з вхідного буфера
            cout << "Введіть значення типу int: ";
        }
        else // якщо все дообре, то повертаємо значення
        {
            return (int)value;
        }
    }
}

void set_value(double* x, double* _x, double* s, int* n)
{
    cout << "Введіть x (початок діапазону), z (кінець діапазону), s (крок діапазону) та значення n: \n";

    cout << "x = ";
    *x = getDouble();

    cout << "z = ";
    *_x = getDouble();

    cout << "s = ";
    *s = getDouble();

    cout << "n = ";
    *n = getInt();

    cout << endl;

    while (*x > *_x || *s <= 0)
    {
        cout << "Помилкові дані!!!\n";
        if (*x > *_x && *s <= 0)
            cout << "Початкове значення діапазону не може бути більшим, ніж його кінцеве!\nКрок повинен бути більшим ніж нуль!\n\n";
        else if (*x > *_x)
            cout << "Початкове значення діапазону не може бути більшим, ніж його кінцеве!\n\n";
        else if (*s <= 0)
            cout << "Крок повинен бути більшим ніж нуль!\n\n";

        cout << "Введіть x (початок діапазону), z (кінець діапазону), s (крок діапазону) та значення n: \n";

        cout << "x = ";
        *x = getDouble();

        cout << "z = ";
        *_x = getDouble();

        cout << "s = ";
        *s = getDouble();

        cout << "n = ";
        *n = getDouble();

        cout << endl;
    }
}

double y(double x, int n)
{
    double a = 0, b = 0;
    if (x < 0)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                b += (x - i * i + j) * (x - i * i + j);
            }
            a += b;
        }
    }
    else
    {
        a = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            a += (x - 1) / (i + 1);
        }
    }
    return a;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, _x, s, a = 1, b = 0;
    int n;

    set_value(&x, &_x, &s, &n);

    while (x <= _x)
    {
        // округлення числа для запобігання помилки у випадку, коли x дорівнює 0
        x = floor(x * 1000000000000000 + 0.5) / 1000000000000000;

        cout << "x = " << x << "    y = " << y(x, n) << endl;
        x += s;
    }
    system("pause");
    return 0;
}