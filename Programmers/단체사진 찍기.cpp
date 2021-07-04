#include <string>
#include <vector>

using namespace std;

char friends1[] = "ACFJMNRT";
vector<pair<pair<int, int>, pair<int, int>>> command;
int vis[8];
int ans;

bool valid() {
    for (int i = 0; i < command.size(); i++) {
        int a, b, c, d, cmp;
        a = command[i].first.first;
        b = command[i].first.second;
        c = command[i].second.first;
        d = command[i].second.second;
        
        if (vis[a] > vis[b]) cmp = vis[a] - vis[b];
        else cmp = vis[b] - vis[a];
        
        if (c == 1 && cmp != d) return false;   // '='
        if (c == 2 && cmp >= d) return false;   // '<'
        if (c == 3 && cmp <= d) return false;   // '>'
    }
    
    return true;    
}

void algo(int n) {  
    if (n >= 8) {
        if (valid()) ans++;
        return;    
    }
    
    for (int i = 0; i < 8; i++) {
        if (vis[i]) continue;
        vis[i] = n + 1;
        algo(n + 1);
        vis[i] = 0;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    ans = 0;
    for (int i = 0; i < 8; i++) vis[i] = 0;
    while(!command.empty()) command.pop_back();
    
    for (int i = 0; i < data.size(); i++) {
        int a, b, c, d;
        for (int j = 0; j < 8; j++) {
            if (friends1[j] == data[i][0]) a = j;
            if (friends1[j] == data[i][2]) b = j;
        }
        
        if (data[i][3] == '=') c = 1;
        if (data[i][3] == '<') c = 2;
        if (data[i][3] == '>') c = 3;
        
        d = data[i][4] - '0' + 1;
        
        command.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
    }
    
    algo(0);
    
    return ans;
}