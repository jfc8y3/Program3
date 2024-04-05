#include "functions.h"
#include <vector>
using namespace std;

//Linear search function searches for last instance of target by starting 
//from last position and uses recursion to check if target matches
//at current positsion. If found, it returns index and if not, 
//it continues the search with (pos_last - 1), and not found returns -1.

int linear_search(vector<int>& items, int& target, int pos_last) {
    if (pos_last < 0)
        return -1;
    if (target == items[pos_last])
        return pos_last;
    else
        return linear_search(items, target, pos_last - 1);
}

//Insertion sort iterates through vector and compares each element with the
//element before it. If element is smaller than previous, move previous
//element one position to right. 

void insertion_sort(vector<int>& num) {
    int i, j, key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++) {
        key = num[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < num[i]) {
                num[i + 1] = num[i]; 
                insertionNeeded = true;
            }
            else {
                break;
            }
        }
        if (insertionNeeded) {
            num[i + 1] = key; 
        }
    }
}