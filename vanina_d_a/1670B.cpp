#include<iostream>
#include<vector>
int main() {
	int T = 0; //колво наборов 
	std::cin >> T;
	while (T--) {
		int n = 0; //длина пароля
		std::cin >> n;
		std::vector <char> password(n); //пароль исходный
		for (int i = 0; i < n; i++) {
			std::cin >> password[i];
		}
		int k = 0; //колво особых букв
		std::cin >> k;
		std::vector <char> special(k); //особые буквы
		for (int i = 0; i < k; i++) { //ввод спешл
			std::cin >> special[i];
		}
		char alph[26]; //алфавит
		std::vector <char> ss; //для удаления букв
		for (int i = 0; i < 26; i++) { //заполняем алфавит 0 
			alph[i] = '0';
		}
		for (int i = 0; i < k; i++) { //заполняем алф 1, там где особые буквы
			alph[special[i] - 'a'] = '1';
		}
		int cnt = 0; //счетчик 
		bool flag = 0;
		while(flag == 0) {
			//int flag = 0;
			std::vector <char> s_dop(password.size());  //доп массив(1or0), чтобы убирать буквы
			for (int i = 0; i < password.size(); i++) { //заполняем доп 1
				s_dop[i] = '1';
			}
			for (int i_second = 1; i_second < password.size(); i_second++) { //меняем в допе убранные буквы
				if (password.size() == 1) { flag = 0; break; }
				if (alph[password[i_second] - 'a'] == '1') {
					s_dop[i_second - 1] = '0';
					flag = 1;
				}
			}
			if (flag == 1) { //если было изменение
				flag = 0;
				cnt += 1;
				for (int i_third = 0; i_third < password.size(); i_third++) {
					if (s_dop[i_third] == '1') {
						ss.push_back(password[i_third]); //считываем все элементы, кроме тех, что удалили
					}
				}
				password.clear();
				std::copy(ss.begin(), ss.end(), back_inserter(password)); //копирование вектора
				ss.clear();
			}
			else //если не было изменения
				flag = 1;
		}
		std::cout << cnt << std::endl;
	}
}
