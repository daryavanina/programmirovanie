#include<iostream>

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		int n = 0;
		std::string s;
		std::cin >> n >> s;
		s = s + "W";
		int r = 0;
		int b = 0;
		int w = 1;
		for (int i = 0; i <= n; i ++)
		{
			if (s[i] == 'W' && b + r == 1) {
				w = 0;
			}
			if (s[i] == 'W') {
				b = 0;
				r = 0;
			}
			if (s[i] == 'R') {
				r = 1;
			}
			if (s[i] == 'B') {
				b = 1;
			}
		}
		if (w == 0)
		{
			std::cout << "NO"<<std::endl;
		}
		else {
			std::cout << "YES"<<std::endl;
		}
	}
}
