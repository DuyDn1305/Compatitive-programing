#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c;

    a = 1;
    b = 1;
    cout << a << " ";
    cout << b << " ";
    for (int i = 1; i <= 8; ++i) {
        // output answer
        c = a+b;
        cout << c << " ";
        // swap position
        a = b;
        b = c;
    }

    printf("HEllo world");
    return 0;
}
