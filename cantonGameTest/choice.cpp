#include <iostream>     // DUH
#include <vector>       // vector (list)
#include <conio.h>
#include "choice.h"

#define KEY_UP 72       //Up arrow character
#define KEY_DOWN 80    //Down arrow character
#define KEY_ENTER '\r'//Enter key charatcer

int askSelection(int numChoices, std::vector<std::string> options) {
    int selected = 0;    //Keeps track of which option is selected.
    //int numChoices = 3; //The number of choices we have.
    bool selecting = true;//True if we are still waiting for the user to press enter.
    bool updated = false;//True if the selected value has just been updated.

    //Output options
    //std::vector<std::string> options = {"A. Option 1","B. Option 2","C. Option 3"};
    //std::cout << "A. Option 1\n";
    //std::cout << "B. Option 2\n";
    //std::cout << "C. Option 3\n";

    std::cout << "\nUse the up and down arrow keys\n";
    for (std::string n : options) {
        std::cout << n << std::endl;
    }
    std::cout << "\n";
    std::cout << "" <<options[0]<<" Is selected \n";

    char c; //Store c outside of loop for efficiency.
    while (selecting) { //As long as we are selecting...
        switch ((c = _getch())) { //Check value of the last inputed character.
            case KEY_UP:
                if (selected > 0) { //Dont decrement if we are at the first option.
                    --selected;
                    updated = true;
                }
                break;
            case KEY_DOWN:
                if (selected < numChoices - 1) { //Dont increment if we are at the last option.
                    ++selected;
                    updated = true;
                }
                break;
            case KEY_ENTER:
                //We are done selecting the option.
                selecting = false;
                break;
            default: break;
        }
        if (updated) { //Lets us know what the currently selected value is.
            std::cout << "\033[F";
            std::cout << "                                                                 \n";
            std::cout << "\033[F";
            std::cout << "Option " << (selected + 1) << " is selected. "<< options[selected] <<"\n";
            updated = false;
        }
    }
    //Lets us know what we ended up selecting.
    std::cout << "Selected :" << options[selected] << '\n';
    return selected;
}
