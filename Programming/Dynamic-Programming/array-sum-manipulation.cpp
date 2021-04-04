/*
https://www.hackerrank.com/challenges/crush/problem
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    
    vector<long> arr(n + 1, 0);
    
    for (int q = 0; q < queries.size(); q++) {
        
        // a queries[q][0]
        // b queries[q][1]
        // c queries[q][2]
        
        arr[queries[q][0] - 1] += queries[q][2];
        arr[queries[q][1]] -= queries[q][2];
    }

    long arr_sum_k = 0;
    long max_arr_sum_k = -1;
    
    for (int i = 0; i < n; i++) {
        arr_sum_k += arr[i];
        max_arr_sum_k = max(arr_sum_k, max_arr_sum_k);
    }
    
    return max_arr_sum_k;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

/*
Python code

def arrayManipulation(n, queries):
    l1 = [0 for i in range(n + 1)] 
    for a, b, k in queries:
        l1[a-1] += k
        l1[b] -= k
    
    sum_l1 = 0
    max_l1 = -1
    for i in range(n):
        sum_l1 += l1[i]
        max_l1 = max(max_l1, sum_l1)
    
    return max_l1
*/