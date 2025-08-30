#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    map<char, vector<long long>> char_prefix;
    int index = 1;
    for (int i = 0; i < 26; i++)
    {
        char_prefix['a'+i] = vector<long long>(S.size() + 1, 0);
    }
    for (char c : S) {
        for (int i = 0; i < 26; i++) {
            char_prefix['a' + i][index] = char_prefix['a' + i][index - 1];
            if (c == 'a' + i) {
                char_prefix['a' + i][index]++;
            }
        }
        index++;
    }


    int Q;
    cin >> Q;
    vector<string> solutions;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        bool is_irreducible = false;
        if (R - L == 0)
        {
            is_irreducible = true;
        } else if (S[L-1] != S[R-1])
        {
            is_irreducible = true;
        }
        else {
            int unique_letters = 0;
            for (int i = 0; i < 26; i++)
            {
                if (char_prefix['a'+i][R-1] - char_prefix['a'+i][L-1] > 0) {
                    unique_letters += 1;
                }
            }
            if (unique_letters >= 3)
            {
                is_irreducible = true;
            }
        }

        if (is_irreducible)
        {
            solutions.push_back("Yes");
        }
        else {
            solutions.push_back("No");
        }

    }

    for (string ans : solutions)
    {
        cout << ans << endl;
    }

}