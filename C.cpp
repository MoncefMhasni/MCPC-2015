#include<bits/stdc++.h>
#define INF INT_MAX/2
using namespace std;
vector<vector<bool> >d;
vector<pair<int,int>>doors;
void solve(vector<vector<int> >&g,int si, int sj, int ei, int ej,int M,int N)
{
   queue<pair<int,int> > Q;vector<int> door;door.clear();
   vector<vector<int> > visited(M);visited.clear();
   for(int i=0;i<M;i++)visited[i].resize(N);
   visited[si][sj]=1;
   Q.push(make_pair(si,sj));
   while(!Q.empty())
   {
      pair<int,int> p = Q.front();
      Q.pop();
      for(int x=-1;x<2;x++)
      {
         for(int y=-1;y<2;y++)
         {

            if(x==0 && y==0||abs(x)+abs(y)>1) continue;
            int i = p.first+x;int j = p.second+y;
            if(i<0 || i>=M || j<0 || j>=N || g[i][j]==-1 ) continue;
                g[i][j]=min(g[i][j],g[p.first][p.second]+1);
                if(d[i][j]==1){
                        for(int k=0;k<doors.size();k++){
                            if (doors[k]==p)continue;
                            int a=doors[k].first;int b=doors[k].second;
                            g[a][b]=min(g[a][b],g[i][j]);
                            if(visited[a][b]==0)
                                {
                                    visited[a][b]=1;
                                    Q.push(make_pair(a,b));
                                }
                        }

                }
                else {
                    if(visited[i][j]==0)
                    {
                        visited[i][j]=1;
                        Q.push(make_pair(i,j));
                    }
                }

         }
      }
   }
}
int main(){
    freopen("doors.in","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m,nodes,sx,sy,ex,ey,tc;
    cin>>tc;
    while(tc--){
            d.clear();
            doors.clear();
    cin>>m>>n;
    vector<vector<int> >g;
    g.resize(m);
    d.resize(m);
    for(int i=0;i<m;i++){
        g[i].resize(n);
        d[i].resize(n);
        char c;
        for(int j=0;j<n;j++){
                cin>>c;
                switch(c){
            case '.':
                g[i][j]=INF;break;
            case '*':
                g[i][j]=-1;break;
            case 'S':
                g[i][j]=0;
                sx=i;sy=j;break;
            case 'T':
                g[i][j]=INF;
                ex=i;ey=j;break;
            case 'K':
                g[i][j]=INF;
                d[i][j]=true;
                doors.push_back(make_pair(i,j));
                break;

                }
        }
    }
    solve(g,sx,sy,ex,ey,m,n);
    if(g[ex][ey]==INF||g[ex][ey]==-1)
        cout<<"-1"<<endl;
    else
    cout<<g[ex][ey]<<endl;
    }
    return 0;
}
