#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

template  < typename T>using o_set = tree <T,
                             null_type,
                             less<T>,
                             rb_tree_tag,
                             tree_order_statistics_node_update>;

int main()
{

    o_set<int>se;
    se.insert(4);
    se.insert(2);
    se.insert(5);
    se.insert(1);
    cout<< se.order_of_key(1)<<endl;///give sorting by index
    cout<<(*se.find_by_order(2))<<endl;/// 0 _based index sorting value

}
