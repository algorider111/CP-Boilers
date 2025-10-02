#include <iostream>
using namespace std;

const int MAX = 100;

// =========================
// Stack using Array
// =========================
class ArrayStack {
private:
    int arr[MAX];    // Array to store stack elements
    int topIndex;    // Index of the top element

public:
    ArrayStack() { topIndex = -1; }

    // Push element on top
    // Time: O(1)
    void push(int x) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    // Remove top element
    // Time: O(1)
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    // Get top element without removing
    // Time: O(1)
    int peek() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    // Time: O(1)
    bool isEmpty() { return topIndex == -1; }

    // Get current size
    // Time: O(1)
    int size() { return topIndex + 1; }

    // Print stack from top to bottom
    // Time: O(n)
    void printStack() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (top --> bottom): ";
        for (int i = topIndex; i >= 0; --i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

// =========================
// Stack using Linked List
// =========================
struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* topNode; // Pointer to top node

public:
    LinkedListStack() { topNode = nullptr; }

    // Push element on top
    // Time: O(1)
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = topNode;
        topNode = newNode;
    }

    // Remove top element
    // Time: O(1)
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Get top element without removing
    // Time: O(1)
    int peek() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Check if stack is empty
    // Time: O(1)
    bool isEmpty() { return topNode == nullptr; }

    // Print stack from top to bottom
    // Time: O(n)
    void printStack() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (top --> bottom): ";
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};



int main() {
    cout << "Array Stack Example:\n";
    ArrayStack aSt;
    aSt.push(45);
    aSt.push(25);
    aSt.push(8);
    aSt.printStack();    // Output: 8 25 45 (top --> bottom)

    aSt.pop();
    aSt.printStack();    // Output: 25 45
    cout << "Top element: " << aSt.peek() << endl; // 25
    cout << "Is empty? " << (aSt.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Size: " << aSt.size() << endl; // 2

    cout << "\nLinked List Stack Example:\n";
    LinkedListStack lSt;
    lSt.push(100);
    lSt.push(200);
    lSt.push(300);
    lSt.printStack();    // Output: 300 200 100

    lSt.pop();
    lSt.printStack();    // Output: 200 100
    cout << "Top element: " << lSt.peek() << endl; // 200
    cout << "Is empty? " << (lSt.isEmpty() ? "Yes" : "No") << endl; // No

    return 0;
}
