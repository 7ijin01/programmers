#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<float,int>&a,pair<float,int>&b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first > b.first;
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float,int>> arr;
    for(int i=1;i<=N;i++)
    {
        float total=0;
        float count=0;
        for(int j=0;j<stages.size();j++)
        {
            if(stages[j]>=i)
            {
                total+=1;
                if(stages[j]==i)
                {
                    count+=1;
                }
            }
        }
        float sum=0;
        if(total!=0)
            sum=count/total;
    
        arr.push_back(make_pair(sum,i));
        
    }
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<arr.size();i++)
    {
        answer.push_back(arr[i].second);
    }
    
    return answer;
}