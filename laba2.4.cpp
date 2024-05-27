#include <fstream>
#include <iostream>

using namespace std;
int main()
{
    ifstream input("4задание.txt");
    int number;
    int position = 1;
    int count=0;

    while (input >> number)
    {
        if (number == 0 and position % 2 == 0)
        {
            count++;
        }
        position++;
    }
    cout << count;
    input.close();

    return 0;
}
