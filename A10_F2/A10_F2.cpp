// ANDREOU VASILEIOS 92275 A10_F2
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define N 105
#pragma warning(disable : 4996)

using namespace std;

class mass_point
{
private:
    int id;
    int mass;
    float x_cord;
    float y_cord;
    float z_cord;

public:
    //default constructor
    mass_point()
    {
        id = 0; mass = 0; x_cord = 0.0; y_cord = 0.0, z_cord = 0.0;
    };

    //constructor with parameters' list
    mass_point(int number, int m, float x, float y, float z)
    {
        id = number;
        mass = m;
        x_cord = x;
        y_cord = y;
        z_cord = z;
    };

    int get_number() { return id; };
    int get_mass() { return mass; };
    float get_x() { return x_cord; };
    float get_y() { return y_cord; };
    float get_z() { return z_cord; };

    void print()
    {
        cout << id << " " << mass << " " << x_cord << " " << y_cord << " " << z_cord << " " << endl;
    };

};//end definition of class mass_point

int main()
{
    int i = 0, m, number;
    float x, y, z;
    float x_bar = 0.0, y_bar = 0.0, z_bar = 0, frequency[11] = {}, tempx[101] = {}, tempy[101] = {}, tempz[101] = {}, tempmass[101] = {};

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
    mass_point a[N];

    cout << "n m x y z" << endl;
    //RHTH KLHSH ston default constructor (arxikopoihsh pinaka)
    for (i = 0; i < N; i++)
    {
        a[i] = mass_point();
        a[i].print();
    };

    cout << endl << "n  m  x  y  z" << endl;

    //RHTH KLHSH ston constructor with parameters' list
    for (i = 0; i < N; i++)
    {
        number = rand() % 10 + 1;
        m = rand() % 100 + 1;
        x = static_cast<float> (rand() % 100 + 1);
        y = static_cast<float> (rand() % 100 + 1);
        z = static_cast<float> (rand() % 100 + 1);

        a[i] = mass_point(number, m, x, y, z);
        a[i].print();
        
        frequency[a[i].get_number()]++;
        tempx[a[i].get_number()] += a[i].get_x();
        tempy[a[i].get_number()] += a[i].get_y();
        tempz[a[i].get_number()] += a[i].get_z();
        tempmass[a[i].get_number()] += a[i].get_mass();
    };

    cout << "\nFrequency\n";
    for (i = 1; i < 11; i++)
    {
        cout << i << " " << frequency[i] << endl;
    };

    cout << "\nResults\n";
    for (i = 1; i < 11; i++)
    {
        if (tempmass[i] > 0)
        {
            x_bar = tempx[i] / tempmass[i];
            y_bar = tempy[i] / tempmass[i];
            z_bar = tempz[i] / tempmass[i];
            cout << "Center of Mass for Part " << i << ": (" << x_bar << ", " << y_bar << ", " << z_bar << ")" << endl;
        }
        else
        {
            cout << "Center of Mass for Part " << i << ": (" << tempx[i] << ", " << tempy[i] << ", " << tempz[i] << ")" << endl;
        }
    };
}// end main