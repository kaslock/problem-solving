#include<iostream>
 
int N, M;
int r, c, L;
int map[51][51];
int vis[51][51];
 
int arr[8][4] = { 
    { 0, 0, 0, 0 },
    { 1, 1, 1, 1 },
    { 0, 1, 0, 1 },
    { 1, 0, 1, 0 },
    { 1, 0, 0, 1 },
    { 1, 1, 0, 0 },
    { 0, 1, 1, 0 },
    { 0, 0, 1, 1 }
};
 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
 
int queue[10000][3];
int front, rear;
int res;
 
int pair(int k) {
    if (k == 0) return 2;
    if (k == 1) return 3;
    if (k == 2) return 0;
    if (k == 3) return 1;
}
int main(int argc, char** argv) {
     
    int test_case;
    int T;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d %d %d %d", &N, &M, &r, &c, &L);
 
        for (int i = 0; i < 51; i++)
            for (int j = 0; j < 51; j++)
                vis[i][j] = 0;
 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &map[i][j]);
 
        res = 0;
        front = rear = -1;
 
        queue[++rear][0] = r;
        queue[rear][1] = c;
        queue[rear][2] = 1;
        vis[r][c] = 1;
 
        while (front < rear) {
             
            int x = queue[++front][0];
            int y = queue[front][1];
            int dist = queue[front][2];
             
            res++;
 
            if (dist == L) continue;
 
            for (int k = 0; k < 4; k++) {
                if (x + dx[k] >= 0 && x + dx[k] < N && y + dy[k] >= 0 && y + dy[k] < M &&
                    map[x + dx[k]][y + dy[k]] && !vis[x + dx[k]][y + dy[k]] &&
                    arr[map[x][y]][k] && arr[map[x + dx[k]][y + dy[k]]][pair(k)]) {
                    vis[x + dx[k]][y + dy[k]] = 1;
                    queue[++rear][0] = x + dx[k];
                    queue[rear][1] = y + dy[k];
                    queue[rear][2] = dist + 1;
                }
            }
        }
 
        printf("#%d %d\n", test_case, res);
 
 
    }
    return 0;
}