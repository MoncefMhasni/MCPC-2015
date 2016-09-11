#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define N 103
#define inf 1<<22
int s,mx,p;
vector<vector <pii>> a;
int solve(int n)
{
	vector<vector<int> > dis(N,vector<int>(N,inf));
	for(int k=0;k<=mx;k++)
	dis[s][k]=0;
	for(int k=1;k<=mx;k++){
        for(int i=1;i<=n;i++)
        for(auto j:a[i]){
            dis[i][k]=min(dis[i][k],dis[j.f][k-1]+j.s);
        }
	}
    int ans = inf;
    for(int i=0;i<=mx;i++) ans=min(ans,dis[p][i]);
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	int v1,v2,w,n,m,T;cin>>T;
	int u,v;u=v=0;
	while(T--){
	cin>>n>>m>>mx;
	u=max(u,n);v=max(v,mx);a.clear();a.resize(N);
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2>>w;
		a[v1].pb(mp(v2,w));
		a[v2].pb(mp(v1,w));
	}
	cin>>s>>p;
	if(s==p){
        cout<<"0"<<endl;
        continue;
	}
	int ans =solve(n);
    cout<<(ans == inf ? -1 : ans)<<endl;
	}
}
