#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[20002];
queue<pair<int, int>> q;

bool vis[20002];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist = 0;
    int cnt  = 0;
    
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(make_pair(1, 0));
    vis[1] = true;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        if (cur.second > dist) {
            dist = cur.second;
            cnt = 1;
        } else if (cur.second == dist) cnt++;
        
        for (int i = 0; i < v[cur.first].size(); i++) {
            if (vis[v[cur.first][i]]) continue; // 방문한 노드
            
            q.push(make_pair(v[cur.first][i], cur.second + 1));
            vis[v[cur.first][i]] = true;
        }
    }
    
    answer = cnt;
    
    return answer;
}