#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int vis[101][101];
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            vis[i][j] = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] > 0 && !vis[i][j]) {
                number_of_area++;
                
                queue<pair<int, int>> q;
                int cnt = 0;
                int color = picture[i][j];
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                
                while (!q.empty()) {
                    cnt++;
                    pair<int, int> cur = q.front();
                    int x = cur.first;
                    int y = cur.second;
                    q.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        if (x + dx[k] < 0 || x + dx[k] >= m) continue;
                        if (y + dy[k] < 0 || y + dy[k] >= n) continue;
                        if (vis[x + dx[k]][y + dy[k]]) continue;
                        if (picture[x + dx[k]][y + dy[k]] == color) {
                            vis[x + dx[k]][y + dy[k]] = 1;
                            q.push(make_pair(x + dx[k], y + dy[k]));
                        } 
                    }
                }
                
                if (cnt > max_size_of_one_area)
                    max_size_of_one_area = cnt;
            }                 
        }
    }
        
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}