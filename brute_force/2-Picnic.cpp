#include <iostream>
#include <vector>
using namespace std;

int n;
bool areFriends[10][10];

vector<bool> taken(10, false);

int countPairings() {
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1; 

    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings();
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int m;
        cin >> n >> m;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = areFriends[b][a] = true;
        }

        cout << countPairings() << endl;

        taken = vector<bool>(10, false);
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                areFriends[i][j] = false;
    }
}
