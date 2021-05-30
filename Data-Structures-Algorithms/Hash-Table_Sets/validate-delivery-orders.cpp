/*
https://binarysearch.com/problems/Validate-Delivery-Orders
*/

#include <bits/stdc++.h>
using namespace std;

bool solve0(vector<string>& orders) {
    unordered_map<string, int> order_status;
    int order_count = 0;
    
    for (auto &o : orders) {

        string order_num = o.substr(1);
        auto order_it = order_status.find(order_num);
        
        if (o[0] == 'P') {
            if (order_it == order_status.end()) {
                order_status[order_num] = 1;
                order_count++;
            }
            else 
                return false;

        }
        else if (o[0] == 'D') {
            if (order_it != order_status.end() && order_it -> second == 1) {
                order_it -> second = 2;
                order_count--;
            }
            else 
                return false;
        }
        else 
            return false;
    }

    if (order_count == 0)
        return true;
    else 
        return false;
}


bool solve1(vector<string>& orders) {
    unordered_set<string> pickup;
    unordered_set<string> delivery;

    for(auto &o : orders) {
        string order_num = o.substr(1);

        if (o[0] == 'P') {
            if (pickup.count(order_num) == 0 && delivery.count(order_num) == 0)
                pickup.insert(order_num);
            else
                return false;
        }
        else if (o[0] == 'D') {
            if (pickup.count(order_num) == 1 && delivery.count(order_num) == 0) {
                delivery.insert(order_num);
                pickup.erase(order_num);
            }
            else
                return false;
        }
        else
            return false;
    }

    return pickup.empty();
}


bool solve2(vector<string>& orders) {
    vector<int> order_status(100000, 0);
    int order_count = 0;
    for (auto& o : orders) {
        int order_num = stoi(o.substr(1));
        if (o[0] == 'P') {
            if (order_status[order_num] == 0) {
                order_status[order_num] = 1;
                order_count++;
            }
            else
                return false;
        }
        else if (o[0] == 'D') {
            if (order_status[order_num] == 1) {
                order_status[order_num] = 2;
                order_count--;
            }
            else 
                return false;
            
        }
        else {
            return false;
        }
    }
    if (order_count == 0)
        return true;
    else
        return false;
}

/*
Input
4
P1 P2 D2 D1

Output
1
1
1
*/

int main() {
    int n;
    cin >> n;
    vector<string> orders;
    while(n -- > 0) {
        string s;
        cin >> s;
        orders.push_back(s);
    }
    cout << solve0(orders) << endl
         << solve1(orders) << endl
         << solve2(orders) << endl;
    return 0;
}