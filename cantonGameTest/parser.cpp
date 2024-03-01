#include <vector>       // vector (list)
#include <iostream>     // DUH
#include <fstream>      // To read files
#include <windows.h>    // sleep()
//#include <ncurses.h>
#include "parser.h"

void printVect(std::vector<std::string> vect) {
    std::cout << "\nSTART OF PRINT : VECT\n";
    int i = 0;
    for (std::string vectNum : vect) {
        std::cout << i << " : " << vectNum << std::endl;
        i++;
    }
    std::cout << "\nEND OF PRINT : VECT\n";
}


std::vector<std::string> parseScript() {
    std::ifstream GSFile("main.GSF");
    std::string line;
    std::string strtemp;
    std::vector<std::string> lineVect = {"0 buffer"};

    while(GSFile >> line) {
        /*
            *e : end line
            *n : new line
        */

        if (line == "*e") {
            //cout << "\n\n";
            lineVect.push_back(strtemp);
            strtemp = "";
        }
        else if (line == "*n") {
            std::cout << R"(
 ======
 CAN NOT USE "NEW LINE".
 PLEASE USE *e TO MARK THE END OF THE LINE
 AUTOMATICLY TOOK OUT THE NEW LINE SYMBOL
                                    Thank you.
 ======
)";
        }
        else {
            strtemp.append(line + " ");
            std::cout << strtemp << std::endl;
            //lineVect.push_back(line);
        }
    }

    // print out the VECTOR
    printVect(lineVect);
    Sleep(500);
    std::cout << "\033[2J\033[1;1H";
    return lineVect;
}
