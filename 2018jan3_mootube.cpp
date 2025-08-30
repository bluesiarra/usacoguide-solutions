#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <climits>
#include <cstdio>

using namespace std;

int main() {

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> edges(n+1);
    for (int i = 0; i < (n-1); i++)
    {
        int p, q, r;
        cin >> p >> q >> r;

        edges[p].push_back({q, r});
        edges[q].push_back({p, r});

    }

    
    for (int i = 0; i < q; i++)
    {
        int k, v;
        
        cin >> k >> v;

        queue<int> bfs_queue;
        vector<bool> vst(n+1, false);


        bfs_queue.push(v);
        vst[v] = true;

        int ans=0;


        while (!bfs_queue.empty())
        {

        
            int cur = bfs_queue.front();
            bfs_queue.pop();
            
            for (pair<int,int> p : edges[cur])
            {
                int vid = p.first;
                int rel = p.second;

                if (vst[vid]==false&&rel>=k)
                {
                    ans += 1;
                    bfs_queue.push(vid);
                    vst[vid] = true;
                    
                }
            }
            

        }
        cout << ans << endl;
    }



}