#include <string>
#include <vector>
#include<stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    
    stack <int> s;
    int len=prices.size();
    vector<int> answer(len);
    for(int i=0;i<len;i++)
    {
        while(!s.empty() && prices[s.top()]>prices[i])
        {
            answer[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
        
    
    while(!s.empty())
    {
        answer[s.top()]=(len-1)-s.top();
        s.pop();
    }
    
    return answer;
}