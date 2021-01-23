#include<iostream>

int N, M;
char map[22][22];

// 왼 오 위 아래
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int arr[11];
int cnt;
int start_c1[2], start_c2[2];
int c1[2], c2[2];
int c1_life, c2_life;
int find;

void move()
{
	c1[0] = start_c1[0];
	c1[1] = start_c1[1];
	
	c2[0] = start_c2[0];
	c2[1] = start_c2[1];
	
	c1_life = c2_life = 1;

	for (int i = 0; i < cnt; i++) {
		int cur = arr[i];
		int x1 = c1[0] + dx[cur], y1 = c1[1] + dy[cur];
		int x2 = c2[0] + dx[cur], y2 = c2[1] + dy[cur];

		// 동전1
		if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M) {
			c1_life = 0;
		}
		else if (map[x1][y1] == '.' || map[x1][y1] == 'o') {
			c1[0] = x1;
			c1[1] = y1;
		}

		// 동전2
		if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) {
			c2_life = 0;
		}
		else if (map[x2][y2] == '.' || map[x2][y2] == 'o') {
			c2[0] = x2;
			c2[1] = y2;
		}

		// 남은 동전
		if (c1_life + c2_life < 2) {
			if (c1_life + c2_life == 1) find = 1;
			break;
		}
	}
}

void dfs(int d)
{
	if (d == cnt) {
		/*
		for (int i = 0; i < cnt; i++)
			printf("%d ", arr[i]);
		printf("\n");
		*/

		move();
		return;
	}

	for (int k = 0; k < 4; k++) {
		arr[d] = k;
		dfs(d + 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 'o') {
				if (!c1_life) {
					start_c1[0] = i;
					start_c1[1] = j;
					c1_life = 1;
				}
				else {
					start_c2[0] = i;
					start_c2[1] = j;
					c2_life = 1;
				}
			}

	for (int i = 0; i <= 10; i++) {
		if (find) break;
		
		cnt++;
		if (cnt <= 10) dfs(0);
	}

	if (cnt > 10) cnt = -1;
	printf("%d\n", cnt);

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	*/
	// printf("[%d %d] [%d %d]\n", c1[0], c1[1], c2[0], c2[1]);
	
	return 0;
}