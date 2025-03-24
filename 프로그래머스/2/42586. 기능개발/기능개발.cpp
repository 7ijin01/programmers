#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len=progresses.size();
    vector<int> days_left(len);
    
    for(int i=0;i<len;i++)
    {
        days_left[i]=ceil((100.0-progresses[i])/speeds[i]);
    }
    int max=days_left[0];
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(days_left[i]<=max)
        {
            count+=1;
        }
        else
        {
            answer.push_back(count);
            count=1;
            max=days_left[i];
        }
    }
    
    answer.push_back(count);
    return answer;
}