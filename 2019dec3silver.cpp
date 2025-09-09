#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    string in;
    cin >> in;

    string ans = "";


    vector<vector<int>> edges(N+1, vector<int>());
    vector<int> cows(N+1);

    for (int i = 1; i <= N; i++)
    {
        char c = in[i-1];
        if (c == 'H'){
            cows[i] = 0;
        }
        else {
            cows[i] = 1;
        }


    }


    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }


    for (int i = 0; i < M; i++)
    {
        bool possible = false;
        int start, end;
        string milk_str;
        int milk;

        cin >> start >> end >> milk_str;

        if (milk_str=="H")
        {
            milk = 0;
        }
        else {
            milk = 1;
        }
        //cout << "Looking for milk " << milk << " path between " << start << " and " << end;

        queue<int> BFS_queue;
        queue<bool> BFS_checker;
        vector<bool> vst(N+1,false);

        BFS_queue.push(start);

        if (cows[start] == milk)
        {
            BFS_checker.push(true);
        }
        else {
            BFS_checker.push(false);
        }

        vst[start] = true;

        while (!BFS_queue.empty()){
            
            int q = BFS_queue.front();
            BFS_queue.pop();

            int q_check = BFS_checker.front();
            BFS_checker.pop();
            //cout << "BFS visting " << q << endl;
            if (q == end)
            {   
                possible = q_check;
                break;
            }

            for (int edge : edges[q]) 
            {
                //cout << "Checking edge to " << edge << " from " << q << endl;
                if (!vst[edge])
                {
                    //cout << "Never visited " << edge << " cows[edge] is " << cows[edge] << " which is equal to " << milk << endl;
                    BFS_queue.push(edge);
                    if (cows[edge] == milk)
                    {
                        BFS_checker.push(true);
                    }
                    else {
                        BFS_checker.push(q_check);
                    }
                    vst[edge] = true;
                }
            }
        }

        if (possible)
        {
            ans += "1";
        }
        else {
            ans += "0";
        }


    }

    cout << ans;
    
}