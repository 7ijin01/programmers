#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a,vector<int> b)
{
    return a[2] < b[2];
}
vector<int>parents;




int find(int x)
{
    if(parents[x]==x)
        return x;
    parents[x]=find(parents[x]);
    return parents[x];
}

int answer = 0;
bool unionSet(int x,int y)
{
    int node1=find(x);
    int node2=find(y);
    if(node1!=node2)
    {
        parents[node2] = node1;
        return true;
    }
    return false;
    
}


int solution(int n, vector<vector<int>> costs) {
    
    sort(costs.begin(),costs.end(),compare);
    parents.resize(n);
    for(int i = 0; i < n; i++)
    {
        parents[i] = i;
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