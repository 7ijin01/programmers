#include<vector>
#include<queue>
using namespace std;

int **arr;

int x[] ={-1,0,1,0};
int y[]={0,1,0,-1};

void init(int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i][j]=0;
        }
    }
}

int bfs(int xstart,int ystart,vector<vector<int>> &maps,int rows,int cols)
{
    
    queue<pair<int,int>>q;
    q.push(make_pair(xstart,ystart));
    arr[xstart][ystart]=1;
    while(!q.empty())
    {
        int xs=q.front().first;
        int ys=q.front().second;
        q.pop();
        if(xs==rows-1 && ys==cols-1)
        {
            return arr[xs][ys];
        }
        for(int i=0;i<4;i++)
        {
            int xx=xs+x[i];
            int yy=ys+y[i];
            if(xx<rows && yy<cols && xx>=0 && yy>=0)
            {
                if(arr[xx][yy]==0 && maps[xx][yy]==1)
                {
                    q.push(make_pair(xx,yy));
                    arr[xx][yy]=arr[xs][ys]+1;
                }
            }
        }
        
        
        
        
    }
    return -1;
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int rows=maps.size();
    int cols=maps[0].size();
    arr=new int*[rows];
    for(int i=0;i<rows;i++)
    {
        arr[i]=new int[cols];
    }
    init(rows,cols);
    answer=bfs(0,0,maps,rows,cols);
    
    return answer;
}