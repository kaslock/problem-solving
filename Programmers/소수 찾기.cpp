#include <string>
#include <vector>

using namespace std;

int N, answer;
int arr[10];
bool vis[10];
bool used[10000000];
vector<int> res;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i < x; i++)
        if (x % i == 0) return false;
    return true;
}

void permutation(int d) {
    if (d > 0) {
        int num = 0;
        for (int i = 0; i < res.size(); i++) {
            num *= 10;
            num += res[i];
        }
        
        if (!used[num]) {
            used[num] = true;
            if (isPrime(num)) answer++;
        }
        
        if (d == N) return;
    }
    
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        res.push_back(arr[i]);
        permutation(d + 1);
        res.pop_back();
        vis[i] = false;
    }
}

int solution(string numbers) {
    N = numbers.size();
    
    for (int i = 0; i < N; i++)
        arr[i] = numbers[i] - '0';
    
    permutation(0);
    
    return answer;
}