// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "tstack.h"

int main() {
    std::string infix = "(2+2)*(3-1)";
    std::string postfix = infx2pstfx(infix);
    int result = eval(postfix);

    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
