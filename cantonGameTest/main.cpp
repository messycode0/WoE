/*
    THIS GAME IS FOR MR.CANTON PROJECT
    GAME NAME:
    CODE EDITORS: JACOB, NATALIE
    WRITERS: EVERYONE ELSE...

    DOES NOT NEED TO BE MODULER
*/
#include <iostream>     // DUH
#include <vector>       // vector (list)

#include "parser.h"
#include "slowtype.h"
#include "choice.h"



void clsscrn() {std::cout << "\033[2J\033[1;1H";}

int main() {
    std::cout << "Game Start" << std::endl;

    std::vector<std::string> parsedScriptVect = parseScript();
    //clsscrn();

    std::cout << R"(
                    _     _          __            _
                   | |   | |        / _|          | |
__      _____  _ __| | __| |   ___ | |_    ___  __| | __ _  ___ _ __ ___
\ \ /\ / / _ \| '__| |/ _` |  / _ \|  _|  / _ \/ _` |/ _` |/ _ \ '__/ __|
 \ V  V / (_) | |  | | (_| | | (_) | |   |  __/ (_| | (_| |  __/ |  \__ \
  \_/\_/ \___/|_|  |_|\__,_|  \___/|_|    \___|\__,_|\__, |\___|_|  |___/
     Under Development, Alpha                         __/ |
                       Miguel INC                    |___/
)";

    std::cout << "\n\n";
    /*
    for (int i = 1; i <= 8; i++) {
        slowPrint(parsedScriptVect[i], 1);
        std::cout << "\n";
    }
    */

    slowPrint(parsedScriptVect[1], 5);
    int foo = askSelection(3, {parsedScriptVect[2], parsedScriptVect[3], parsedScriptVect[4]});
    if (foo == 0) {
        std::cout << R"(
  ___________________
:' ,__________,  ':  `.
| '            `  |    `.
| |  Hello     |  |      `.
| |            |  |        \
| |  (World )  |  |         ]
| |            |  |~~~~~~.  )
| `,__________,'  |\__O\_| ,'
|    _______      |     \.`
|<> [___=___](@)<>|    .'\
':________________/__.'   )
   (____________)        /
                        /
              _________/
  ___________/______
 /''''=========='(@)\___
 |[][][][][][][][][]|   \ _______
 |[][][][][][][][][]|    \__     \
 |[][][][][][][][][]|    |  \..  |
 \------------------/    | ( # ) |
                         |  '''  |
                         \_______/

)";
    }

    return 0;
    // hi
}
