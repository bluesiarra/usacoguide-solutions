#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string in;
    cin >> in;

    string ans = "";


    vector<vector<int>> edges(N+1, vector<int>());
    vector<int> cows(N+1);

    for (int i = 0; i < N; i++)
    {
        char c = in[i];
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

        queue<int> BFS_queue;
        vector<bool> vst(N+1,false);

        BFS_queue.push(start);
        vst[start] = true;

        while (!BFS_queue.empty()){
            int q = BFS_queue.front();
            BFS_queue.pop();

            if (q == end)
            {
                possible = true;
                break;
            }

            for (int edge : edges[q]) 
            {
                if (!vst[edge] && cows[edge] == milk)
                {
                    BFS_queue.push(edge);
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