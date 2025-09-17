#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    int N = 0, M = 0;
    char operation = ' ';
    bool hasA = false, hasB = false, hasC = false;

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-a" && i + 1 < argc)
        {
            N = atoi(argv[i + 1]);
            hasA = true;
            i++;
            cout << "Key -a: N = " << N << endl;
        }
        else if (arg == "-b" && i + 1 < argc)
        {
            M = atoi(argv[i + 1]);
            hasB = true;
            i++;
            cout << "Key -b: M = " << M << endl;
        }
        else if (arg == "-c" && i + 1 < argc)
        {
            operation = argv[i + 1][0];
            hasC = true;
            i++;
            cout << "Key -c: operation = " << operation << endl;
        }
        else if (arg == "-d")
        {
            cout << "Program: key -d processed" << endl;
        }
        else if (arg == "-e")
        {
            cout << "Program: key -e processed" << endl;
        }
    }

    if (!hasA || !hasB || !hasC)
    {
        cout << "Error: must specify keys -a, -b and -c with arguments!" << endl;
        cout << "Usage: program.exe -a 5 -b 3 -c +" << endl;
        return 1;
    }

    cout << "Result: " << N << " " << operation << " " << M << " = ";

    switch (operation)
    {
    case '+':
        cout << N + M << endl;
        break;
    case '-':
        cout << N - M << endl;
        break;
    case '*':
        cout << N * M << endl;
        break;
    case '/':
        if (M != 0)
            cout << (double)N / M << endl;
        else
            cout << "Error: division by zero!" << endl;
        break;
    default:
        cout << "Error: unknown operation!" << endl;
        break;
    }

    return 0;
}