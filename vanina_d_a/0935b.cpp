#include <iostream>
#include <string>

int main() {
    int n = 0;//количество ходов
    int x = 0;
    int y = 0;
    int count = 0;
    std::cin >> n;

    std::string path;//U or R
    for (int i = 0; i < n; i++) {
        char temp;
        std::cin >> temp;
        path.push_back(temp);
    }


    int r = 0;//количество R
    int u = 0;//кол-во U
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (path[i] == 'R') {
            r++;
        }
        else { 
            u++;
        }
        if (r == u)
        {
            if (path[i + 1] == path[i]) {
                ans++;
            }
        }
    }
    std::cout << ans;
    return 0;
}
