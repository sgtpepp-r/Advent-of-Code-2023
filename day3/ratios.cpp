#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

unsigned int _getSum(vector<string> fullGrid) {
    int Sum = 0;
    string strNum = "";
    int firstDigit = -1;
    bool helper = false;

    for (int i = 0; i<fullGrid.size(); i++) {
        for (int j = 0; j<fullGrid[i].size(); j++) {
            if (isdigit(fullGrid[i][j])) {
                strNum += fullGrid[i][j];
                if (firstDigit == -1) {
                    firstDigit = j;
                }
                if (!isdigit(fullGrid[i][j+1])) {
                    int lastDigit = j;
                    for (int k = firstDigit - (int(firstDigit!=0)); k<=lastDigit + (int(lastDigit!=fullGrid[i].size()-1)); k++) {
                        for (int l = i-(int(i!=0)); l<=(i+(int(i!=fullGrid.size()-1))); l++) {
                            if (!isdigit(fullGrid[l][k]) && fullGrid[l][k] != '.') {
                                Sum += stoi(strNum);
                                helper = true;
                                break;
                            }
                        }
                        if (helper) {
                            break;
                        }
                    }
                    firstDigit = -1;
                    strNum = "";
                    helper = false;
                }     
            }
        }
    }
    return Sum;
}

int _getGears(vector<string> fullGrid) {
    string strNum = "";
    vector<int> gearVec;
    int gearRatio;
    int gearSum = 0;

    for (int i = 0; i<fullGrid.size(); i++) {
        for (int j = 0; j<fullGrid[i].size(); j++) {
            if (fullGrid[i][j] == '*') {
                for (int k = i - (int(i!=0)); k<=i + (int(i!=fullGrid[i].size()-1)); k++) {
                    for (int l = j-(int(i!=0)); l<=(j+(int(j!=fullGrid.size()-1))); l++) {
                        if (isdigit(fullGrid[k][l])) {
                            if (l == j-1) {
                                int m = l-1;
                                while(isdigit(fullGrid[k][m])) {
                                    strNum = fullGrid[k][m] + strNum;
                                    m--;
                                }
                            }
                            while(isdigit(fullGrid[k][l])) {
                                strNum += fullGrid[k][l];
                                l++;
                            }
                            gearVec.push_back(stoi(strNum));  
                            strNum = "";
                        } 
                    }
                }
                if(gearVec.size()==2) {
                    gearRatio = gearVec[0] * gearVec[1];
                    gearSum += gearRatio;
                }
                gearVec.clear();
            }
        }
    }
    return gearSum;
}

int main() {

    ifstream IF("day3.txt");
    string text;
    vector<string> fullGrid;
    unsigned int Sum;
    unsigned int gearSum;

    while(getline(IF, text)) {
        fullGrid.push_back(text);
    }

    Sum = _getSum(fullGrid);
    cout<<Sum<<endl;

    gearSum = _getGears(fullGrid);
    cout<<gearSum<<endl;

    return 0;
}