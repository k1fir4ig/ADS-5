// Copyright 2025 NNTU-CS
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>
#include "tstack.h"

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> stack;
    std::string postfix;
    bool prevWasDigit = false;

    for (char ch : inf) {
        if (isspace(ch)) {
            continue;
        }

        if (isdigit(ch)) {
            if (prevWasDigit) {
                postfix += ch;
            } else {
                if (!postfix.empty()) {
                    postfix += ' ';
                }
                postfix += ch;
            }
            prevWasDigit = true;
        } else {
            prevWasDigit = false;

            if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix += ' ';
                    postfix += stack.pop();
                }
                if (stack.isEmpty()) {
                    throw std::runtime_error("Mismatched parentheses");
                }
                stack.pop(); // Удаляем '(' из стека
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                while (!stack.isEmpty() && getPriority(stack.peek()) >= getPriority(ch)) {
                    postfix += ' ';
                    postfix += stack.pop();
                }
                stack.push(ch);
            }
        }
    }

    while (!stack.isEmpty()) {
        if (stack.peek() == '(') {
            throw std::runtime_error("Mismatched parentheses");
        }
        postfix += ' ';
        postfix += stack.pop();
    }

    return postfix;
}

int eval(const std::string& post) {
    TStack<int, 100> stack;
    std::istringstream iss(post);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            if (stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
            int rhs = stack.pop();
            if (stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
            int lhs = stack.pop();

            switch (token[0]) {
                case '+': stack.push(lhs + rhs); break;
                case '-': stack.push(lhs - rhs); break;
                case '*': stack.push(lhs * rhs); break;
                case '/': 
                    if (rhs == 0) throw std::runtime_error("Division by zero");
                    stack.push(lhs / rhs); 
                    break;
                default:
                    throw std::runtime_error("Unknown operator");
            }
        }
    }

    if (stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
    int result = stack.pop();
    if (!stack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
    return result;
}
