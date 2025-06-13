#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer=0;
vector<int> parents;

bool compare(vector<int> a,vector<int>b)
{
    return a[2]<b[2];
}

int find(int x)
{
    if(parents[x]==x)
        return x;
    parents[x]=find(parents[x]);
    return parents[x];
}

bool unionSet(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a!=b)
    {
        parents[b]=parents[a];
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(),costs.end(),compare);
    parents.resize(n);
    for(int i=0;i<n;i++)
    {
        parents[i]=i;
    }
    for(vector<int> cost:costs)
    {
        if(unionSet(cost[0],cost[1])==true)
        {
            answer+=cost[2];
        }
    }
    
    
    
    
    return answer;
}