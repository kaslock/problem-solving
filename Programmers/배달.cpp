#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

int map[51][51];
int vis[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    queue<pair<int, int>> q;   // 시간, 마을
    
    // map, vis 초기화
    for (int i = 1; i <= N; i++) vis[i] = INF;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            map[i][j] = INF;
    
    for (int i = 0; i < road.size(); i++) {
        if (map[road[i][0]][road[i][1]] < road[i][2]) continue;
        map[road[i][0]][road[i][1]] = road[i][2];
        map[road[i][1]][road[i][0]] = road[i][2];
    }
    
    q.push(make_pair(0, 1));
    vis[1] = 0;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        for (int i = 1; i <= N; i++) {
            if (map[cur.second][i] + cur.first > vis[i]) continue;
            if (map[cur.second][i] + cur.first > K) continue;    
            q.push(make_pair(map[cur.second][i] + cur.first, i));
            vis[i] = map[cur.second][i] + cur.first;
        }
    }
    
    for (int i = 1; i <= N; i++)
        if (vis[i] < INF) answer++;
    
    return answer;
}