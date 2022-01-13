// USACO 2021 December Contest, Bronze
// Problem 3. Walking Home
// http://www.usaco.org/index.php?page=viewproblem&cpid=1145
/*
Bessie the cow is trying to walk from her favorite pasture back to her barn.
The pasture and farm are on an N×N grid (2≤N≤50), with her pasture in the top-left corner and the barn in the 
bottom-right corner. Bessie wants to get home as soon as possible, so she will only walk down and to the right. 
There are haybales in some locations that Bessie cannot walk through; she must walk around them.

Bessie is feeling a little tired today, so she wants to change the direction she walks at most K times (1≤K≤3).

How many distinct paths can Bessie walk from her favorite pasture to the barn? Two paths are distinct if Bessie walks 
in a square in one path but not in the other.

INPUT FORMAT (input arrives from the terminal / stdin):
The input for each test case contains T sub-test cases, each describing a different farm and each of which must be answered 
correctly to pass the full test case. The first line of input contains T (1≤T≤50). Each of the T sub-test cases follow.
Each sub-test case starts with a line containing N and K.
The next N lines each contain a string of N characters. Each character is either . if it is empty or H if it has a haybale. 
It is guaranteed the top-left and bottom-right corners of the farm will not contain haybales.

OUTPUT FORMAT (print output to the terminal / stdout):
Output T lines, the ith line containing the number of distinct paths Bessie can take in the ith sub-test case.

SAMPLE INPUT:
7
3 1
...
...
...
3 2
...
...
...
3 3
...
...
...
3 3
...
.H.
...
3 2
.HH
HHH
HH.
3 3
.H.
H..
...
4 3
...H
.H..
....
H...
SAMPLE OUTPUT:
2
4
6
2
0
0
6
We'll denote Bessie's possible paths as strings of D's and R's, indicating that Bessie moved either down or right, 
respectively.

In the first sub-test case, Bessie's two possible walks are DDRR and RRDD.

In the second sub-test case, Bessie's four possible walks are DDRR, DRRD, RDDR, and RRDD.

In the third sub-test case, Bessie's six possible walks are DDRR, DRDR, DRRD, RDDR, RDRD, and RRDD.

In the fourth sub-test case, Bessie's two possible walks are DDRR and RRDD.

In the fifth and sixth sub-test cases, it is impossible for Bessie to walk back to the barn.

In the seventh sub-test case, Bessie's six possible walks are DDRDRR, DDRRDR, DDRRRD, RRDDDR, RRDDRD, and RRDRDD.

SCORING:
Test case 2 satisfies K=1.
Test cases 3-5 satisfy K=2.
Test cases 6-10 satisfy K=3.

Problem credits: Nick Wu
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, n, k, ans;

void dfs(vector<string> &map, int x, int y, int &d, char c, int &ans) {
    if (x < 0 || y < 0 || x >= n || y >= n || map[x][y] == 'H') {
        return;
    }
    if (x == n-1 && y == n-1) {
        ans++;
        return;
    }
    // move down
    if (c == 'R') {
        if (d < k) {
            d++;
            c = 'D';
            dfs(map, x, y+1, d, c, ans);
            c = 'R';
            d--;
        }
    } else {
        dfs(map, x, y+1, d, c, ans);
    }

    // move right
    if (c == 'D') { 
        if (d < k) {
            d++;
            c = 'R';
            dfs(map, x+1, y, d, c, ans);
            c = 'D';
            d--;
        }
    } else {
        dfs(map, x+1, y, d, c, ans);
    }
}

int main(void) {
    cin >> T;
    for (int t = 0; t < T; t++) {
        ans = 0;
        cin >> n >> k;
        vector<string> map(n);
        for (int i = 0; i < n; i++) {
            cin >> map[i];
        }
        // cout << "********case*********" << t <<'\n';
        // for (int i = 0; i < n; i++) {
        //     cout << map[i] << '\n';
        // }
        // cout << "****************";        
        int dir = 0, x = 0, y = 0;
        char c = 'R';
        dfs(map, x+1, y, dir, c, ans);
        c = 'D';
        dfs(map, x, y+1, dir, c, ans);
        cout << ans << '\n';
    }
    return 0;
}