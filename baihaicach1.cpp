#include <iostream>
using namespace std;
int josephus(int n, int k) {
    int a = 1;
    for (int i = 1; i <= n; i++) {
        a = (a + k - 1) % i + 1;
    }
    return a;
}
int main() {
    cout << josephus(5, 2);
}