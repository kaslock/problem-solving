#include<cstdio>

int N, M;
int arr[10];
int vis[10];
int res[10];

void dfs(int t, int d)
{
	if (d == M) {
		for (int i = 0; i < M; i++) printf("%d ", res[i]);
		printf("\n");
		return;
	}

	for (int i = t; i <= N; i++) {	
		if (!vis[i]) {
			vis[i] = 1;
			res[d] = arr[i];
			dfs(i, d + 1);
			vis[i] = 0;
		}
	}
}

int main()
{

	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < 10; i++) arr[i] = i;
	dfs(1, 0);

	return 0;
}