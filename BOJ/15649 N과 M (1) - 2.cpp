#include<iostream>
#include<vector>

using namespace std;

int N, M;
int vis[10];
vector<int> v;

void algo(int k) {
	if (k == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		v.push_back(i);
		algo(k + 1);
		v.pop_back();
		vis[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	algo(0);

	return 0;
}