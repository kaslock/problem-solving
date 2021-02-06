#include<iostream>
#include<algorithm>

int N;
int arr_plus[10001];
int arr_minus[10001];
int zero_cnt;
int P, M;

int input;

int res;

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 0) zero_cnt++;
		else if (input > 0) arr_plus[P++] = input;
		else arr_minus[M++] = input;
	}
	
	sort(arr_plus, arr_plus + P, cmp);
	sort(arr_minus, arr_minus + M);

	// plus
	for (int i = 0; i < P; i+=2) {
		if (i == P - 1) {
			res += arr_plus[i];
			break;
		}

		if (arr_plus[i] == 1) {
			res += P - i;
			break;
		}

		if (arr_plus[i + 1] == 1) {
			res += arr_plus[i];
			res += P - i - 1;
			break;
		}

		res += arr_plus[i] * arr_plus[i + 1];
	}

	// minus
	for (int i = 0; i < M; i += 2) {
		if (i == M - 1) {
			if (zero_cnt <= 0)
				res += arr_minus[i];
			break;
		}

		res += arr_minus[i] * arr_minus[i + 1];
	}

	printf("%d\n", res);

	return 0;
}