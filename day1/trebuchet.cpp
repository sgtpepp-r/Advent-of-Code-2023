#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int _getDigits(string line) {

    vector<string> stringVector {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<char> numVector {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    string newline = "";
    int intNum = 0;
    int firstDigit, secondDigit;

    for(int i = 0; i<line.size(); i++) {
        for (int  j = 3; j<6; j++) {
            for (int k = 0; k<stringVector.size(); k++){
                if (line.substr(i,j) == stringVector[k]) {
                    newline += numVector[k];
                }
            }
        }
        if (!isalpha(line[i])) {
            newline += line[i];
        }
    
    }

    firstDigit = newline.front() - '0';
    secondDigit = newline.back() - '0';
    intNum = (firstDigit*10) + secondDigit;

    return intNum;
}

int main() {

    ifstream IF("day1.txt");
    string line;
    
    int sum = 0;

    while (getline(IF,line)) {
        int digits = _getDigits(line);
        sum += digits;
    }

    cout<<sum<<endl;

    return 0;
}