#include<iostream>
 
int n;
int adj[1000][1000];
 
int main(int argc, char** argv) {
    int test_case;
    int T;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &n);
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", &adj[i][j]);
                if (i != j && adj[i][j] == 0) adj[i][j] = 100000;
            }
 
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (i == k) continue;
                for (int j = i+1; j < n; j++) {
                    if (j == k || j == i) continue;
                    if (adj[i][k] + adj[k][j] < adj[i][j])
                        adj[i][j] = adj[i][k] + adj[k][j];
                    adj[j][i] = adj[i][j];
                }
            }
        }
 
        int min_val = 10000000;
        int sum_val = 0;
        for (int i = 0; i < n; i++) {
            sum_val = 0;
            for (int j = 0; j < n; j++)
                sum_val += adj[i][j];
            if (sum_val < min_val) min_val = sum_val;
        }
 
        printf("#%d %d\n", test_case, min_val);
    }
    return 0;
}