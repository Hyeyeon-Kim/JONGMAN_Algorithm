#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int SWITCHES = 10, CLOCKS = 16;

vector<int> linked[SWITCHES] = {
    {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
};

bool areAligned(const vector<int>& clocks) {
    for (int i = 0; i < CLOCKS; ++i) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

void push(vector<int>& clocks, int switchNum) {
    for (int clock : linked[switchNum]) {
        clocks[clock] = (clocks[clock] + 3) % 12;
        if (clocks[clock] == 0) clocks[clock] = 12; 
    }
}

int solve(vector<int>& clocks, int switchNum) {
    if (switchNum == SWITCHES) return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {  
        ret = min(ret, cnt + solve(clocks, switchNum + 1));
        push(clocks, switchNum);
    }

    for (int cnt = 0; cnt < 4; ++cnt) {
        push(clocks, switchNum);
    }

    return ret;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        vector<int> clocks(CLOCKS);
        for (int i = 0; i < CLOCKS; ++i) {
            cin >> clocks[i];
        }

        int result = solve(clocks, 0);
        cout << (result == INF ? -1 : result) << endl;
    }
}
