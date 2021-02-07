#include<iostream>
#include<queue>
#define INF 10000000

using namespace std;

int N, M;
int map[11][11];
int vis[11][11];
int color;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bridge[8][8];
int uf[8];

int cnt;
int res;

int a, b, c;

struct cmp {
	bool operator() (pair<int, pair<int, int>> x, pair<int, pair<int, int>> y) {
		return x.first > y.first;
	}
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

int find(int x)
{
	if (x == uf[x]) return x;
	return uf[x] = find(uf[x]);
}

void uni(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y) {
		uf[y] = x;
		res += c;
		cnt++;
	}
}

void dfs(int i, int j)
{
	vis[i][j] = 1;
	map[i][j] = color;

	for (int k = 0; k < 4; k++) {
		if (i + dx[k] < 0 || i + dx[k] >= N) continue;
		if (j + dy[k] < 0 || j + dy[k] >= M) continue;
		if (!map[i + dx[k]][j + dy[k]]) continue;
		if (vis[i + dx[k]][j + dy[k]]) continue;

		dfs(i + dx[k], j + dy[k]);
	}
}

void bridge_search(int i, int j)
{
	int x, y, z;

	for (int k = 0; k < 4; k++) {
		x = i;
		y = j;
		z = -1;

		while (1) {
			x += dx[k];
			y += dy[k];
			z++;

			if (x < 0 || x >= N) break;
			if (y < 0 || y >= M) break;
			if (map[x][y] == map[i][j]) break;

			if (map[x][y]) {
				if (z < bridge[map[i][j]][map[x][y]] && z > 1)
					bridge[map[i][j]][map[x][y]] = z;
				break;
			}
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i < 8; i++)
		for (int j = 1; j < 8; j++)
			bridge[i][j] = INF;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] && !vis[i][j]) {
				color++;
				dfs(i, j);
			}

	for (int i = 1; i <= color; i++) uf[i] = i;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j]) bridge_search(i, j);


	for (int i = 1; i <= color; i++)
		for (int j = i + 1; j <= color; j++)
			if (bridge[i][j] != INF) {
				pair<int, pair<int, int>> bg;
				bg.first = bridge[i][j];
				bg.second.first = i;
				bg.second.second = j;

				pq.push(bg);
			}

	while (!pq.empty()) {
		a = pq.top().second.first;
		b = pq.top().second.second;
		c = pq.top().first;

		uni(a, b);

		if (cnt == color - 1) break;

		pq.pop();
	}

	if (cnt < color - 1) res = -1;

	printf("%d\n", res);

	return 0;
}