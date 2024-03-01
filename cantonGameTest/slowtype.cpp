#include <iostream>     // DUH
#include <windows.h>    // Sleep()
#include "slowtype.h"

// SLOW Type Face
int slowPrint(std::string output, int inter = 200) {
    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i];
        Sleep(inter);
    }
    std::cout << "\n";
    return 0;
}


