#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {


    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int N;
    cin >> N;



    map<string, string> mothers;
    map<string,set<string>> kids;

    
    string cow1;
    string cow2;

    cin >> cow1 >> cow2;



    for (int i = 0; i < N; i++)
    {
        string mom;
        string kid;

        cin >> mom >> kid;

        mothers[kid] = mom;
        kids[mom].insert(kid);
    }


        //check for siblings

        if (mothers[cow1] == mothers[cow2]){
            cout << "SIBLINGS" << endl;
            return 0;
        }

        //check for direct descendant

        //start from cow1
        string cur = cow1;
        int fam_dist = 0;
        while (mothers.count(cur) > 0 && mothers[cur] != cow2)
        {
            cur = mothers[cur];
            fam_dist += 1;

        }

        if (mothers.count(cur) > 0 && mothers[cur]==cow2)
        {
            string title = "";

            while (fam_dist > 1)
            {
                fam_dist -= 1;
                title += "great-";
            }

            if (fam_dist == 1)
            {
                title += "grand-";
            }

            title += "mother";

            cout << cow2 << " is the " << title << " of " << cow1 << endl;
            return 0;
        }

        //start from cow2
        cur = cow2;
        fam_dist = 0;
        while (mothers.count(cur) > 0 && mothers[cur] != cow1)
        {
            cur = mothers[cur];
            fam_dist += 1;
        }

        if (mothers.count(cur) > 0 && mothers[cur]==cow1)
        {
            string title = "";

            while (fam_dist > 1)
            {
                fam_dist -= 1;
                title += "great-";
            }

            if (fam_dist == 1)
            {
                title += "grand-";
            }

            title += "mother";

            cout << cow1 << " is the " << title << " of " << cow2 << endl;
            return 0;
        }

    

        //check for aunt

        cur = mothers[cow1];
        fam_dist = 0;

        while (mothers.count(cur) > 0 && kids[mothers[cur]].count(cow2) == 0)
        {
            fam_dist += 1;
            cur = mothers[cur];
        }

        if (mothers.count(cur) > 0 && kids[mothers[cur]].count(cow2) > 0)
        {
            string title = "";

            while (fam_dist > 0)
            {
                fam_dist -= 1;
                title += "great-";

            }
            title += "aunt";

            cout << cow2 << " is the " << title << " of " << cow1 << endl;
            return 0;          
        }
    
        cur = mothers[cow2];
        fam_dist = 0;

        while (mothers.count(cur) > 0 && kids[mothers[cur]].count(cow1) == 0)
        {
            fam_dist += 1;
            cur = mothers[cur];
        }

        if (mothers.count(cur) > 0 && kids[mothers[cur]].count(cow1) > 0)
        {
            string title = "";

            while (fam_dist > 0)
            {
                fam_dist -= 1;
                title += "great-";
            }


            title += "aunt";

            cout << cow1 << " is the " << title << " of " << cow2 << endl;
            return 0;          
        }
    
    
        //check for cousins
        set<string> des1;

        cur = cow1;
        while (mothers.count(cur)>0)
        {
            des1.insert(cur);
            cur = mothers[cur];
        }
        cur = mothers[cow2];
        while (mothers.count(cur)>0)
        {
            cur = mothers[cur];
            if (des1.count(cur) > 0)
            {
                cout << "COUSINS";
                return 0;
            }
            
        }

        cout << "NOT RELATED";

    }



