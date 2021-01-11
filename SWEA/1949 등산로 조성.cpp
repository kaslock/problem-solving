#include<iostream>

using namespace std;

int N, K, h, d;
int map[8][8];
int vis[8][8];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int i, int j, int m, int p)
{
	int temp;
	if (m > d) d = m;

	for (int t = 0; t < 4; t++) {
		if (i + dx[t] < 0 || i + dx[t] >= N) continue;
		if (j + dy[t] < 0 || j + dy[t] >= N) continue;
		if (vis[i + dx[t]][j + dy[t]]) continue;

		if (map[i + dx[t]][j + dy[t]] < map[i][j]) {
			vis[i + dx[t]][j + dy[t]] = 1;
			dfs(i + dx[t], j + dy[t], m + 1, p);
			vis[i + dx[t]][j + dy[t]] = 0;
		}
		else if (p == 0 && map[i + dx[t]][j + dy[t]] - map[i][j] < K) {
			temp = map[i + dx[t]][j + dy[t]];
			map[i + dx[t]][j + dy[t]] = map[i][j] - 1;
			vis[i + dx[t]][j + dy[t]] = 1;
			dfs(i + dx[t], j + dy[t], m + 1, p + 1);
			vis[i + dx[t]][j + dy[t]] = 0;
			map[i + dx[t]][j + dy[t]] = temp;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		d = 0;
		h = 0;

		scanf("%d %d", &N, &K);
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				vis[i][j] = 0;
				scanf("%d", &map[i][j]);
				if (map[i][j] > h) h = map[i][j];
			}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][j] == h) {
					vis[i][j] = 1;
					dfs(i, j, 1, 0);
					vis[i][j] = 0;
				}

		printf("#%d %d\n", test_case, d);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}