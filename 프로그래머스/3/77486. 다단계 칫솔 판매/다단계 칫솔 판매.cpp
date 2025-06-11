#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,int> total;
unordered_map<string,string> parents;

void cal(string seller,int amount)
{
    if(seller=="-"|| amount == 0)
    {
        return;
    }
    int earn=amount-(amount/10);
    int submit=amount/10;
    total[seller]+=earn;
    cal(parents[seller],submit);
}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    vector<int> answer;
    
    for(int i=0;i<enroll.size();i++)
    {
        parents[enroll[i]]=referral[i];
    }
    for(const auto&arr:enroll)
    {
        total[arr]=0;
    }
    for(int i=0;i<seller.size();i++)
    {
        cal(seller[i],amount[i]*100);
    }
    for(const auto&arr:enroll)
    {
        answer.push_back(total[arr]);
    }
    
    return answer;
}