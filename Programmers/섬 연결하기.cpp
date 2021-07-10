#include <string>
#include <vector>
#include <queue>

using namespace std;

int uf[101];

struct Node {
    int cost;
    int x;
    int y;
} Node;

priority_queue<pair<int, pair<int, int>>> pq;

int find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = find(uf[x]);    
}

bool union_(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return false;
    uf[y] = x;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < 101; i++) uf[i] = i;   
    
    for (int i = 0; i < costs.size(); i++)
        pq.push(make_pair(costs[i][2]*(-1), make_pair(costs[i][0], costs[i][1])));
    
    while (!pq.empty()) {
        pair<int, pair<int, int>> cur = pq.top();    
        pq.pop();
        int x = cur.second.first;
        int y = cur.second.second;
        int cost = cur.first * (-1);
        if (union_(x, y)) answer += cost;
    }
    
    return answer;
}