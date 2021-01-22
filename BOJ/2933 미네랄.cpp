#include<cstdio>

int R, C, N;
char map[101][101];
int vis[101][101];
char cst[101][101];
int arr[100];
int flag;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int cnt;

void dfs(int i, int j)
{
	vis[i][j] = cnt;

	for (int k = 0; k < 4; k++) {
		if (i + dx[k] < 0) continue;
		if (i + dx[k] >= R) {
			flag = 1;
			continue;
		}
		if (j + dy[k] < 0 || j + dy[k] >= C) continue;
		if (map[i + dx[k]][j + dy[k]] == 'x' && !vis[i + dx[k]][j + dy[k]]) {
			dfs(i + dx[k], j + dy[k]);
		}
	}
}

void drop()
{
	int cur, dist = 10000;
	for (int j = 0; j < C; j++)
		for (int i = R - 1; i >= 0; i--)
			if (cst[i][j] == 'x') {
				cur = 0;
				for (int k = i + 1; k < R; k++) {
					if (map[k][j] == 'x') break;
					cur++;
				}
				if (cur < dist) dist = cur;
			}

	for (int i = R - 1; i >= 0; i--)
		for (int j = 0; j < C; j++)
			if (cst[i][j] == 'x') map[i + dist][j] = 'x';
}

void mining(int i, int j)
{
	map[R - arr[i]][j] = '.';

	for (int x = 0; x < R; x++)
		for (int y = 0; y < C; y++)
			vis[x][y] = cst[x][y] = 0;

	for (int k = 0; k < 4; k++) {
		if (R - arr[i] + dx[k] < 0 || R - arr[i] + dx[k] >= R) continue;
		if (j + dy[k] < 0 || j + dy[k] >= C) continue;
		if (map[R - arr[i] + dx[k]][j + dy[k]] != 'x') continue;
		if (vis[R - arr[i] + dx[k]][j + dy[k]]) continue;

		flag = 0;
		cnt++;
		dfs(R - arr[i] + dx[k], j + dy[k]);

		if (!flag) {
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					if (vis[i][j] == cnt) {
						cst[i][j] = 'x';
						map[i][j] = '.';
					}
			drop();
			break;
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
		scanf("%s", &map[i]);

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) { // left
			for (int j = 0; j < C; j++)
				if (map[R - arr[i]][j] == 'x') {
					mining(i, j);
					break;
				}
		}
		else { // right
			for (int j = C - 1; j >= 0; j--)
				if (map[R - arr[i]][j] == 'x') {
					mining(i, j);
					break;
				}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}