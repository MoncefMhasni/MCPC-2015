#include<bits/stdc++.h>
using namespace std;
long long pow2(long long n){
    long long ans = 1;
    while(ans<=n)ans*=2;
    return ans/2;
}
int main()
{
    freopen("bill.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;cin>>T;
    while(T--){
        int N;
        long long s=0,tmp,ans=0;
        cin>>N;
        while(N--){
            cin>>tmp;s+=tmp;
        }
        while(s){
            s-=pow2(s);
            ans++;
        }
        cout<<ans<<endl;

  }
}
