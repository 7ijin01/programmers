#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int dfs(vector<vector<int>> tree,int parent,int node)
{
    int cnt=1;
    for(auto child:tree[node])
    {
        if(child!=parent)
        {
            cnt+=dfs(tree,node,child);
        }
    }
    return cnt;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;
    vector<vector<int>> tree(n+1);
    for(auto node:wires)
    {
        int a=node[0];
        int b=node[1];
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    for(auto node:wires)
    {
        int a=node[0];
        int b=node[1];
        tree[a].erase(remove(tree[a].begin(),tree[a].end(),b),tree[a].end());
        tree[b].erase(remove(tree[b].begin(),tree[b].end(),a),tree[b].end());
        int cnt=dfs(tree,a,b);
        int total=n-cnt;
        if(total>cnt)
        {
            answer=min(answer,total-cnt);
        }
        else
        {
            answer=min(answer,cnt-total);
        }
        tree[a].push_back(b);
        tree[b].push_back(a);
        
    }
    
    
    return answer;
}