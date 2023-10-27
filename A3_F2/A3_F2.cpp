// ANDREOU VASILEIOS 92275 A3_F2
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#pragma warning(disable : 4996)

using namespace std;

class WebPage
{
    private:
        int visits;
        int msgs;
        int downloads;

    public:
        //default constructor!!!!
        WebPage()
        {
            visits = 0; msgs = 0; downloads = 0;
        };

        // Constructor with parameters' list
        WebPage(int v, int m, int d)
        {
            visits = v;
            msgs = m;
            downloads = d;
        };

    int get_visits() { return visits; };
    double get_msgs() { return msgs; };
    double get_downloads() { return downloads; };

    void print()
    {
        cout << visits << " " << msgs << " " << downloads << endl;
    };

};//end definition of class WebPage

int main()
{
    int i = 0, v, m, d;
    double sum_visits = 0.0, sum_messages = 0.0, sum_downloads = 0.0;

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
    WebPage a[N];
    
    // RHTH KLHSH STON DEFAULT CONSTRUCTOR (ARXIKOPOIHSH PINAKA)!!!!!
    for (i = 0; i<N; i++)
    {
        a[i] =  WebPage();
        a[i].print();
    };

    cout << endl;
    
    // RHTH KLHSH STON  CONSTRUCTOR with parameters' list!!!!!
    for (i=0; i<N; i++)
    {
        v = static_cast<double> (rand()%1001);
        m = static_cast<double> (rand()%1001);
        d = static_cast<double> (rand()%1001);

        a[i] = WebPage(v, m, d);
        a[i].print();

        sum_visits += a[i].get_visits();
        sum_messages += a[i].get_msgs();
        sum_downloads += a[i].get_downloads();
    };

    cout << "\n--------Totals--------\n";
    cout << "Total visits: " << sum_visits << endl;
    cout << "Total messages: " << sum_messages << endl;
    cout << "Total downloads: " << sum_downloads << endl;
}// end main