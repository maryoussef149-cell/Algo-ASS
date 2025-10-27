#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Recursion
long long fibRecursion(int n, long long a = 0, long long b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibRecursion(n - 1, b, a + b);
}



//Matrix Multiplication
struct Matrix {
    long long a, b, c, d;
};


Matrix multiply(Matrix x, Matrix y) {
    return {
        x.a * y.a + x.b * y.c,
        x.a * y.b + x.b * y.d,
        x.c * y.a + x.d * y.c,
        x.c * y.b + x.d * y.d
    };
}


Matrix Powering(Matrix base, int n) {
    if (n == 1)
        return base;
    if (n % 2 == 0) {
        Matrix half = Powering(base, n / 2);
        return multiply(half, half);
    } else {
        return multiply(base, Powering(base, n - 1));
    }
}

long long fibMatrix(int n) {
    if (n == 0)
        return 0;
    Matrix F = {1, 1, 1, 0};
    Matrix result = Powering(F, n - 1);
    return result.a;
}

//Dynamic Programming
unordered_map<int, long long> store;

long long fibonacci(int n) {
    if (n == 0)
        return n;
    if (n == 1)
        return n;

    long long a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;  
        a = b;      
        b = c;
    }

    return b;
}


int main() {
    int n;
    cout << "Enter a number to calculate its Fibonacci: ";
    cin >> n;

    cout << "Recursion Method: " << fibRecursion(n) << endl;
    cout << "Matrix Multiplication Method: " << fibMatrix(n) << endl;
    cout << "Dynamic Programming Method: " << fibonacci(n) << endl;

    return 0;
}
