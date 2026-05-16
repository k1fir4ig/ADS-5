// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int kSize>
class TStack {
 private:
  T data[kSize];
  int top_index;

 public:
  TStack() : top_index(-1) {}

  bool isEmpty() const {
    return top_index == -1;
  }

  bool isFull() const {
    return top_index == kSize - 1;
  }

  void push(const T& value) {
    if (!isFull()) {
      data[++top_index] = value;
    }
  }

  T pop() {
    if (!isEmpty()) {
      return data[top_index--];
    }
    return T();
  }

  T peek() const {
    if (!isEmpty()) {
      return data[top_index];
    }
    return T();
  }
};

#endif  // INCLUDE_TSTACK_H_
