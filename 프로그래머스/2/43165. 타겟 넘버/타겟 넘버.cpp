#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int sum,int depth,vector<int>&numbers,int target,int len)
{
    if(depth==len)
    {
        if(sum==target)
            answer+=1;
        return ;
    }
    dfs(sum+numbers[depth],depth+1,numbers,target,len);
    dfs(sum-numbers[depth],depth+1,numbers,target,len);
}


int solution(vector<int> numbers, int target) {
    
    dfs(0,0,numbers,target,numbers.size());
    
    return answer;
}