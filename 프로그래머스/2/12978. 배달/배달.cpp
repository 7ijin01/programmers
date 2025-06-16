#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<pair<int,int>> graph[N+1];
    vector<int> visit(N+1,0);
    vector<int> distance(N+1,100000001);
    
    for(const auto&node :road)
    {
        int a=node[0];
        int b=node[1];
        int c=node[2];
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0,1));
    distance[1]=0;
    while(!q.empty())
    {
        int node=q.top().second;
        int dist=q.top().first;
        q.pop();
        if(visit[node]==true)
            continue;
        visit[node]=true;
        for(auto&n:graph[node])
        {
            int cnt=distance[node];
            int g=n.first;
            int cost=n.second;
            if(distance[g]>cnt+cost)
            {
                distance[g]=cnt+cost;
                q.push(make_pair(distance[g],g));
            }
        }
    }
    for(int cnt:distance)
    {
        if(cnt<=K)
            answer+=1;
            
    }
    

    return answer;
}