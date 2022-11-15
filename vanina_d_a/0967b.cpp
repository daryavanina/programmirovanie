#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n = 0;
    int a = 0, b = 0;
    int ans = 0;
    int holes = 0;
    std::cin >> n >> a >> b;
    std::vector <int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    int sum = a * v[0];
    std::sort(v.begin()+1, v.end());
    for (int j = 0; j < n; j++)
    {
        ans += v[j];
        if (sum / ans >= b)
            holes = j + 1;
    }
    std::cout << n - holes << std::endl;
}
