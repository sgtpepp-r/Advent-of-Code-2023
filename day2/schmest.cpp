#include <iostream>
#include <string>

using namespace std;

int main(){

    string tst = "Game 31:";
    string stringID = "";
    int gameID;

    for (int i =0; i<tst.size(); i++) {
        while (tst[i] != ':') {
            if (isdigit(tst[i])) {
                stringID += tst[i];
            }
            i++;
        }
        
    }
    gameID = stoi(stringID);
    cout<<gameID<<endl;
    //cout<<num<<endl;



    return 0;
}