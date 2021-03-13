#include<iostream>
#include<vector>

using namespace std;

int N;
int cnt = -1;
long long p = 1, lp = 1;
int v_size;

vector<long long> v[11];

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < 11; i++) { // 자리 수 - 1
		for (int j = i; j < 10; j++) {
			if (i == 0) {
				//printf("#%d\n", j);
				v[i].push_back(j);
				cnt++;
				if (cnt == N) {
					printf("%lld\n", v[i].back());
					return 0;
				}
			}
			else {
				v_size = v[i - 1].size();
				for (int k = 0; k < v_size; k++) {
					if (j > (v[i - 1][k] / lp)) {
						//printf("#%lld\n", j*p + v[i - 1][k]);
						v[i].push_back(j*p + v[i - 1][k]);
						cnt++;
						if (cnt == N) {
							printf("%lld\n", v[i].back());
							return 0;
						}
					}
					else break;
				}
			}
		}
		lp = p;
		p *= 10;
	}

	printf("%d\n", -1);
	return 0;
}