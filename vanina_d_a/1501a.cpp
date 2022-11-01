#include<iostream>
int main()
{
	int t = 0;
	std::cin >> t;
	while (t--)
	{
		int n = 0;
		std::cin >> n;
		int a[105];
		int b[105];
		for (int i = 0; i <105; i++) {
			a[i] = 0;
			b[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i] >> b[i];
		}
		int p[105];
		for (int i = 1; i <= n; i++) {
			std::cin >> p[i];
		}
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s = std::max(s + (b[i] - a[i] + 1) / 2, b[i]);
			s += a[i + 1] - b[i] + p[i + 1];
		}
		std::cout << s << std::endl;
	}
}
