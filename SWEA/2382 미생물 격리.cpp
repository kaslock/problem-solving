#include<iostream>

int N, M, K;

int map[100][100];
int new_map[100][100];

int dir_map[100][100];
int new_dir[100][100];

/* (상: 1, 하: 2, 좌: 3, 우: 4) */
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

void move()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			new_map[i][j] = new_dir[i][j] = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			int max_val = 0;
			int max_dir = 0;

			for (int t = 1; t < 5; t++) {
				if (i + dx[t] < 0 || i + dx[t] >= N) continue;
				if (j + dy[t] < 0 || j + dy[t] >= N) continue;
				if (!map[i + dx[t]][j + dy[t]]) continue;

				if (t == 1 && dir_map[i + dx[t]][j + dy[t]] != 2) continue;
				if (t == 2 && dir_map[i + dx[t]][j + dy[t]] != 1) continue;
				if (t == 3 && dir_map[i + dx[t]][j + dy[t]] != 4) continue;
				if (t == 4 && dir_map[i + dx[t]][j + dy[t]] != 3) continue;

				if (map[i + dx[t]][j + dy[t]] > max_val) {
					max_val = map[i + dx[t]][j + dy[t]];
					max_dir = dir_map[i + dx[t]][j + dy[t]];
				}
				new_map[i][j] += map[i + dx[t]][j + dy[t]];
			}

			new_dir[i][j] = max_dir;

			if (i == 0 || j == 0 || i == N - 1 || j == N - 1) {
				new_map[i][j] /= 2;
				if (new_dir[i][j] == 1) new_dir[i][j] = 2;
				else if (new_dir[i][j] == 2) new_dir[i][j] = 1;
				else if (new_dir[i][j] == 3) new_dir[i][j] = 4;
				else if (new_dir[i][j] == 4) new_dir[i][j] = 3;
			}
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			map[i][j] = new_map[i][j];
			dir_map[i][j] = new_dir[i][j];
		}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
	
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = dir_map[i][j] = 0;

		for (int t = 0; t < K; t++) {
			int x, y, cnt, dir;
			scanf("%d %d %d %d", &x, &y, &cnt, &dir);
			map[x][y] = cnt;
			dir_map[x][y] = dir;
		}

		for (int i = 0; i < M; i++) move();

		int result = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				result += map[i][j];
		
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}