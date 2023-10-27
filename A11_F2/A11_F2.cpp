// ANDREOU VASILEIOS 92275 A10_F2
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 105
#pragma warning(disable : 4996)

using namespace std;

class inertia
{
private:
    int id;
    double mass;
    double x_cord;
    double y_cord;
    double z_cord;

public:
    //default constructor
    inertia()
    {
        id = 0; mass = 0.0; x_cord = 0.0; y_cord = 0.0, z_cord = 0.0;
    };

    //constructor with parameters' list
    inertia(int number, double m, double x, double y, double z)
    {
        id = number;
        mass = m;
        x_cord = x;
        y_cord = y;
        z_cord = z;
    };

    int get_number() { return id; };
    double get_mass() { return mass; };
    double get_x() { return x_cord; };
    double get_y() { return y_cord; };
    double get_z() { return z_cord; };

    void print()
    {
        cout << id << " " << mass << " " << x_cord << " " << y_cord << " " << z_cord << " " << endl;
    };

};//end definition of class inertia

int main()
{
    int i = 0, number;
    double m, x, y, z;
    double Ixy = 0.0, Iyz= 0.0, Izx = 0.0, frequency[10] = {}, tempIxy[101] = {}, tempIyz[101] = {}, tempIzx[101] = {}, tempmass[101] = {};

    srand((unsigned int)time(0));

    // ****************************************************************************************************
    system("Color F1");

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 20;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Courier"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    std::cout << "Font: Courier, Size: 20\n";
    // ****************************************************************************************************

    cout << endl;
    inertia a[N];

    cout << "n m x y z" << endl;
    //RHTH KLHSH ston default constructor (arxikopoihsh pinaka)
    for (i = 0; i < N; i++)
    {
        a[i] = inertia();
        a[i].print();
    };

    cout << endl << "n  m  x  y  z" << endl;

    //RHTH KLHSH ston constructor with parameters' list
    for (i = 0; i < N; i++)
    {
        number = rand() % 10;
        m = static_cast<double> (rand() % 100 + 1);
        x = static_cast<double> (rand() % 100 + 1);
        y = static_cast<double> (rand() % 100 + 1);
        z = static_cast<double> (rand() % 100 + 1);

        a[i] = inertia(number, m, x, y, z);
        a[i].print();

        frequency[a[i].get_number()]++;
        tempIxy[a[i].get_number()] += pow(a[i].get_z(), 2);
        tempIyz[a[i].get_number()] += pow(a[i].get_x(), 2);
        tempIzx[a[i].get_number()] += pow(a[i].get_y(), 2);
        tempmass[a[i].get_number()] += a[i].get_mass();
    };
    
    cout << "\nFrequency\n";
    for (i = 1; i < 10; i++)
    {
        cout << i << " " << frequency[i] << endl;
    };
    
    cout << "\nResults\n";
    for (i = 1; i < 10; i++)
    {
        if (frequency[i]>5)
        {
            Ixy = tempmass[i] * tempIxy[i];
            Iyz = tempmass[i] * tempIyz[i];
            Izx = tempmass[i] * tempIzx[i];
            cout << "Inertia for Part " << i << " (Ixy, Iyz, Izx):" << " (" << Ixy << ", " << Iyz << ", " << Izx << ")" << endl;
        }
        else
        {
            cout << "Part " << i << " has lesser than 5 material points." << endl;
        }
    };
}// end main