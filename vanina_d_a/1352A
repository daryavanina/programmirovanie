#include<iostream>//5673
int main() {
    int n, vs;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int del, cnt;//5673 5009 3071
    for (int i = 0; i < n; i++) {
        vs = a[i];
        del = 10;
        cnt = 0;
        while (vs > 0) {
            if (vs % del != 0) {
                cnt++;
                vs -= vs % del;
            }
            del *= 10;
        }
        std::cout << cnt << '\n';
        vs = a[i];
        del = 10;
        while (vs > 0) {
            if (vs % del != 0) {
                std::cout << vs % del << ' ';
                vs -= vs % del;
            }
            del *= 10;
        }
        std::cout << '\n';
    }

}
