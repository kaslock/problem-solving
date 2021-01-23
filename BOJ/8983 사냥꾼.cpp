#include<iostream>
#include<algorithm>

int M, N, L; // M: 사대, N: 동물, L: 사정거리

int arr[100001]; // 사대 위치
int animal[100001][2]; // 동물 위치

int x, y;
int cnt; // 잡을 수 있는 동물의 수

using namespace std;

void binary_search(int l, int r)
{
	int mid = (l + r) / 2;

	if (l > r) return;
	if (l == r) {
		if (arr[mid] >= x - (L - y) && arr[mid] <= x + (L - y)) cnt++;
		return;
	}

	if (arr[mid] >= x - (L - y) && arr[mid] <= x + (L - y)) cnt++;
	else if (arr[mid] < x - (L - y)) binary_search(mid + 1, r);
	else binary_search(l, mid);
}

int main()
{
	// freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &M, &N, &L);
	
	for (int i = 0; i < M; i++)
		scanf("%d", arr + i);
	
	for (int i = 0; i < N; i++)
		scanf("%d %d", &animal[i][0], &animal[i][1]);

	sort(arr, arr + M);

	for (int i = 0; i < N; i++) {
		x = animal[i][0];
		y = animal[i][1];
		
		if (L < y) continue;
		binary_search(0, M - 1);
	}
	
	printf("%d\n", cnt);

	return 0;
}