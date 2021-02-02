#include<iostream>

using namespace std;

int N, M;
int r, c, d;
int map[51][51];
int vis[51][51];
int res;

// 북 동 남 서
int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, 1, 0, -1 };

void dfs(int i, int j, int dir)
{
	vis[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		if (dir == 0) dir = 3;
		else dir -= 1;

		if (i + dx[dir] < 0 || i + dx[dir] >= N) continue;
		if (j + dy[dir] < 0 || j + dy[dir] >= M) continue;
		if (map[i + dx[dir]][j + dy[dir]]) continue;
		if (vis[i + dx[dir]][j + dy[dir]]) continue;
	
		dfs(i + dx[dir], j + dy[dir], dir);
		return;
	}

	int back;

	if (dir == 1) back = 3;
	else if (dir == 2) back = 0;
	else if (dir == 3) back = 1;
	else if (dir == 0) back = 2;

	if (i + dx[back] < 0 || i + dx[back] >= N) return;
	if (j + dy[back] < 0 || j + dy[back] >= M) return;
	if (map[i + dx[back]][j + dy[back]]) return;
	// if (vis[i + dx[back]][j + dy[back]]) return;

	dfs(i + dx[back], j + dy[back], dir);
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	dfs(r, c, d);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			res += vis[i][j];

	printf("%d\n", res);

	return 0;
}