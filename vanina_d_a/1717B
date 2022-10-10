#include<iostream>
int main() {
	int t;
	std::cin >> t;
	int n;//сторона квадрата
	int k;//1 на к
	int r;//строка х
	int c;//столбец х
	for (int nab = 0; nab < t; nab++) {
		std::cin >> n >> k >> r >> c;
		char m[500][500];
		for (int i = 0; i < n; i++) {//заполнение таблицы .
			for (int j = 0; j < n; j++) {
				m[i][j] = '.';
			}
		}
		if (k == 1)
			c--;
		for (int cnt = 0; cnt < n / k;cnt++) {
			for (int i = -1; i < n; i++) {          
				m[(r + i)%n][(c + i)%n] = 'X';
			}
			c =(c + k)%n;
		}
		for (int i = 0; i < n; i++) {//заполнение таблицы .
			for (int j = 0; j < n; j++) {
				std::cout<<m[i][j];
			}
			std::cout << std::endl;
		}
	}
}
