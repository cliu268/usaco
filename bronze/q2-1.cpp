// USACO 2021 US Open, Bronze
// Problem 3. Acowdemia III
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1133
/*
Bessie is a busy computer science graduate student. However, even graduate students need friends. As a result, Farmer John 
has opened a pasture with the explicit purpose of helping Bessie and other cows form lasting friendships.

Farmer John's pasture can be regarded as a large 2D grid of square "cells" (picture a huge chess board). Each cell is 
labeled with:

C if the cell contains a cow.
G if the cell contains grass.
. if the cell contains neither a cow nor grass.

For two distinct cows to become friends, the cows must choose to meet at a grass-covered square that is directly 
horizontally or vertically adjacent to both of them. During the process, they eat the grass in the grass-covered square, so 
future pairs of cows cannot use that square as a meeting point. The same cow may become friends with more than one other 
cow, but no pair of cows may meet and become friends more than once.

Farmer John is hoping that numerous pairs of cows will meet and become friends over time. Please determine the maximum 
number of new friendships between distinct pairs of cows that can possibly be created by the end of this experience.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains N and M (N,M≤1000).
The next N lines each contain a string of M characters, describing the pasture.

OUTPUT FORMAT (print output to the terminal / stdout):
Count the maximum number of pairs of cows that can become friends by the end of the experience.

SAMPLE INPUT:
4 5
.CGGC
.CGCG
CGCG.
.CC.C

SAMPLE OUTPUT:
4

If we label the cow in row i and column j with coordinates (i,j), then in this example there are cows at (1,2), (1,5), (2,2), 
(2,4), (3,1), (3,3), (4,2), (4,3), and (4,5). One way for four pairs of cows to become friends is as follows:

The cows at (2,2) and (3,3) eat the grass at (3,2).
The cows at (2,2) and (2,4) eat the grass at (2,3).
The cows at (2,4) and (3,3) eat the grass at (3,4).
The cows at (2,4) and (1,5) eat the grass at (2,5).

SCORING:
Test cases 2-4 satisfy N=2.
Test cases 5-12 satisfy no additional constraints.

Problem credits: Benjamin Qi
*/
#include <iostream>
#include <vector>
using namespace std;
struct cow {
    int x, y;
    cow(int a, int b) : x(a), y(b) {}
};
struct cowpair {
    cow x, y;
    cowpair(cow a, cow b) : x(a), y(b) {} 
};

bool operator==(const cow &right, const cow &left) {
    return (right.x == left.x && right.y == left.y);
}

bool operator==(const cowpair &right, const cowpair &left) {
        return ((right.x == left.x && right.y == left.y) || (right.x == left.y && right.y == left.x));
}

bool operator!=(const cowpair &right, const cowpair &left) {
        return !(right == left);
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<string> map;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        map.push_back(row);
    }
    int answer = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<cowpair> cp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'G') {
                vector<cow> c;
                for (int k = 0; k < 4; k++) {
                    int x = i+dx[k], y = j+dy[k];
                    if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] != 'C') {
                        continue;
                    } else {
                        c.push_back(cow(x, y));
                    }
                }
                if (c.size() < 2) {
                    continue;
                } else if (c.size() == 2) {
                    if (c[0].x != c[1].x && c[0].y != c[1].y) {
                        cowpair temp = cowpair(c[0], c[1]);
                        int i=0;
                        for (; i < cp.size(); i++) {
                            if (cp[i] == temp) {
                                break;
                            }
                        }
                        if (i < cp.size()) {
                            continue;
                        } else {
                            cp.push_back(temp);
                            answer++;
                        }
                    } else {
                        answer++;
                    }
                } else { // at least 3 cows
                    answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}