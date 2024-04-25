#include <iostream>
using namespace std;
// Function prototypes
void menu();
void addFraction(int a, int b, int c, int d);
void subtractFraction(int a, int b, int c, int d);
void multiplyFraction(int a, int b, int c, int d);
void divideFraction(int a, int b, int c, int d);
int gcd(int a, int b);
void simplifyAndDisplay(int num, int den);
int main() {
    while (true) {
        menu(); // Display menu and get choice
    }
    return 0;
}
void menu() {
    int choice;
    int a, b, c, d;
    cout << "Fraction Calculator\n";
    cout << "1. Add Fractions\n";
    cout << "2. Subtract Fractions\n";
    cout << "3. Multiply Fractions\n";
    cout << "4. Divide Fractions\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    if (choice < 1 || choice > 5 || cin.fail()) {
        cout << "Invalid choice, please try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    if (choice == 5) {
        exit(0);
    }
    cout << "Enter numerator and denominator for the first fraction: ";
    cin >> a >> b;
    if (cin.fail() || b == 0) {
        cout << "Invalid input, denominators must be non-zero. Please restart.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cout << "Enter numerator and denominator for the second fraction: ";
    cin >> c >> d;
    if (cin.fail() || d == 0) {
        cout << "Invalid input, denominators must be non-zero. Please restart.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    switch (choice) {
        case 1: addFraction(a, b, c, d); break;
        case 2: subtractFraction(a, b, c, d); break;
        case 3: multiplyFraction(a, b, c, d); break;
        case 4: divideFraction(a, b, c, d); break;
    }
}
void addFraction(int a, int b, int c, int d) {
    // a/b + c/d = (a*d + b*c) / (b*d)
    int num = a * d + b * c;
    int den = b * d;
    simplifyAndDisplay(num, den);
}
void subtractFraction(int a, int b, int c, int d) { # type: ignore
    // a/b - c/d = (a*d - b*c) / (b*d)
    int num = a * d - b * c;
    int den = b * d;
    simplifyAndDisplay(num, den);
}
void multiplyFraction(int a, int b, int c, int d) {
    // (a/b) * (c/d) = (a*c) / (b*d)
    int num = a * c;
    int den = b * d;
    simplifyAndDisplay(num, den);
}
void divideFraction(int a, int b, int c, int d) {
    // (a/b) / (c/d) = (a*d) / (b*c)
    if (c == 0) {
        cout << "Cannot divide by zero.\n";
        return;
    }
    int num = a * d;
    int den = b * c;
    simplifyAndDisplay(num, den);
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void simplifyAndDisplay(int num, int den) {
    int common_divisor = gcd(num, den);
    num /= common_divisor;
    den /= common_divisor;
    cout << "Result: " << num << "/" << den << endl;
}
