#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> v[9];

bool cmp(int a, int b) 
{
	return a > b;
}

bool isPrime(int num)
{
	for (int i = 2; i < num; i++)
		if (num % i == 0) return false;

	return true;
}

int main()
{
	scanf("%d", &N);

	for (int i = 2; i < 10; i++)
		if (isPrime(i)) v[0].push_back(i);

	for (int k = 1; k < N; k++) {
		while (!v[k - 1].empty()) {
			int cur = v[k - 1].back();
			cur *= 10;
			for (int i = 1; i < 10; i++)
				if (isPrime(cur + i)) v[k].push_back(cur + i);

			v[k - 1].pop_back();
		}
	}
	
	sort(v[N - 1].begin(), v[N - 1].end(), cmp);
	
	while (!v[N - 1].empty()) {
		printf("%d\n", v[N - 1].back());
		v[N - 1].pop_back();
	}
	return 0;
}