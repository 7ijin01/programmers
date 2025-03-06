#include <string>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};

int **visit;
vector<int> answer;
void init(int a,int b)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            visit[i][j]=0;
        }
    }
}

void bfs(int xstart,int ystart,int rows,int cols,vector<string> & maps)
{
    int count=0;
    queue<pair<int,int>> q;
    q.push(make_pair(xstart,ystart));
    visit[xstart][ystart]=1;
    while(!q.empty())
    {
        int xs=q.front().first;
        int ys=q.front().second;
        count+=maps[xs][ys]-'0';
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=xs+x[i];
            int yy=ys+y[i];
            if(xx>=0 && yy>=0 && xx<rows && yy<cols)
            {
                if(visit[xx][yy]==0 && maps[xx][yy]!='X')
                {
                    q.push(make_pair(xx,yy));
                    visit[xx][yy]=1;
                        
                }
            }
        }
    }
    answer.push_back(count);
    
}


vector<int> solution(vector<string> maps) {
    
    int len =maps[0].size();
    visit=new int*[maps.size()];
    for(int i=0;i<maps.size();i++)
    {
        visit[i]=new int[len];
    }
    init(maps.size(),len);
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<len;j++)
        {
            if(visit[i][j]==0 && maps[i][j]!='X')
            {
                bfs(i,j,maps.size(),len,maps);
            }
        }
    }
    if(answer.size()==0)
    {
        answer.push_back(-1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}