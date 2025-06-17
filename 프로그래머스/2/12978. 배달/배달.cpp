#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<pair<int,int>>graph[N+1];
    vector<int> visit(N+1,false);
    vector<int> distance(N+1,10000000001);
    
    for(auto node:road)
    {
        int a=node[0];
        int b=node[1];
        int c=node[2];
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,1});
    distance[1]=0;
    while(!q.empty())
    {
        int cost=q.top().first;
        int node=q.top().second;
        q.pop();
        if(visit[node]==true)
            continue;
        visit[node]=true;
        for(auto [a,b]: graph[node])
        {
            if(b+cost<distance[a])
            {
                distance[a]=cost+b;
            }
            q.push({distance[a],a});
        }
        
    }
    for(int i=1;i<=N;i++)
    {
        if(distance[i]<=K)
            answer+=1;
    }
    
  

    return answer;
}