// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int SIZE>
class TStack {
private:
    T data[SIZE];
    int top;

public:
    TStack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == SIZE - 1;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        data[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return data[top--];
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[top];
    }
};

#endif  // INCLUDE_TSTACK_H_
