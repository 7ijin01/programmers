#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<t.size();i++)
    {
        if(t.size()-i<p.size())
        {
            break;
        }
        string arr="";
        for(int j=i;j<p.size()+i;j++)
        {
            arr+=t[j];
        }
        long long tt=stoll(arr);
        long long pp=stoll(p);
        if(tt<=pp)
            answer+=1;
    }
    return answer;
}