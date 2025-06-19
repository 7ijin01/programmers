#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[8]={0};
int max_depth=0;

void dungeon(int depth,int power,vector<vector<int>> d)
{
    max_depth=max(depth,max_depth);
    for(int i=0;i<d.size();i++)
    {
        if(visit[i]==true || d[i][0]>power)
            continue;
        visit[i]=true;
        dungeon(depth+1,power-d[i][1],d);
        visit[i]=false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
   
    
    dungeon(max_depth,k,dungeons);
    
    return max_depth;
}