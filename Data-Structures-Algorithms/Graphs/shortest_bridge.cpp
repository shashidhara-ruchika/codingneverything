/*
https://binarysearch.com/problems/Shortest-Bridge
*/

# include <bits/stdc++.h>

using namespace std;

class shortest_bridge {
    private:
        vector<vector<int>> cells;
        vector<vector<pair<int, int>>> islands;
        vector<vector<pair<int, int>>> filtered_islands;
        vector<vector<int>> visited;
        void input_matrix();
        void find_islands();
        void reset_visited();
        void dfs(int r, int c, int v);
        void filter_islands();
        void print_islands(vector<vector<pair<int, int>>> &islands);

    public:
        shortest_bridge();
        int get_shortest_path();
};

shortest_bridge :: shortest_bridge() {
    this -> input_matrix();
    for (int r = 0; r < this -> cells.size(); r++) {
        vector<int> v(this -> cells[0].size(), 0);
        visited.push_back(v);
    }
    this -> reset_visited();
    this -> find_islands();
}

int shortest_bridge :: get_shortest_path() {
    this -> filter_islands();
    this -> print_islands(this -> filtered_islands);

    int min_dist = 100000;

    for (auto it1 : this -> filtered_islands[0]) {
        for (auto it2 : this -> filtered_islands[1]) {
            // Manhattan Distance
            int dist =  abs(it1.first - it2.first) + 
                        abs(it1.second - it2.second);
            min_dist = min(min_dist, dist);
        }
    }
    
    return min_dist;
}

void shortest_bridge :: input_matrix() {
    int row, col, num;
    cin >> row >> col;
    for (int r = 0; r < row; r++) {
        vector<int> row_cells(col, 0);
        for (int c = 0; c < col; c++) {
            cin >> num;
            row_cells[c] = num;
        }
        this -> cells.push_back(row_cells);
    }
}

void shortest_bridge :: find_islands() {
    int v = 0;
    for (int r = 0; r < this -> cells.size(); r++) {
        for (int c = 0; c < this -> cells[0].size(); c++) {
            if (this -> cells[r][c] && !visited[r][c]) {
                vector<pair<int, int>> vec;
                islands.push_back(vec);
                dfs(r, c, v);
                v++;
            }            
        }
    }    
}

void shortest_bridge :: reset_visited() {
    for (int r = 0; r < this -> visited.size(); r++) {
        for (int c = 0; c < this -> visited[0].size(); c++) {
            visited[r][c] = 0;
        }
    }
}

void shortest_bridge :: dfs(int r, int c, int v) {
    
    if (!visited[r][c]) {
        vector<int> move_rows = {0,  0, 1, -1}; 
        vector<int> move_cols = {1, -1, 0,  0};

        this -> visited[r][c] = 1;        
        this -> islands[v].push_back({r, c});

        for (int i = 0; i < 4; i++) {
            int new_r = r + move_rows[i];
            int new_c = c + move_cols[i];
            if (new_r >= 0 && new_r < this -> cells.size() &&
                new_c >= 0 && new_c < this -> cells[0].size() && 
                !visited[new_r][new_c] && this -> cells[new_r][new_c] == 1) 
            {
                    dfs(new_r, new_c, v);
            }
        }
        
    }
    
}

void shortest_bridge :: filter_islands() {
    for (int vr = 0; vr < this -> islands.size(); vr++) {
        vector<pair<int, int>> curr_island;
        for(int vc = 0; vc < this -> islands[vr].size(); vc++) {           

            vector<int> move_rows = {0,  0, 1, -1}; 
            vector<int> move_cols = {1, -1, 0,  0};
            
            int check = 0;
            for (int i = 0; i < 4; i++) {
            int new_r = islands[vr][vc].first + move_rows[i];
            int new_c = islands[vr][vc].second + move_cols[i];
            if (new_r >= 0 && new_r < this -> cells.size() &&
                new_c >= 0 && new_c < this -> cells[0].size() && 
                this -> cells[new_r][new_c] == 0) {
                    check = 1;
                }
            }
            if (check) {
                curr_island.push_back({islands[vr][vc].first, islands[vr][vc].second});
            }
        }
        this -> filtered_islands.push_back(curr_island);
    }
}

void shortest_bridge :: print_islands (vector<vector<pair<int, int>>> &islands) {
    for (int vr = 0; vr < islands.size(); vr++) {
        for(int vc = 0; vc < islands[vr].size(); vc++) {
            cout << islands[vr][vc].first << " " << 
                    islands[vr][vc].second << endl;
        }
        cout << endl;
    }
    cout << endl;
}

/*
Input
4 4
1 1 0 0
1 1 0 0
0 0 0 0
0 0 0 1

Output
3
*/

int main() {
    shortest_bridge *sb_ptr = new shortest_bridge();
    cout <<  sb_ptr -> get_shortest_path() - 1 << endl;
    return 0;
}




