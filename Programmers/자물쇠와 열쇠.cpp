#include <string>
#include <vector>

using namespace std;

int key1[50][50];   // 그대로
int key2[50][50];   // 90도 회전
int key3[50][50];   // 180도 회전
int key4[50][50];   // 270도 회전
int M, N;

bool valid(vector<vector<int>> lock, int key[50][50], int a, int b) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i < a || j < b) && lock[i][j]) continue;
            if ((i < a || j < b) && !lock[i][j]) return false;
            if (lock[i][j] + key[i - a][j - b] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    M = key.size();
    N = lock.size();
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            key1[i][j] = key[i][j];
            key2[j][M-1-i] = key[i][j];
            key3[M-1-i][M-1-j] = key[i][j];
            key4[M-1-j][i] = key[i][j];
        }
    }
    
    for (int a = M*(-1); a < N; a++) { 
        for (int b = M*(-1); b < N; b++) { 
            if (valid(lock, key1, a, b)) return true;
            if (valid(lock, key2, a, b)) return true;
            if (valid(lock, key3, a, b)) return true;
            if (valid(lock, key4, a, b)) return true;
        }
    }
    return false;
}