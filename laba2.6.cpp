#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
    vector<char>vet;

    ifstream input("text.txt");
    char c;

    while (input >> c)
    {
        vet.push_back(c);
    }
    char First = vet[0];
    char Second = vet[1];
    char fc = vet[0] + vet[1];
    if (isdigit(fc))
    {
        int num = fc - '0';
        if (num % 2 == 0)
        {
            cout << "все отлично";
        }
        else
        {
            cout << "не подходит";
        }
    }
    else
    {
        cout << "абсолютно не подходит";
    }
    input.close();
    return 0;


}
