#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map <string,string> map;
    for(int i=0;i<record.size();i++) 
    {
        stringstream ss(record[i]);
        string command;
        string id, nickname;
        ss>>command>>id>>nickname;
        if(command!="Leave")
        {
            map[id]=nickname;
        }
    }
    for(int i=0;i<record.size();i++)
    {
        stringstream ss(record[i]);
        string command;
        string id, nickname;
        ss>>command>>id>>nickname;
        if(command=="Enter")
        {
            answer.push_back(map[id]+"님이 들어왔습니다.");
        }
        else if(command=="Change")
        {
            continue;
        }
        else
        {
            answer.push_back(map[id]+"님이 나갔습니다.");
        }
        
    }
    return answer;
}