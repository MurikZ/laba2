#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    setlocale(0, "ru");
    string line;
    ifstream in("2задание.txt");
    int count0 = 0;
    int count1 = 0;

    while (getline(in, line))
    {
        int n = stoi(line);
        if (n == 0)
        {
            count0++;
        }
        else if (n == 1)
        {
            count1++;
        }
    }
    if (count1 > count0)
    {
        cout << "количество единиц больше";
    }
    else if (count1 < count0)
    {
        cout << "количество нулей больше";
    }
    else
    {
        cout << "количество нулей и единиц одинаково";
    }
    in.close();
}//задание 2
