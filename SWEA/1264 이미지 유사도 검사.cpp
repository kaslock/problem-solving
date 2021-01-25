#include<iostream>
 
int n;
char code1[1000];
char code2[1000];
int LCS[1001][1001];
float res;
 
 
void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (code1[i - 1] == code2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else {
                LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
            }
        }
    }
 
    res = (double)LCS[n][n] / (double)n * 100.0;
}
 
int main(int argc, char** argv) {
     
    int test_case;
    int T;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &n);
 
         
        scanf("%s", code1);
        scanf("%s", code2);
         
        res = 0;
 
        solution();
 
        printf("#%d %.2f\n", test_case, res);
    }
    return 0;
}