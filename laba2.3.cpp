#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;
int main()
{
    ifstream in("inputзадание3.txt");
    ofstream out("outputзадание3.txt");

    char c;
    while (in.get(c))
    {
        if (isalpha(c))
        {
            out << c;
        }
    }
    in.close();
    out.close();
    return 0;
}
