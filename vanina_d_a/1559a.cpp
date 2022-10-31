#include<iostream>
#include<vector>
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        int el;
        std::cin >> n;
        std::vector <int> arr = {};
        for (int i = 0; i < n; i++) {
            std::cin >> el;
            arr.push_back(el);
        }
        int res = arr[0];

        for (int i = 1; i < n; i++) {
            res &= arr[i];
        }
        std::cout << res << std::endl;
    }

}
