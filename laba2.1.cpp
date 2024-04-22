#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    setlocale(0, "RU");
    string line;
    int count = 0;
    int sum = 0;

    ifstream in;
    in.open("1задание.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            double n = stod(line);
            if (n > 0)
            {
                count++;
                sum += n;
            }

        }
    }
    else
    {
        cerr << "error\n";
    }

    cout << "количество положительных" << count;
    cout << "сумма положительных" << sum;
    in.close();
}