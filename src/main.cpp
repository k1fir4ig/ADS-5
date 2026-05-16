// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "tstack.h"

std::string infx2pstfx(const std::string& inf);
int eval(const std::string& pref);

int main() {
  std::string infixExpr = "(2+2)*(3-1)";
  std::string postfixExpr = infx2pstfx(infixExpr);
  int calcResult = eval(postfixExpr);

  std::cout << "Infix: " << infixExpr << std::endl;
  std::cout << "Postfix: " << postfixExpr << std::endl;
  std::cout << "Result: " << calcResult << std::endl;

  return 0;
}
