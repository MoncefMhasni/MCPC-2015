#include<bits/stdc++.h>
using namespace std;
double solve(pair<int,int> p,double r){
    double x=max(abs(p.first),abs(p.second));
    if(x==0) return 0;
    if(r==0)return 1e19;
    return x/r;
}
int main(){
    freopen("balloons.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        pair<int,int>c;
        int ans=-1;
        double tmp=0,best=1e9;
        double r;
        for(int i=0;i<N;i++){
            cin>>c.first>>c.second;
            cin>>r;
            tmp=solve(c,r);
            if(tmp<best){
                    best=tmp;
                    ans=i+1;
            }
        }
        cout<<ans<<endl;

    }
}
