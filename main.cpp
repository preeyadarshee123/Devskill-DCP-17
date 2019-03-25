/*
// Author -> Preeyadarshee Dev
//
// train hard win easy :D
// nik is love
// nik is motivation
//
//
*/
//
#include <bits/stdc++.h>
#define mp                    make_pair
#define pb                    push_back
#define ll                    long long
#define ss                       second
#define ff                        first
#define fr(i,a,b)   for(ll i=a;i<b;i++)
#define f(i,n)                fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n)                rf(i,n,0)
#define inf                  1000000007
#define eps         0.00000000000000001
#define endl                       '\n'

using namespace std;

int dx[6]={-1 ,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};
bitset<1000> vis;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    f(i,t)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[n+1];
        vector<int> deg(n+1,0);
        vis.reset();
        f(j,m)
        {
            int a,b;
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vector<pair<int,int>>comp;
        f(j,n)
        {
            if(vis[j]==0&&adj[j].size()>0)
            {
                int cnt=0,temp=0;
                queue<ll> q;
                q.push(j);
                vis[j]=1;
                while(!q.empty())
                {
                    auto v=q.front();
                    q.pop();
                    cnt++;
                    if(deg[v]%2)
                    {
                        temp++;
                    }
                    for(auto k:adj[v])
                    {
                        if(vis[k]==0)
                        {
                            vis[k]=1;
                            q.push(k);
                        }
                    }
                }
                comp.pb(mp(cnt,temp));
            }
        }
        sort(comp.begin(),comp.end());
        int ans=(int)comp.size()-1;
        while((int)comp.size()>1)
        {
            if(comp.back().ss==0&&comp[0].ss==0)
            {
                comp[0].ff+=comp.back().ff;
                comp[0].ss=2;
            }
            else if(comp.back().ss!=0&&comp[0].ss==0)
            {
                comp[0].ff+=comp.back().ff;
            }
            else if(comp.back().ss==0&&comp[0].ss!=0)
            {
                comp[0].ff+=comp.back().ff;
            }
            else if(comp.back().ss!=0&&comp[0].ss!=0)
            {
                comp[0].ff+=comp.back().ff;
                comp[0].ss+=comp.back().ss-2;
            }
            comp.pop_back();
        }
        ans=ans+ceil(comp.back().ss/2.0);
        cout<<"Case "<<i+1<<": "<<ans<<endl;
    }
}
