/*
https://www.hackerrank.com/challenges/attending-workshops/problem
*/

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};
typedef struct Workshop Workshop;

struct Available_Workshops {
    int n;
    vector<Workshop> workshop_arr;
};
typedef struct Available_Workshops Available_Workshops;
    
//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize (int start_time[], int duration[], int n) {
    
    Available_Workshops *all_workshops_ptr = new Available_Workshops;
    all_workshops_ptr -> n = n;
    
    for (int i = 0; i < n; i++) {
       Workshop w;
       w.start_time = start_time[i];
       w.duration = duration[i];
       w.end_time = start_time[i] + duration[i];
       
       all_workshops_ptr -> workshop_arr.push_back(w);
    }
    return all_workshops_ptr;
}

bool compare_workshops(const Workshop& w1, const Workshop& w2) {
  return w1.end_time < w2.end_time;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    
    vector<Workshop> all_workshops = ptr -> workshop_arr;
    sort(all_workshops.begin(), all_workshops.end(), compare_workshops);
    
    int total_workshops_attendable = 1;
    int curr_end_time = all_workshops[0].end_time;
    
    for(int i = 1; i < ptr -> n; i++) {
        
        if (all_workshops[i].start_time >= curr_end_time) {
            total_workshops_attendable++;
            curr_end_time = all_workshops[i].end_time;
        }
    }
        
    return total_workshops_attendable;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
