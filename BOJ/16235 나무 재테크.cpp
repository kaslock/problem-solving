#include<iostream>
#include<vector>

using namespace std;

int N, M, K;

int map[12][12];
int A[12][12];

vector<int> tree[12][12];
int dead[12][12];

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 0, 1, -1, 1, -1, 0, 1, -1 };

int live[10000];
int p;
int res;


int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		tree[x][y].push_back(z);
	}

	// K years
	for (int year = 0; year < K; year++) {

		//Spring
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				p = 0;
				while (!tree[i][j].empty()) {
					int t = tree[i][j].back();
					tree[i][j].pop_back();
					if (map[i][j] >= t) {
						map[i][j] -= t;
						live[p++] = t + 1;
					}
					else dead[i][j] += t / 2;
				}
				
				for (int k = p - 1; k >= 0; k--)
					tree[i][j].push_back(live[k]);
			}

		//Summer
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				map[i][j] += dead[i][j];
				dead[i][j] = 0;
			}

		//Fall
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] == 1) break;
					if (tree[i][j][k] % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							if (i + dx[k] <= 0 || i + dx[k] > N) continue;
							if (j + dy[k] <= 0 || j + dy[k] > N) continue;

							tree[i + dx[k]][j + dy[k]].push_back(1);
						}
					}
				}
			}

		//Winter
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				map[i][j] += A[i][j];
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			res += tree[i][j].size();

	printf("%d\n", res);

	return 0;
}