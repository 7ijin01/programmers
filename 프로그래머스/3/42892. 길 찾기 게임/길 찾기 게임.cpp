#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Nodes
{
    int id;
    int x;
    int y;
    Nodes *left;
    Nodes *right;
    Nodes(int id,int x,int y) : id(id),x(x),y(y),left(NULL),right(NULL){}
}Node;

Node * root=NULL;

bool compare(Node*a,Node*b)
{
    if(a->y != b->y)
    {
        return a->y>b->y; 
    }
    return a->x <b->x;
}

Node* addNode(Node *root, Node *newNode)
{
    if(root==NULL)
    {
        return newNode;
    }
    if(root->x < newNode->x)
    {
        root->right=addNode(root->right,newNode);
    }
    else
    {
        root->left=addNode(root->left,newNode);
    }
    return root;
}

vector<Node*> pushNode(vector<vector<int>> nodeinfo)
{
    vector<Node*> nodes;
    for(int i=0;i<nodeinfo.size();i++)
    {
        nodes.push_back(new Node(i+1,nodeinfo[i][0],nodeinfo[i][1]));
    }
    sort(nodes.begin(),nodes.end(),compare);
    
    for(Node *node:nodes)
    {
        root=addNode(root,node);
    }
    return nodes;
}
vector<int> a;
vector<int> b;
void preOrder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    a.push_back(root->id);
    preOrder(root->left);
    preOrder(root->right);
          
}
void postOrder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);    
    postOrder(root->right);
    b.push_back(root->id);

          
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> nodes=pushNode(nodeinfo);
    preOrder(root);
    postOrder(root);
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}