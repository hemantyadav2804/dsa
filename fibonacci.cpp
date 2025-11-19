
#include <iostream>
using namespace std;

int fibonacci(int n) {      // Recursive function
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int choice, n;

    cout << "1. Fibonacci using Recursion\n";
    cout << "2. Fibonacci without Recursion\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the range: ";
    cin >> n;

    switch(choice) {
        case 1:
            cout << "Fibonacci Series (Recursion): ";
            for (int i = 0; i < n; i++) {
                cout << fibonacci(i) << " ";
            }
            break;

        case 2:
            cout << "Fibonacci Series (Non-Recursion): ";
            int a = 0, b = 1;
            for (int i = 0; i < n; i++) {
                cout << a << " ";
                int c = a + b;
                a = b;
                b = c;
            }
            break;

        default:
            cout << "Invalid Choice!";
    }

    return 0;
}

/*
---------------------------------------------------------
            EXPLANATION (BEGINNER FRIENDLY)
---------------------------------------------------------

1) What is Fibonacci Series?
   A sequence where each number = sum of previous two numbers.
   Starts like: 0, 1, 1, 2, 3, 5, 8, 13...

---------------------------------------------------------
2) Recursion Method (Choice 1):
   - Function calls itself.
   - fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
   - Easy to understand but slower (more function calls).

---------------------------------------------------------
3) Non-Recursive Method (Choice 2):
   - Uses simple loop.
   - Very fast.
   - Stores 2 numbers (a and b) and keeps adding them.

---------------------------------------------------------
4) Real-Time Uses of Fibonacci:
   ✔ Used in computer algorithms (divide & conquer, trees)
   ✔ Used in stock market technical analysis
   ✔ Used in nature (sunflower seeds, pinecones, shells)
   ✔ Used in graphics (spirals, golden ratio)
   ✔ Used in dynamic programming and coding interviews
   ✔ Used in cryptography and hashing techniques

---------------------------------------------------------
*/
