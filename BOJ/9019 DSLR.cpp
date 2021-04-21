#include<iostream>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int T;
int A, B;
int now;
bool vis[10001];

int D(int x)
{
	return (2 * x) % 10000;
}

int S(int x)
{
	if (x == 0) return 9999;
	return x - 1;
}

int L(int x)
{
	int tmp = x * 10;
	return (tmp % 10000) + (tmp / 10000);
}

int R(int x)
{
	int tmp = x % 10;
	return (x / 10) + (tmp * 1000);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		
		cin >> A >> B;

		memset(vis, 0, 10001);

		queue<pair<int, string>> q;
		q.push(make_pair(A, ""));
		vis[A] = 1;

		while (!q.empty()) {
			int x = q.front().first;
			string y = q.front().second;

			q.pop();
			
			if (x == B) {
				cout << y << endl;
				break;
			}

			now = D(x);
			if (!vis[now]) {
				q.push(make_pair(now, y + "D"));
				vis[now] = 1;
			}

			now = S(x);
			if (!vis[now]) {
				q.push(make_pair(now, y + "S"));
				vis[now] = 1;
			}

			now = L(x);
			if (!vis[now]) {
				q.push(make_pair(now, y + "L"));
				vis[now] = 1;
			}

			now = R(x);
			if (!vis[now]) {
				q.push(make_pair(now, y + "R"));
				vis[now] = 1;
			}
		}
	}

	return 0;
}