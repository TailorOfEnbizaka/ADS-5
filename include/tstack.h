// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
private:
  T data[size];
  int top;
public:
  TStack() : top(0) {}
  void posh(const T& item) {
    if (top <= size - 1)
      data[top++] = item;
    else
      throw std::string("Full!");
  }
  T get() const {
    return data[top];
  }
  T pop() {
    if (top > 0)
      return data[--top];
    throw std::string("Empty");
  }
  bool Empty() {
    return top == -1;
  }
};
#endif  // INCLUDE_TSTACK_H_
