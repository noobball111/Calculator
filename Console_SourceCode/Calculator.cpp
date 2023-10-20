#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

void printArray(vector <string> arr) {
    cout << "array: ";
    for (const string& str : arr){
        cout << "[" + str + "] ";
    }
    cout << endl;
}

vector<string> Split(string str) {
    int counter = 0;
    vector<string> splitted;



    return splitted;
}

double calculate(double x, double y, string Operator) {
    if (Operator == "+")
        return x+y;
    else if (Operator == "-")
        return x-y;
    else if (Operator == "*")
        return x*y;
    else if (Operator == "/")
        return x/y;
    else if (Operator == "//")
        return floor(x/y);
    else if (Operator == "%")
        return (x/y - floor(x/y))*y;
    else
        throw runtime_error("Invalid operator");
}

int calc(string str) {
//    find parenthesis
    if (str.find('(') != -1) {
        cout << "parenthesis found\n";
    }

    int multiply = str.find('*');
    int division = str.find('/');
    int Plus = str.find('+');
    int Minus = str.find('-');

    multiply = multiply == -1 ? numeric_limits<int>::max() : multiply;
    division = division == -1 ? numeric_limits<int>::max() : division;

    if (multiply < division && multiply > 0){
        int Lpointer = multiply-1;
        int Rpointer = multiply+1;
        string LeftStr = "";
        string RightStr = "";
        while (isdigit(str[Lpointer])){
            LeftStr += str[Lpointer];
            Lpointer -= 1;
        }
        while (isdigit(str[Rpointer])){
            RightStr += str[Rpointer];
            Rpointer += 1;
        }
        str = str.substr(0, Lpointer+1) + to_string(int(calculate(stod(LeftStr), stod(RightStr), "*"))) + str.substr(Rpointer);
    } else if (multiply > division && division > 0){
        int Lpointer = division-1;
        int Rpointer = division+1;
        string LeftStr = "";
        string RightStr = "";
        while (isdigit(str[Lpointer])){
            LeftStr += str[Lpointer];
            Lpointer -= 1;
        }
        while (isdigit(str[Rpointer])){
            RightStr += str[Rpointer];
            Rpointer += 1;
        }
        str = str.substr(0, Lpointer+1) + to_string(int(calculate(stod(LeftStr), stod(RightStr), "/"))) + str.substr(Rpointer);
    } else if (Plus < Minus && Plus > 0){
        int Lpointer = Plus-1;
        int Rpointer = Plus+1;
        string LeftStr = "";
        string RightStr = "";
        while (isdigit(str[Lpointer])){
            LeftStr += str[Lpointer];
            Lpointer -= 1;
        }
        while (isdigit(str[Rpointer])){
            RightStr += str[Rpointer];
            Rpointer += 1;
        }
        str = str.substr(0, Lpointer+1) + to_string(int(calculate(stod(LeftStr), stod(RightStr), "+"))) + str.substr(Rpointer);
    } else if (Plus > Minus && Minus > 0){
        int Lpointer = Minus-1;
        int Rpointer = Minus+1;
        string LeftStr = "";
        string RightStr = "";
        while (isdigit(str[Lpointer])){
            LeftStr += str[Lpointer];
            Lpointer -= 1;
        }
        while (isdigit(str[Rpointer])){
            RightStr += str[Rpointer];
            Rpointer += 1;
        }
        str = str.substr(0, Lpointer+1) + to_string(int(calculate(stod(LeftStr), stod(RightStr), "-"))) + str.substr(Rpointer);
    }
    if (str.find('(') || str.find('+') || str.find('-') || str.find('*') || str.find('/')) {
        str = calc(str);
    }

    cout << str;

    return stoi(str);
}

int main() {
    // cout << calc("(((((10 + 5) * 2) - 7) / 3) + (((12 * 4) - 2) / (7 + 1)) - ((((6 - 3) * 5) + 2) * ((9 / 3) + 1))) + (((((15 - 5) * 2) + 4) / 2) - ((10 * 3) + 2))");
    calc("1+1+2/2+1");
}
