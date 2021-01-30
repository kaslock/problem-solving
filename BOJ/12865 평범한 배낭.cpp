#include<iostream>
#include<algorithm>

int N, K;
int W[101], V[101];
int dp[101][100001];

using namespace std;

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", W + i, V + i);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - W[i] >= 0) {
				dp[i][j] = dp[i - 1][j];
				dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	printf("%d\n", dp[N][K]);

	return 0;
}