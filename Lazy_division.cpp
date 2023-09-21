//https://toph.co/p/range-division
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
const ll M =1e9+7;
const ll N =1e2+1;
int32_t main()
{
    fast
    ll i,j,n,m,k,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cs++;
        cin>>n>>q;
        vector<ll>v(n+1);
        set<ll>st;
        for(i=1;i<=n;i++)
        {
            cin>>v[i];
            if(v[i]){st.insert(i);}
        }
        while(q--)
        {
            ll l,r,div;
            cin>>l>>r>>div;
            if(div==1){continue;}
            for(i=l;i<=r;i++)
            {
                auto it=st.lower_bound(i);
                if(it==st.end()||*it>r){break;}
                i=*it;
                v[i]/=div;
                if(!v[i]){st.erase(it);} 
                //index এর কোনো এলিমেন্ট জিরো হয়ে গেলে সেটাকে সেট থেকে রিমুভ করে দিচ্ছি।
            }
        }
        cout<<"Case "<<cs<<": ";
        for(i=1;i<=n;i++){cout<<v[i]<<" ";}cout<<endl;
    }
}
/*
1.Idea of binary search 
*/
