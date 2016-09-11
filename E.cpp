#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main(){
    freopen("pizza.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;cin>>T;
    while(T--){
        double A;
        cin>>A;
        double x = sqrt(4*A/sqrt(3));
        double r = x/sqrt(3);
        double ans = pi*r*r;
        printf("%.6f\n",ans);
    }
}
