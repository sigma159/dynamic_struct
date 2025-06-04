#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000;

class SimpleStack {
private:
    char data[MAX];
    int positions[MAX];
    int top;

public:
    SimpleStack() : top(-1) {}

    void push(char value, int pos) {
        if (top < MAX - 1) {
            top++;
            data[top] = value;
            positions[top] = pos;
        }
    }

    void pop() {
        if (top >= 0)
            top--;
    }

    char peek() {
        return (top >= 0) ? data[top] : '\0';
    }

    int peekPos() {
        return (top >= 0) ? positions[top] : -1;
    }

    bool empty() {
        return top == -1;
    }
};

bool isOpening(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosing(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool match(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

void checkBrackets(const string& input) {
    SimpleStack stack;
    int errorPos = -1;

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];

        if (isOpening(ch)) {
            stack.push(ch, i);
        }
        else if (isClosing(ch)) {
            if (stack.empty()) {
                errorPos = i;
                break;
            }
            else if (!match(stack.peek(), ch)) {
                errorPos = i;
                break;
            }
            else {
                stack.pop();
            }
        }
        else if (ch == ';') {
            break;
        }
    }

    if (errorPos != -1) {
        cout << "Помилка на позиції " << errorPos << ":\n";
        cout << input.substr(0, errorPos + 1) << endl;
    }
    else if (!stack.empty()) {
        cout << "Відкриваюча дужка без пари на позиції " << stack.peekPos() << ":\n";
        cout << input.substr(0, stack.peekPos() + 1) << endl;
    }
    else {
        cout << "Рядок коректний — дужки розставлені правильно.\n";
    }
}

int main() {
    string input;
    cout << "Введіть рядок (завершіть символом ';'):\n";
    getline(cin, input);

    checkBrackets(input);

    return 0;
}
