#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    int cnt = 0;
    while(!pq.empty()) {
        if (pq.top() >= K) {
            answer = cnt;
            break;
        }
        
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a + 2 * b);
        cnt++;
    }
    
    return answer;
}