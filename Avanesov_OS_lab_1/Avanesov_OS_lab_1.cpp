#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

bool isInteger(const string& s) {
    if (s.empty()) return false;
    for (char c : s)
        if (!isdigit(c) && c != '-' && c != '+') return false;
    return true;
}

int main(int argc, char* argv[]) {
    string outputFilename = "result.txt";
    string errorFilename = "errors.txt";

    if (argc == 1) {
        ofstream errorFile(errorFilename);
        errorFile << "Error: no arguments provided!" << endl;
        cerr << "Error: no arguments provided! Check " << errorFilename << endl;
        return 1;
    }

    int N = 0, M = 0;
    char operation = ' ';
    bool hasA = false, hasB = false, hasC = false;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];

        if (arg == "-a") {
            if (i + 1 >= argc || !isInteger(argv[i + 1])) {
                ofstream errorFile(errorFilename);
                errorFile << "Error: invalid number for key -a!" << endl;
                cerr << "Error: invalid number for key -a! Check " << errorFilename << endl;
                return 1;
            }
            N = atoi(argv[++i]);
            hasA = true;
        }
        else if (arg == "-b") {
            if (i + 1 >= argc || !isInteger(argv[i + 1])) {
                ofstream errorFile(errorFilename);
                errorFile << "Error: invalid number for key -b!" << endl;
                cerr << "Error: invalid number for key -b! Check " << errorFilename << endl;
                return 1;
            }
            M = atoi(argv[++i]);
            hasB = true;
        }
        else if (arg == "-c") {
            if (i + 1 >= argc) {
                ofstream errorFile(errorFilename);
                errorFile << "Error: missing argument for key -c!" << endl;
                cerr << "Error: missing argument for key -c! Check " << errorFilename << endl;
                return 1;
            }
            string opArg = argv[i + 1];
            if (opArg.length() != 1 || (opArg[0] != '+' && opArg[0] != '-' && opArg[0] != '*' && opArg[0] != '/')) {
                ofstream errorFile(errorFilename);
                errorFile << "Error: invalid operation! Use +, -, *, /" << endl;
                cerr << "Error: invalid operation! Use +, -, *, / Check " << errorFilename << endl;
                return 1;
            }
            operation = argv[++i][0];
            hasC = true;
        }
        else if (arg == "-d") {
            if (i + 1 >= argc) {
                ofstream errorFile(errorFilename);
                errorFile << "Error: missing argument for key -d!" << endl;
                cerr << "Error: missing argument for key -d! Check " << errorFilename << endl;
                return 1;
            }
            outputFilename = argv[++i];
        }
        else if (arg == "-e") {
            if (i + 1 >= argc) {
                ofstream errorFile(errorFilename);
                errorFile << "Error: missing argument for key -e!" << endl;
                cerr << "Error: missing argument for key -e! Check " << errorFilename << endl;
                return 1;
            }
            errorFilename = argv[++i];
        }
        else {
            ofstream errorFile(errorFilename);
            errorFile << "Error: unknown key '" << arg << "'!" << endl;
            cerr << "Error: unknown key '" << arg << "'! Check " << errorFilename << endl;
            return 1;
        }
    }

    if (!hasA || !hasB || !hasC) {
        ofstream errorFile(errorFilename);
        errorFile << "Error: missing required keys! Use -a, -b, -c" << endl;
        cerr << "Error: missing required keys! Use -a, -b, -c Check " << errorFilename << endl;
        return 1;
    }

    ofstream outputFile(outputFilename);
    outputFile << "Result: " << N << " " << operation << " " << M << " = ";

    if (operation == '+') {
        outputFile << N + M << endl;
        cout << "Result: " << N << " + " << M << " = " << N + M << endl;
    }
    else if (operation == '-') {
        outputFile << N - M << endl;
        cout << "Result: " << N << " - " << M << " = " << N - M << endl;
    }
    else if (operation == '*') {
        outputFile << N * M << endl;
        cout << "Result: " << N << " * " << M << " = " << N * M << endl;
    }
    else if (operation == '/') {
        if (M == 0) {
            ofstream errorFile(errorFilename);
            errorFile << "Error: division by zero!" << endl;
            cerr << "Error: division by zero! Check " << errorFilename << endl;
            return 1;
        }
        outputFile << (double)N / M << endl;
        cout << "Result: " << N << " / " << M << " = " << (double)N / M << endl;
    }

    cout << "Result saved to: " << outputFilename << endl;
    return 0;
}