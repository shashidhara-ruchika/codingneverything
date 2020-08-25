/*
https://www.codechef.com/LRNDSA03/problems/CVOTE
*/

/*
Input:
first line:   n m 
next n lines: chef country
next m lines: chef
4 5
Ramanujan India
Torricelli Italy
Gauss Germany
Lagrange Italy
Ramanujan
Torricelli
Torricelli
Ramanujan
Lagrange

Output:
Country winner   - lexicographically smallest country with largest num of votes
Chef of the year - lexicographically smallest chef with largest num of votes
Italy
Ramanujan

Since keys of map is in ascending order, it will be in lexicographical order

Structure of country_count map: - First max count gives Country winner
Country : Count
Germany : 0
India   : 2
Italy   : 3

Structure of chef_country_count map: - First max count gives Chef of the year
Chef       : < Country , Count>
Gauss      : < Germany , 0 >
Lagrange   : < Italy   , 1 >
Ramanujan  : < India   , 2 >
Torricelli : < Italy   , 2 >
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long int n, m;
	cin >> n >> m;
	map<string, long int> country_count;
	map<string, pair<string, long int>> chef_country_count;
	string chef, country;
	for(int i = 0; i < n ; i++) {
	    cin >> chef >> country;
	    country_count.insert({country, 0});
	    chef_country_count.insert({chef, make_pair(country, 0)});
	}
	for(int i = 0; i < m; i++) {
	    cin >> chef;
	    country_count[chef_country_count[chef].first]++;
	    chef_country_count[chef].second++;
	}
	
	long int max_count_country = -1, max_count_chef = -1;
	string country_winner, chef_year;
	for(auto x: country_count) {
	    //cout << x.first << " " << x.second << endl;
	    if(x.second > max_count_country) {
	        max_count_country = x.second;
	        country_winner = x.first;
	    }
	}
	//cout << endl;
	for(auto x: chef_country_count) {
	    //cout << x.first << " " << x.second.first << " " << x.second.second << endl;
	    if(x.second.second > max_count_chef) {
	        max_count_chef = x.second.second;
	        chef_year = x.first;
	    }
	}
	//cout << endl;
	cout << country_winner << endl;
	cout << chef_year << endl;
	return 0;
}
