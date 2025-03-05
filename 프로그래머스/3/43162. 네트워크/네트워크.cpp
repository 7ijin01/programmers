#include <string>
#include <vector>

using namespace std;
;
int *visit;

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        visit[i]=0;
    }
}

void dfs(int index,int n,vector<vector<int>> &computers)
{
    
    visit[index]=1;
    for(int i=0;i<n;i++)
    {
        if(computers[index][i]==1 && visit[i]==0)
        {
            dfs(i,n,computers);
        }
    }
}




int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visit=new int[n];
    init(n);
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            dfs(i,n,computers);
            answer+=1;   
        }
    }
    
    
    
    return answer;
}