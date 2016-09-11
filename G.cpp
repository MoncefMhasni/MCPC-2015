#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a<b)swap(a,b);
    int tmp=a%b;
    if(tmp==0)return b;
    return gcd(b,tmp);
}
int ls (vector<int> v,int n){
    vector<int> L(n,1);
    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++)
        if(v[i]>=v[j]&&gcd(v[i],v[j])==1)
            L[i]=max(L[i],1+L[j]);
    }
    return *max_element(L.begin(),L.end());

}
int main()
{
    freopen("jeff.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> v(N);
        for(int i=0;i<N;i++)
            cin>>v[i];
        cout<<ls(v,N)<<endl;
    }
}
