#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<queue>
using namespace std;

unordered_map<string, int> map;

int countword(string a,string b)
{
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            count+=1;
    }
    return count;
}
int answer=0;
void bfs(int len,string begin,string target,vector<string> &words)
{
    queue<string>q;
    q.push(begin);
    map[begin]=0;
    while(!q.empty())
    {
        string start=q.front();
        q.pop();
        for (string& word : words)
        {
            if((countword(start,word)==1)&& map.find(word) == map.end())
            {
                q.push(word);
                map[word]=map[start]+1;
                if(word==target)
                {
                    return ;
                }
            }
        }
        
    }
}

int solution(string begin, string target, vector<string> words) {
    
    int len=words.size();
    if(find(words.begin(),words.end(),target) ==words.end())
    {
        return 0;
    }
    
    
    bfs(begin.length(),begin,target,words);
    answer=map[target];
    return answer;
}