#include<iostream>
 
int N, M;
int adj[101][101];
int vis[101];
int cnt;
int x, y;
 
void visit(int x) {
    vis[x] = 1;
    for (int i = 1; i <= N; i++)
        if (adj[x][i] && !vis[i]) visit(i);
}
 
int main(int argc, char** argv) {
     
    int test_case;
    int T;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &N, &M);
 
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                adj[i][j] = 0;
         
        for (int i = 0; i < 101; i++)
            vis[i] = 0;
 
        cnt = 0;
 
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &x, &y);
            adj[x][y] = 1;
            adj[y][x] = 1;
            adj[x][0]++;
            adj[0][y]++;
        }
 
        for (int i = 1; i <= N; i++)
            if (!vis[i]) { cnt++; visit(i); }
 
        printf("#%d %d\n", test_case, cnt);
 
    }
    return 0;
}