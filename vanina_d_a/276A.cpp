#include<iostream>
int main()
{
    int n, k;
    std::cin >> n >> k;
    int f, t, maxf=-10000000000,tekf;
    for(int i=0; i < n; i++)
    {
        std::cin >> f >> t;
        if (t > k)
            tekf = f - t + k;
        else
            tekf = f;
        maxf = std::max(maxf, tekf);
    }
    std::cout << maxf;
}
