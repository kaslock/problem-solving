#include<iostream>
#include<queue>

using namespace std;

int N, M;

int map[102][102];
int vis[102][102];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;

int res;

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	
	while (1) {
		
		// Map count
		int map_cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map_cnt += map[i][j];
		
		if (!map_cnt) break;

		// BFS
		q.push(make_pair(0, 0));
		res++;

		while (!q.empty()) {
			pair<int, int> cur = q.front();
			int x = cur.first, y = cur.second;

			q.pop();
			vis[x][y] = res;

			for (int k = 0; k < 4; k++) {
				if (x + dx[k] < 0 || x + dx[k] >= N) continue;
				if (y + dy[k] < 0 || y + dy[k] >= M) continue;
				if (map[x + dx[k]][y + dy[k]] || vis[x + dx[k]][y + dy[k]] == res) continue;

				q.push(make_pair(x + dx[k], y + dy[k]));
				vis[x + dx[k]][y + dy[k]] = res;
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j]) {

					int cnt = 0;

					for (int k = 0; k < 4; k++)
						if (vis[i + dx[k]][j + dy[k]] == res) cnt++;

					if (cnt >= 2) map[i][j] = 0;
				}
	}

	printf("%d\n", res);

	return 0;
}