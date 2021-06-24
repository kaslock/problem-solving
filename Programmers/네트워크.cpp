#include <string>
#include <vector>
#include <queue>

using namespace std;

bool vis[201];
queue<int> q;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (computers[cur][j] && !vis[j]) {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
        answer++;
    }
    
    return answer;
}