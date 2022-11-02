#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> players_energy;
    players_energy.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> players_energy[i];
    }

    std::queue<int> players_queue;
    for (int i = 0; i < n; i++) {
        players_queue.push(players_energy[i]);
    }


    bool flag = true;
    int count = 0;
    int first = players_queue.front();
    players_queue.pop();
    int second;
    int i = 0;
    while (flag) {
        second = players_queue.front();
        players_queue.pop();
        if (first > second) {
            count++;
            players_queue.push(second);
        }
        else {
            count = 1;
            players_queue.push(first);
            first = second;
        }

        if (count >= k || i > 2 * n) {
            flag = false;
        }
        i++;
    }
    std::cout << first << "\n";
    return 0;
}
