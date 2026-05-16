// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getOpPriority(char op) {
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string postfix = "";
  int len = inf.length();

  for (int i = 0; i < len; ++i) {
    char ch = inf[i];

    if (ch == ' ') continue;

    if (ch >= '0' && ch <= '9') {
      if (!postfix.empty() && postfix.back() != ' ') {
        postfix += ' ';
      }
      while (i < len && (inf[i] >= '0' && inf[i] <= '9')) {
        postfix += inf[i];
        ++i;
      }
      --i;
    } else if (ch == '(') {
      stack.push(ch);
    } else if (ch == ')') {
      while (!stack.isEmpty() && stack.peek() != '(') {
        postfix += ' ';
        postfix += stack.pop();
      }
      stack.pop();
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      while (!stack.isEmpty() &&
             getOpPriority(stack.peek()) >= getOpPriority(ch)) {
        postfix += ' ';
        postfix += stack.pop();
      }
      stack.push(ch);
    }
  }

  while (!stack.isEmpty()) {
    postfix += ' ';
    postfix += stack.pop();
  }

  return postfix;
}

int eval(const std::string& pref) {
  TStack<int, 100> stack;
  int len = pref.length();

  for (int i = 0; i < len; ++i) {
    if (pref[i] == ' ') continue;

    if (pref[i] >= '0' && pref[i] <= '9') {
      int num = 0;
      while (i < len && (pref[i] >= '0' && pref[i] <= '9')) {
        num = num * 10 + (pref[i] - '0');
        ++i;
      }
      --i;
      stack.push(num);
    } else if (pref[i] == '+' || pref[i] == '-' ||
               pref[i] == '*' || pref[i] == '/') {
      int r = stack.pop();
      int l = stack.pop();

      if (pref[i] == '+') stack.push(l + r);
      else if (pref[i] == '-') stack.push(l - r);
      else if (pref[i] == '*') stack.push(l * r);
      else if (pref[i] == '/') stack.push(l / r);
    }
  }

  return stack.pop();
}
