// USACO 2022 US Open Contest, Bronze
// Problem 2. Counting Liars
// http://www.usaco.org/index.php?page=viewproblem&cpid=1216
/*
Bessie the cow is hiding somewhere along the number line. Each of Farmer John's N other cows (1≤N≤1000) have a piece of 
information to share: the i-th cow either says that Bessie is hiding at some location less than or equal to pi, or that 
Bessie is hiding at some location greater than or equal to pi (0≤pi≤10^9).

Unfortunately, it is possible that no hiding location is consistent with the answers of all of the cows, meaning that not 
all of the cows are telling the truth. Count the minimum number of cows that must be lying.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains N.
The next N lines each contain either L or G, followed by an integer pi. L means that the i-th cow says that Bessie's hiding 
location is less than or equal to pi, and G means that i-th cow says that Bessie's hiding location is greater than or equal 
to pi.

OUTPUT FORMAT (print output to the terminal / stdout):
The minimum number of cows that must be lying.

SAMPLE INPUT:
2
G 3
L 5
SAMPLE OUTPUT:
0
It is possible that no cow is lying.

SAMPLE INPUT:
2
G 3
L 2
SAMPLE OUTPUT:
1
At least one of the cows must be lying.

Problem credits: Jesse Choe
*/
/* another sample IN:
9
L 2
G 4
L 6
G 8
L 10
G 12
G 14
L 16
G 18
another sample OUT:
4
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

// int main(void) {
//     int n;
//     cin >> n;
//     vector<int> G, L;
//     map<int, char> cows;
//     for (int i = 0; i < n; i++) {
//         char dir;
//         cin >> dir;
//         int p;
//         cin >> p;
//         if (dir == 'G') G.push_back(p);
//         else L.push_back(p);        
//         cows[p] = dir;
//     }
//     int answer = G.size(), count = answer;
//     for (auto x : cows) {
//         if (x.second == 'G') count--;
//         else {
//             //if (x.first != 10^9)
//                 count++;
//         }
//         answer = min(answer, count);
//     }
//     cout << answer;
//     return 0;
// }

int main(void) {
    int n;
    cin >> n;
    vector<int> G, L;
    for (int i = 0; i < n; i++) {
        char dir;
        cin >> dir;
        int p;
        cin >> p;
        if (dir == 'G') G.push_back(p);
        else L.push_back(p);        
    }
    sort(G.begin(), G.end());
    sort(L.begin(), L.end());
    int i = 0, j = 0, answer = G.size(), count = answer;
    while (i < G.size() && j < L.size()) {
        if (G[i] <= L[j]) {
            count--;
            i++;
        } else {
            count++;
            j++;
        }
        answer = min(answer, count);
    }
    if (i == G.size()) {
        // n-j remaining items in L
        // not possible to go smaller
    } else {
        // n-i remaining items in G
        count -= G.size()-i;
        answer = min(answer, count);
    }
    cout << answer;
    return 0;
}