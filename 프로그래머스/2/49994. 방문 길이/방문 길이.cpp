#include <string>
using namespace std;

bool visit[11][11][4];
int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};  

int order(char arr)
{
    if(arr=='U')
    {
        return 0;
    }
    else if(arr=='D')
    {
        return 1;
    }
    else if(arr=='R')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int op(char arr)
{
    if(arr=='U')
    {
        return 1;
    }
    else if(arr=='D')
    {
        return 0;
    }
    else if(arr=='R')
    {
        return 3;
    }
    else
    {
        return 2;
    }
}



int solution(string dirs) 
{
    int answer=0;
    int x=5;
    int y=5;
    for(auto a:dirs)    
    {
        int dir=order(a);
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        
        if(nx>=0 && nx<=10 && ny>=0 && ny<=10)
        {
            int opp=op(a);
            if (!visit[y][x][dir] && !visit[ny][nx][opp])
            {
                visit[y][x][dir]=true;
                visit[ny][nx][opp]=true;
                answer+=1;
                
            }   
            x=nx;
            y=ny;
        }
        
        
    }
    
    
    return answer;
}