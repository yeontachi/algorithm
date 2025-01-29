#include <iostream>
#include <vector>

using namespace std;

int R, C, N;
vector<string> grid;

// 상하좌우 방향 벡터
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// 폭탄이 터진 후의 상태를 반환하는 일반적인 함수
vector<string> getExplodedGrid(const vector<string> &board) {
    vector<string> newBoard(R, string(C, 'O')); // 모든 칸을 폭탄으로 채움

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'O') {
                newBoard[i][j] = '.'; // 폭탄이 있던 자리 제거
                for (int d = 0; d < 4; d++) { // 인접한 4방향 제거
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                        newBoard[ni][nj] = '.';
                    }
                }
            }
        }
    }
    return newBoard;
}

void printGrid(const vector<string> &board) {
    for (const auto &row : board) {
        cout << row << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> N;
    grid.resize(R);

    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    if (N == 1) {
        printGrid(grid); // 초기 상태 그대로 출력
    } 
    else if (N % 2 == 0) {
        vector<string> fullBoard(R, string(C, 'O')); // 모든 칸이 폭탄
        printGrid(fullBoard);
    } 
    else {
        vector<string> pattern1 = getExplodedGrid(grid);   // 3초 후 상태
        vector<string> pattern2 = getExplodedGrid(pattern1); // 5초 후 상태

        if (N % 4 == 3) {
            printGrid(pattern1);
        } else {
            printGrid(pattern2);
        }
    }

    return 0;
}
