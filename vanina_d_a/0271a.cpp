#include<iostream>
int main() {
    int i;
    std::cin >> i;
    for (int a = i + 1; i <= 9000; a++) {
        int s1 = a / 1000;
        int s2 = a % 1000 / 100;
        int s3 = a % 100 / 10;
        int s4 = a % 10;
        if (s1 == s2) continue;
        if (s1 == s3) continue;
        if (s1 == s4) continue;
        if (s2 == s3) continue;
        if (s2 == s4) continue;
        if (s3 == s4) continue;
        std::cout << a;
        break;
    }
}
