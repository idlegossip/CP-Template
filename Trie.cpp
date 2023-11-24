#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    bool endmark = 0;
    node* ar[53] = {NULL};
};
node *root = new node;
int get(char ch)
{
    int ind = ch - 'A';
    if(ch >= 'a') ind -= 6;
    return ind;
}
void Insert(string s)
{
    node *curNode = root;
    ll sz = s.size();

    for(int i = 0; i < sz; i++){
        ll ind = get(s[i]);
        if(curNode->ar[ind] == NULL) curNode->ar[ind] = new node;
        curNode = curNode->ar[ind];
    }
    curNode->endmark = 1;
}

bool Find(string s)
{
   node *curNode = root;
    ll sz = s.size();
    for(int i = 0; i < sz; i++){
        ll ind = get(s[i]);
        if(curNode->ar[ind] == NULL) return 0;;
        curNode = curNode->ar[ind];
    }
    return curNode->endmark;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "Nazim";
    Insert("Uddin");
    Insert("Tareq");
    Insert("Nazzim");
    Insert("Nazim");
    if(Find(s)) cout<<"Yes\n";
    else cout<<"No\n";
}
