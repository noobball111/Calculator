#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string CustomSplit(string str) {
    int counter = 0;
    vector<string> splitted;

    while (str != "") {
        string character;
        character = str[0];

        if (character == "+") {
            counter += 2;
            splitted.push_back("");
            splitted[counter - 1] += character;
            str = str.substr(1);
        } else if (character == "-") {
            counter += 2;
            splitted.push_back("");
            splitted[counter - 1] += character;
            str = str.substr(1);
        } else if (character == "*") {
            counter += 2;
            splitted.push_back("");
            splitted[counter - 1] += character;
            str = str.substr(1);
        } else if (character == "/") {
            counter += 2;
            splitted.push_back("");
            splitted[counter - 1] += character;
            str = str.substr(1);
        } else if (character == "(") {
            string ReversedStr = str;
            reverse(ReversedStr.begin(), ReversedStr.end());
            int CloseParenthesisPosition = ReversedStr.find(")");
            splitted.push_back("");
            splitted[counter] += str.substr(1, str.length() - CloseParenthesisPosition - 2);
            str = str.substr(str.length() - CloseParenthesisPosition);
            switch (CloseParenthesisPosition){
                case 0:
                    break;
                default:
                    counter += 1;
            }
        } else {
            splitted.push_back("");
            splitted[counter] += character;
            str = str.substr(1, -1);
        }
    }

    cout << "done";

    return "";
}

int calc(string str) {
    int result = 0;
    string splitted = CustomSplit(str);

    cout << splitted << endl;

    return result;
}

int main() {
    calc("1+1");
    return 0;
}