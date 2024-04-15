// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int prior_op(char str) {
	if (str == '+' || str == '-')
		return 1;
	else if (str == '*' || str == '/')
		return 2;
	return 0;
}
int summa(int a, int b, char str) {
	if (str == '+')
		return a + b;
	else if (str == '-')
		return a - b;
	else if (str == '*')
		return a * b;
	else if (str == '/')
		return a / b;
}
std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
  std::string post_str;
TStack<char, 100> stack;
for (char str : inf) {
	if (isdigit(str)) {
		post_str += str;
		post_str += ' ';
	}
	else if (str == '+' || str == '-' || str == '*' || str == '/') {
		while (!stack.Empty()) {
			if (prior_op(stack.get()) >= prior_op(str)) {
				post_str += stack.get();
				post_str += ' ';
				stack.pop();
			}
		}
		stack.posh(str);
	}
	else if(str=='(')
		stack.posh(str);
	else if (str == ')') {
		while (!stack.Empty() && stack.get() != '(') {
			post_str += stack.get();
			post_str += ' ';
			stack.pop();
		}
		stack.pop();
	}
}
while (!stack.Empty()) {
	post_str += stack.get();
	post_str += ' ';
	stack.pop();
}
if (!post_str.empty()) {
	post_str.pop_back();
}
return post_str;
}

int eval(std::string pref) {
  // добавьте код
  TStack <int, 100> stack;
int a, b;
for (char str:post) {
	if (std::isdigit(str))
		stack.posh(str);
	else if (str == '+' || str == '-' || str == '*' || str == '/') {
		a = stack.pop();
		b = stack.pop();
		stack.posh(summa(a, b, str));
	}
}
return stack.pop();
  return 0;
}
