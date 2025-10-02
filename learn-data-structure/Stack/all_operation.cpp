#include <iostream>
#define endl '\n'

using namespace std;

const int MAX = 100; // Maximum size of the stack

// A simple stack implementation using a fixed-size array
class Stack {
private:
    int arr[MAX];   // Array to store stack elements
    int topIndex;   // Index of the top element

public:
    // Constructor: initialize the stack as empty
    Stack() {
        topIndex = -1;
    }

    // Push an element onto the stack
    void push(int x) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    // Remove the top element from the stack
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    // Return the top element without removing it
    int peek() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Return the current size of the stack
    int size() {
        return topIndex + 1;
    }

    // Print all elements of the stack from top to bottom
    void printStack() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top → bottom): ";
        for (int i = topIndex; i >= 0; --i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    // Example usage
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(25);

    st.printStack();             // Stack elements (top -> bottom): 30 20 10
    cout << "Top element: " << st.peek() << endl; // Top element: 30
    cout << "Stack size: " << st.size() << endl; // Stack size: 3

    // st.pop();
    st.printStack();             // Stack elements (top -> bottom): 20 10
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl; // No

    return 0;
}
