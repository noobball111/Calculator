#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printArray(vector<string> arr, int size) {
    cout << "array: ";
    for (int i = 0; i < size; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

string CustomSplit(string str) {
    int counter = 0;
    vector<string> splitted = {};

    while (str != "") {
        string character = "";
        character = str[0];

        if (character == "+") {
            counter += 2;
            splitted[counter - 1] = "";
            splitted[counter - 1] += character;
            //splitted.push_back(character);
            str = str.substr(1);
        } else if (character == "-") {
            counter += 2;
            splitted[counter - 1] = "";
            splitted[counter - 1] += character;
            //splitted.push_back(character);
            str = str.substr(1);
        } else if (character == "*") {
            counter += 2;
            splitted[counter - 1] = "";
            splitted[counter - 1] += character;
            //splitted.push_back(character);
            str = str.substr(1);
        } else if (character == "/") {
            counter += 2;
            splitted[counter - 1] = "";
            splitted[counter - 1] += character;
            //splitted.push_back(character);
            str = str.substr(1);
        } else if (character == "(") {
            string ReversedStr = str;
            reverse(ReversedStr.begin(), ReversedStr.end());
            int CloseParenthesisPosition = ReversedStr.find(")");
            splitted[counter] = "";
            splitted[counter] += str.substr(1, str.length() - CloseParenthesisPosition - 2);
            str = str.substr(str.length() - CloseParenthesisPosition);
            switch (CloseParenthesisPosition){
                case 0:
                    break;
                default:
                    counter += 1;
            }
        } else {
            splitted[counter] = (splitted[counter] == "");
            splitted[counter] += character;
            str = str.substr(1, -1);
        }
    }

    //printArray(splitted, sizeof(splitted) / sizeof(splitted[0]));

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
    calc("1+1");
}
