#include<iostream>
int main() {
    int a[5][5];
    int ind1, ind2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> a[i][j];
            if (a[i][j] == 1)
            {
                ind1 = i;
                ind2 = j;
            }
        }
    }
    std::cout << abs(2 - ind1) + abs(2 - ind2);
}
