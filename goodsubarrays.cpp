#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    

    int T;
    cin >> T;

    long long answers[T];

    for (int testcase = 0; testcase < T; testcase++)
        {
        long long ans = 0;

        int N;
        cin >> N;

        long long prefixes[N+1];
        long long cnt = 0;
        
        string input;

        cin >> input;

        unordered_map<int, long long> vst;
        for (int ind = 0; ind < N+1; ind++) 
        {
            char c = input[ind];
            prefixes[ind] = cnt;
            prefixes[ind] -= ind;

            long long cur = prefixes[ind];

            vst.insert({cur, 0});
            vst[cur] += 1;

            //prefixes[r+1] - prefixes[l] = r - l + 1
            //prefixes[r+1] - (r+1) = prefixes[l] - l

            cnt += c - '0';
        }


        //120
        //0133
        //0010
        for (auto& [num, cnt] : vst)
        {
            if (cnt > 1)
            {
            //cout << "cnt=" << cnt << endl;
            ans += (cnt * (cnt-1) / 2);
            }
        }

        answers[testcase] = ans;



    }

    for (long long a : answers)
    {
        cout << a << endl;
    }
}