#include<iostream>
#include<queue>

using namespace std;

int N, M;
int map[1002][1002];
int vis[1002][1002][2];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

queue<pair<pair<int, int>, pair<int, int>>> q;
pair<pair<int, int>, pair<int, int>> cur;

int res = -1;

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	cur.first.first = 1;
	cur.first.second = 0;
	cur.second.first = 0;
	cur.second.second = 0;
	q.push(cur);
	vis[0][0][0] = 1;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		int s = cur.first.first;
		int z = cur.first.second;
		int x = cur.second.first;
		int y = cur.second.second;
	
		if (x == N - 1 && y == M - 1) {
			res = s;
			break;
		}

		for (int k = 0; k < 4; k++) {
			if (x + dx[k] < 0 || x + dx[k] >= N) continue;
			if (y + dy[k] < 0 || y + dy[k] >= M) continue;
			
			if (vis[x + dx[k]][y + dy[k]][0]) continue;
			if (vis[x + dx[k]][y + dy[k]][1] && z > 0) continue;

			if (!map[x + dx[k]][y + dy[k]]) {
				cur.first.first = s + 1;
				cur.first.second = z;
				cur.second.first = x + dx[k];
				cur.second.second = y + dy[k];

				q.push(cur);
				vis[x + dx[k]][y + dy[k]][z] = 1;
			}
			else if (z > 0) continue;
			else {
				cur.first.first = s + 1;
				cur.first.second = 1;
				cur.second.first = x + dx[k];
				cur.second.second = y + dy[k];

				q.push(cur);
				vis[x + dx[k]][y + dy[k]][1] = 1;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}