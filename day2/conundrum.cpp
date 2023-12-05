#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Colours {
    int red, green, blue;
};

struct Games {
    int gameID;
    vector<Colours> rounds;

};

void _getGame(string text, Games* g){
    text += ';';
    string stringID = "";
    string colourString = "";
    string roundString = "";
    int i;

    // get game ID
    for (i = 0; i<text.size(); i++) {
        if (text[i] == ':') {
            g->gameID = stoi(stringID);  
            break;
        }
        else if (isdigit(text[i])) {
            stringID += text[i];
        }
    }  

    // get rounds
    for (i = i+1; i<text.size(); i++) {
        if (text[i] == ';') {
            Colours c = {0,0,0};
            colourString = "";
            for (int j = 0; j<roundString.size(); j++) {
                if (isdigit(roundString[j])) {
                    colourString += roundString[j];
                }
                else if (roundString[j] == ',') {
                    colourString = "";
                }
                else {
                    if (roundString.substr(j,3) == "red") {
                        c.red = stoi(colourString);
                    }
                    else if (roundString.substr(j,5) == "green") {
                        c.green = stoi(colourString);
                    }
                    else if (roundString.substr(j,4) == "blue") {
                        c.blue = stoi(colourString);
                    }
                }
            }
            g->rounds.push_back(c);
            roundString = "";
        }
        else {
            roundString += text[i];
        }
    }
}

//bool function, return ID if line if true
bool _possibleGame(Games game, Colours max) {
    for (int i = 0; i<game.rounds.size(); i++) {
        Colours cr = game.rounds[i];
        if (cr.red > max.red || cr.blue > max.blue || cr.green > max.green) {
            return false;
        }
    }
    return true;
}

int _findMinPowers(Games game) {
    int minRed = 0;
    int minGreen = 0; 
    int minBlue = 0;

    for (int i = 0; i<game.rounds.size(); i++) {
        Colours cr = game.rounds[i];
        if (cr.red > minRed) {
            minRed = cr.red;
        }
        if (cr.green > minGreen) {
            minGreen = cr.green;
        }
        if (cr.blue > minBlue) {
            minBlue = cr.blue;
        }
    }
    return minRed*minBlue*minGreen;
}

int main() {
    
    ifstream IF("day2.txt");
    string text; 
    int numGames = 100;
    int SumIDs = 0;
    int SumPowers = 0;

    Colours maxColours = {12, 13, 14};
    Games* ptr; 

    while (getline(IF, text)) {
        ptr = new Games;
        _getGame(text, ptr);
        
        if(_possibleGame(*ptr, maxColours)) {
            SumIDs += ptr->gameID;
        }

        SumPowers += _findMinPowers(*ptr);
    }
    
    cout<<"Sum of possible Game IDs: "<<SumIDs<<endl;
    cout<<"Sum of Minimum Powers: "<<SumPowers<<endl;

    return 0;
}