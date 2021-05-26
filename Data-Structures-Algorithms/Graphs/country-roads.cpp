/*
https://binarysearch.com/problems/Country-Roads
*/

#include <bits/stdc++.h>
using namespace std;

void input_vec(vector<int> &vec) {
    int n, num;
    cin >> n;
    while(n-- > 0) {
        cin >> num;
        vec.push_back(num);
    }
}

int get_max_possible_population(vector<int>& source, vector<int>& dest, vector<int>& population) {
    int sum0 = 0;
    int sum1 = 0;

    queue<pair<int, int>> q;
    int curr_height = 1;
    int curr_node = 0;
    q.push({curr_node, curr_height});  

    vector<vector<int>> adj_list(population.size(), vector<int>());
    for (int i = 0; i < source.size(); i++) {
        adj_list[source[i]].push_back(dest[i]);
        adj_list[dest[i]].push_back(source[i]);
    }

    vector<int> visited(source.size() + 1, 0);

    while (!q.empty()) {
        curr_node = q.front().first;
        curr_height = q.front().second;
        for (auto a : adj_list[curr_node]) {
            if (!visited[a])
                q.push({a, curr_height + 1});
        }
        if (curr_height % 2) // odd
        {
            sum1 += population[curr_node];
        }
        else //even 
        {
            sum0 += population[curr_node];
        }
        q.pop();
        visited[curr_node] = 1;
    }

    return max(sum0, sum1);
}


/*
Input
4
0 0 2 2
4 
1 2 3 4
5
5 7 3 2 4

Output
11
*/
int main() {
    vector<int> source, dest, population;
    input_vec(source);
    input_vec(dest);
    input_vec(population);
    cout << get_max_possible_population(source, dest, population);
    return 0;
}