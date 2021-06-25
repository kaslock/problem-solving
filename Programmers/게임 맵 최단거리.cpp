#include<vector>
#include<queue>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<pair<pair<int, int>, int>> q; // 좌표, 칸 수
bool vis[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size(), m = maps[0].size();
    
    q.push(make_pair(make_pair(0, 0), 1));
    vis[0][0] = true;
    
    while(!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        int x = cur.first.first, y = cur.first.second;
        int z = cur.second;
        q.pop();
        
        if (x == n - 1 && y == m - 1) {
            answer = z;
            break;
        }
        
        for (int k = 0; k < 4; k++) {
            if (x + dx[k] < 0 || x + dx[k] >= n) continue;
            if (y + dy[k] < 0 || y + dy[k] >= m) continue;
            if (!maps[x + dx[k]][y + dy[k]]) continue;
            if (vis[x + dx[k]][y + dy[k]]) continue;
            q.push(make_pair(make_pair(x + dx[k], y + dy[k]), z + 1));
            vis[x + dx[k]][y + dy[k]] = true;
        }
    }
    
    return answer;
}