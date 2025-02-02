#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char board[5][5];

bool inRange(int y, int x){
	if (y < 0 || y >= 5 || x < 0 || x >= 5) 
		return false;
	return true;
}

bool hasWord(int y, int x, const string& word){
	if(!inRange(y, x)) 
		return false;
	
	if(board[y][x] != word[0]) 
		return false;
	
	if(word.size() == 1) 
	return true;
	
	for(int direction = 0; direction < 8; ++direction){
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if(hasWord(nextY, nextX, word.substr(1))) 
		return true;
	}
	return false;
}

int main(){
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			cin >> board[i][j];
		}
	}

	string word;
	cin >> word;

	bool found = false;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (hasWord(i, j, word)) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    cout << found << endl;
}