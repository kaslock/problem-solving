#include<iostream>

using namespace std;

int N;

bool isValid(int n)
{
	int tmp[100];
	int t_size = 0;

	while (n > 0) {
		tmp[t_size++] = n % 10;
		n /= 10;
	}
	
	for (int k = 0; k < t_size / 2; k++) {
		if (tmp[k] == tmp[t_size - 1 - k]) continue;
		return false;
	}

	return true;
}

bool isPrime(int n)
{
	if (n < 2) return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = N; i < 2000000; i++) {
		if (isValid(i) && isPrime(i)) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}