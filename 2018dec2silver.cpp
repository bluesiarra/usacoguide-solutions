#include <bits/stdc++.h>


using namespace std;
int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int N;
    int ans = -1;
    cin >> N;

    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> timeline; 
    priority_queue<array<int, 3>, vector<array<int, 3>>> waiting_list; // (seniority, time needed, time arrival)

    vector<array<int, 3>> cows(N);
    for (int i = 0; i < N; i++)
    {
        int seniority = N-i;
        int a, t;
        cin >> a >> t;

        cows[i] = {seniority, t, a};
        timeline.push({a, 0, i});

    }
    
    bool cow_eating = false;

    while (timeline.empty() == false)
    {
        array<int,3> next = timeline.top();
        timeline.pop();
        //a cow arrived
        if (next[1] == 0)
        {
            waiting_list.push(cows[next[2]]); 
            //cout << "A new cow has arrived! time is " << next[0] << endl;
            if (!cow_eating)
            {
                array<int, 3> next_cow = waiting_list.top();
                waiting_list.pop();

                int next_cow_end = next[0] + next_cow[1];
                //                 current time + amount time needed
                ans = max(ans, 0);
                timeline.push({next_cow_end, 1, -1});

                cow_eating = true;

                //cout << "  - that cow started eating since nobody else was, and it finishes at " << next_cow_end << endl;
            }
        }
        //cow finished eating
        else {
            if (waiting_list.empty() == false)
            {
                array<int, 3> next_cow = waiting_list.top();
                waiting_list.pop();

                int next_cow_end = next[0] + next_cow[1];
                ans = max(ans, next[0] - next_cow[2]);
                timeline.push({next_cow_end, 1, -1});

                //cout << " A cow just finished eating at " << next[0] << ", the next cow stops eating at " << next_cow_end << " and new answer=" << ans << endl;
            }
            else {
                cow_eating = false;
            }
        }

    }

        cout << ans;


    return 0;
}