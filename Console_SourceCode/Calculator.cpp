#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printArray(vector < string > arr, int size) {
    cout << "array: ";
    for (int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

vector < string > check(vector < string > splitted, string currentElement, int Parentthesis, string str) {
    if (!currentElement.empty()) {
        switch (Parentthesis) {
        case 0:
            splitted.push_back(currentElement);
        case 1:
            splitted[splitted.size() - 1] += currentElement;
        }
    }

    if (!str.empty()) {

        switch (Parentthesis) {
        case 0:
            splitted.push_back(str);
        case 1:
            splitted[splitted.size() - 1] += str;
        }
    }

    return splitted;
}

string CustomSplit(string str) {
    vector < string > splitted;
    string currentElement;
    int Parentthesis = 0;

    for (char character: str) {
        if (character == '+' || character == '-' || character == '*' || character == '/') {
             string OperatorStr(1, character);
            splitted = check(splitted, currentElement, Parentthesis, OperatorStr);

            currentElement.clear();
        } else if (character == '(') {
            splitted = check(splitted, currentElement, Parentthesis, "(");
            currentElement.clear();

            // splitted.push_back("(");
            Parentthesis = 1;
        } else if (character == ')') {
            splitted = check(splitted, currentElement, Parentthesis, ")");
            currentElement.clear();

            // splitted.push_back(")");
            Parentthesis = 0;
        } else if (isdigit(character)) {
            currentElement += character;
        }
    }

    splitted = check(splitted, currentElement, Parentthesis, "");

    printArray(splitted, splitted.size());
    cout << "done";

    return "";
}

int calc(string str) {
    int result = 0;
    string splitted = CustomSplit(str);

    cout << splitted << endl;

    // int size = sizeof(splitted) / sizeof(splitted[0]);
    // for (int i = 0; i < size; i++) {
    //     cout << "[" << splitted[i] << "] ";
    // }

    cout << endl;

    return result;
}

int main() {
    // cout << calc("(((((10 + 5) * 2) - 7) / 3) + (((12 * 4) - 2) / (7 + 1)) - ((((6 - 3) * 5) + 2) * ((9 / 3) + 1))) + (((((15 - 5) * 2) + 4) / 2) - ((10 * 3) + 2))");
    calc("((94)*343+5435)");
}