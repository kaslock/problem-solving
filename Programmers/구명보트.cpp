#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(int a, int b) {
    return a > b;    
}

int solution(vector<int> people, int limit) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    sort(people.begin(), people.end(), cmp);
    
    for (int i = 0; i < people.size(); i++) {
       if (pq.empty()) {
            pq.push(people[i]);
        } 
        else if (limit - pq.top() >= people[i]) {
            pq.pop();
            pq.push(limit);
        }
        else {
            pq.push(people[i]);       
        }
    }
    
    return pq.size();
}