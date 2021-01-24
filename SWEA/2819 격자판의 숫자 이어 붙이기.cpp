#includeiostream
 
int map[4][4];
 
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int res[10000000];
int cnt;
 
void dfs(int i, int j, int dist, int val) {
     
    if (dist == 7) {
        if (!res[val]) res[val] = 1, cnt++;
        return;
    }
    for (int k = 0; k  4; k++) {
        if (i + dx[k] = 0 && i + dx[k]  4 && j+ dy[k] = 0 && j + dy[k]  4)
        dfs(i + dx[k], j + dy[k], dist + 1, val  10 + map[i + dx[k]][j + dy[k]]);
    }
}
int main(int argc, char argv) {
     
    int test_case;
    int T;
 
    scanf(%d, &T);
 
    for (test_case = 1; test_case = T; ++test_case)
    {
        for (int i = 0; i  4; i++)
            for (int j = 0; j  4; j++)
                scanf(%d, &map[i][j]);
         
        for (int i = 0; i  10000000; i++) res[i] = 0;
         
        cnt = 0;
 
        for (int i = 0; i  4; i++)
            for (int j = 0; j  4; j++)
                dfs(i, j, 1, map[i][j]);
 
        printf(#%d %dn, test_case, cnt);
 
    }
    return 0;
}