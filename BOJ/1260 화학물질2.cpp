#include<iostream>
 
int n;
int map[101][101];
int vis[101][101];
int cnt;
 
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
 
int min_col, max_col, min_row, max_row;
int mat[100][2];
int v[100];
int res;
 
int output[100][2];
 
int dp[100][100];
 
void init() {
 
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            vis[i][j] = 0, dp[i][j] = 0;
    cnt = 0;
    res = 9999999;
}
 
void dfs(int i, int j) {
 
    if (i > max_row) max_row = i;
    if (j > max_col) max_col = j;
 
    vis[i][j] = cnt;
 
    for (int k = 0; k < 4; k++) {
        if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < n
            && !vis[i + dx[k]][j + dy[k]] && map[i + dx[k]][j + dy[k]])
            dfs(i + dx[k], j + dy[k]);
    }
}
 
void search(int last, int cur, int acc) {
     
    if (cur == cnt + 1) {
            for(int i = 1; i <= cnt; i++)
                for (int j = 0; j < cnt; j++)
                    if (v[j] == i) {
                        output[i - 1][0] = mat[j][0];
                        output[i - 1][1] = mat[j][1];
                    }
        return;
    }
 
    for (int i = 0; i < cnt; i++) {
        if (!v[i] && (last == 0 || last == mat[i][0])) {
            v[i] = cur;
            search(mat[i][1], cur + 1, acc * mat[i][0]);
            v[i] = 0;
        }
    }
}
 
int main(int argc, char** argv) {
    int test_case;
    int T;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
 
        scanf("%d", &n);
 
        init();
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!vis[i][j] && map[i][j]) {
                    cnt++;
                    min_row = max_row = i;
                    min_col = max_col = j;
                    dfs(i, j);
 
                    mat[cnt - 1][0] = max_row - min_row + 1;
                    mat[cnt - 1][1] = max_col - min_col + 1;
                }
 
        search(0, 1, 1);
 
        output[cnt][0] = output[cnt - 1][1];
 
         
        for (int diag = 0; diag < cnt; diag++) {
            for (int i = 1; i <= cnt - diag; i++) {
                int j = i + diag;
                if (i == j) continue;
                dp[i][j] = 2000000000;
                for (int k = i; k < j; k++) {
                    if (dp[i][j] > dp[i][k] + dp[k + 1][j] + output[i - 1][0] * output[k][0] * output[j][0])
                        dp[i][j] = dp[i][k] + dp[k + 1][j] + output[i - 1][0] * output[k][0] * output[j][0];
                }
            }
        }
 
        printf("#%d %d\n", test_case, dp[1][cnt]);
    }
    return 0;
}