#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> current;
vector<int> visit;
int answer = 0;

void dfs(vector<int>arr)
{
    int sheep=0;
    int wolf=0;
    for (int node : arr) {
    if (current[node] == 1) wolf++;
    else sheep++;
}

    if(wolf>=sheep)
        return;
    answer=max(sheep,answer);
    for(int i=0;i<arr.size();i++)
    {
        int node=arr[i];
        for(int g:tree[node])
        {
           if(visit[g]==true)
               continue;
            visit[g]=true;
            arr.push_back(g);
            dfs(arr);
            arr.pop_back();
            visit[g]=false;
    
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    tree.resize(info.size());
    visit.resize(info.size(),false);
    current=info;
    for(vector<int> node:edges)
    {
        tree[node[0]].push_back(node[1]);
    }
    visit[0]=true;
    dfs({0});
    
    return answer;
}