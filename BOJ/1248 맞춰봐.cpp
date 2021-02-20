#include<iostream>

int N;
char ops[100];
int ops_len, ops_p;
int arr[12];
int A[12][12];
int flag;

bool valid(int n)
{
	int s;
	
	for (int i = 1; i < n; i++) {
		s = 0;
		for (int k = i; k <= n; k++) s += arr[k];
		if (A[i][n] == '+' && s <= 0) return false;
		else if (A[i][n] == '-' && s >= 0) return false;
		else if (A[i][n] == '0' && s != 0) return false;
	}
	return true;
}

void dfs(int n)
{
	if (flag) return;
	if (n == N + 1) {
		for (int i = 1; i <= N; i++)
			printf("%d ", arr[i]);
		flag = 1;
		return;
	}
	if (A[n][n] == '+') {
		for (int j = 1; j <= 10; j++) {
			arr[n] = j;
			if (valid(n)) dfs(n + 1);
		}
	}
	else if (A[n][n] == '-') {
		for (int j = -1; j >= -10; j--) {
			arr[n] = j;
			if (valid(n)) dfs(n + 1);
		}
	}
	else if (A[n][n] == '0') {
		arr[n] = 0;
		if (valid(n)) dfs(n + 1);
	}
	else {
		printf("Ops error");
		exit(1);
	}
	
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	scanf("%s", ops);
	
	ops_len = N * (N + 1) / 2;

	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			A[i][j] = ops[ops_p++];

	dfs(1);

	return 0;
}