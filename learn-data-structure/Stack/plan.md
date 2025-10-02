### 🔹 Basics

* What a stack is (LIFO principle – Last In, First Out)
* Common real-life examples (undo operations, browser back button, plate stacking)
* Difference between **stack** and **queue**

### 🔹 Core Operations

* **push(x):** insert an element at the top
* **pop():** remove the top element
* **top()/peek():** get the top element without removing
* **isEmpty():** check if stack is empty
* **size():** return number of elements

### 🔹 Implementations

1. **Using arrays (static stack)**
2. **Using linked list (dynamic stack)**
3. **Using STL (C++ `std::stack`) or Java/Python built-in stacks**

### 🔹 Applications of Stack

* Expression evaluation:

  * Infix → Postfix/Prefix conversion
  * Postfix/Prefix expression evaluation
* Balanced parentheses checking
* Undo/Redo operations
* Function call/recursion tracking
* Backtracking problems (e.g., maze solving, N-Queens)
* Browser history / text editor operations
* Monotonic stacks (used in many **competitive programming** problems, e.g., "Next Greater Element")

### 🔹 Advanced Usage in Competitive Programming

* Stack-based DP (some interval DP problems)
* Histogram largest rectangle problem
* Stock span problem
* Sliding window minimum/maximum (with monotonic stack/queue)
