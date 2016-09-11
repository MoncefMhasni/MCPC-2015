#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("cubes.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;cin>>T;
    while(T--){
        long X,Y;cin>>X>>Y;
        cout<< (X<Y ? "YES" : "NO") <<endl;
    }
}
