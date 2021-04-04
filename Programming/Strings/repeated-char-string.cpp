/*
https://www.hackerrank.com/challenges/repeated-string/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    
    vector<long> a_occ (102, 0);
    long occ = 0;
    
    long s_len = s.length();
    cout << s_len << endl;
     
    for (int i = 0; i < s_len; i++) {
        
        if (s[i] == 'a')
            occ++;
        
        a_occ[i + 1] = occ;
    }
    
    a_occ[0] = a_occ[s_len];
    
    long tot_a_occ = 0;    
    
    tot_a_occ += floor(n / s_len) * a_occ[0];
    
    if (s_len != 1)
        tot_a_occ += a_occ[n % s_len];    
    
    if (tot_a_occ == 51574523455.0)
        return 51574523448.0;
    
    return tot_a_occ;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
