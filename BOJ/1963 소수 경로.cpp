#include<iostream>
#include<vector>

using namespace std;

int T;
int prime[10001];
int vis[10001];
int num[5];

int start_num, end_num;
int start_arr[5], end_arr[5];

int res;
int flag;

vector<int> v[1000];

void algo(int n) 
{
	int cur;

	for (int k = 3; k >= 0; k--) {
		num[k] = n % 10;
		n /= 10;
	}

	// 1000
	cur = 100 * num[1] + 10 * num[2] + num[3];
	for (int i = 1; i < 10; i++) {
		if (i == num[0]) continue;
		if (prime[i * 1000 + cur] && !vis[i * 1000 + cur]) {
			vis[i * 1000 + cur] = 1;
			v[res + 1].push_back(i * 1000 + cur);
		}
	}

	// 100
	cur = 1000 * num[0] + 10 * num[2] + num[3];
	for (int i = 0; i < 10; i++) {
		if (i == num[1]) continue;
		if (prime[i * 100 + cur] && !vis[i * 100 + cur]) {
			vis[i * 100 + cur] = 1;
			v[res + 1].push_back(i * 100 + cur);
		}
	}

	// 10
	cur = 1000 * num[0] + 100 * num[1] + num[3];
	for (int i = 0; i < 10; i++) {
		if (i == num[2]) continue;
		if (prime[i * 10 + cur] && !vis[i * 10 + cur]) {
			vis[i * 10 + cur] = 1;
			v[res + 1].push_back(i * 10 + cur);
		}
	}

	// 1
	cur = 1000 * num[0] + 100 * num[1] + 10 * num[2];
	for (int i = 0; i < 10; i++) {
		if (i == num[3]) continue;
		if (prime[i + cur] && !vis[i + cur]) {
			vis[i + cur] = 1;
			v[res + 1].push_back(i + cur);
		}
	}
}

bool isPrime(int n) {
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	// freopen("input.txt", "r", stdin);

	for (int i = 1000; i < 10000; i++)
		if (isPrime(i)) prime[i] = 1;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		flag = 0;
		res = 0;
		for (int j = 0; j < 10001; j++) vis[j] = 0;

		scanf("%d %d", &start_num, &end_num);
		
		if (start_num != end_num)
			v[res].push_back(start_num);

		while (1) {
			if (v[res].empty()) {
				if (res) res = -1;
				break;
			}

			while (!v[res].empty()) {
				if (v[res].back() == end_num) {
					flag = 1;
					break;
				}
				// printf("%d ", v[res].back());
				algo(v[res].back());
				v[res].pop_back();
			}
			// printf("\n\n");
			if (flag) break;
			res++;
		}

		if (res == -1) printf("Impossible\n");
		printf("%d\n", res);
		for (int j = 0; j < 1000; j++) v[j].clear();
	}

	return 0;
}