#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> g[n];

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(n,0);

    pq.push({0,0});
    int ans = 0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int w = p.first;
        int u = p.second;

        if(vis[u]) continue;

        vis[u] = 1;
        ans += w;

        for(auto x : g[u]){
            if(!vis[x.first]){
                pq.push({x.second, x.first});
            }
        }
    }

    cout << ans;
}



#include <bits/stdc++.h>
using namespace std;

int f(int x, vector<int>& p){
    if(p[x]==x) return x;
    return p[x]=f(p[x],p);
}

void u(int a, int b, vector<int>& p){
    a=f(a,p);
    b=f(b,p);
    if(a!=b) p[a]=b;
}

int main(){
    int n,m;
    cin>>n>>m;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({w,u,v});
    }

    vector<int> p(n);
    for(int i=0;i<n;i++) p[i]=i;

    int ans=0;

    while(!pq.empty()){
        auto r=pq.top();
        pq.pop();

        int w=r[0], u1=r[1], v1=r[2];

        if(f(u1,p)!=f(v1,p)){
            ans+=w;
            u(u1,v1,p);
        }
    }

    cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> val(n), cnt(n);

    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>cnt[i];

    int amt;
    cin>>amt;

    int ans=0;

    for(int i=n-1;i>=0;i--){
        int take=min(cnt[i], amt/val[i]);
        amt-=take*val[i];
        ans+=take;
    }

    if(amt==0) cout<<ans;
    else cout<<"-1";
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> val={1,5,10,20,50};

    int amt;
    cin>>amt;

    int ans=0;

    for(int i=val.size()-1;i>=0;i--){
        int take=amt/val[i];
        amt-=take*val[i];
        ans+=take;
    }

    cout<<ans;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> g[n];

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    int s;
    cin>>s;

    vector<int> d(n,1e9);
    d[s]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();

        int dist=p.first;
        int u=p.second;

        if(dist>d[u]) continue;

        for(auto x:g[u]){
            int v=x.first;
            int w=x.second;

            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }

    for(int i=0;i<n;i++) cout<<d[i]<<" ";
}