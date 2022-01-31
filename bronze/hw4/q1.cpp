// USACO 2017 January Contest, Bronze
// Problem 3. Cow Tipping
// http://www.usaco.org/index.php?page=viewproblem2&cpid=689
/*
Farmer John occasionally has trouble with bored teenagers who visit his farm at night and tip over his cows. One morning, he 
wakes up to find it has happened again -- his N^2 cows began the night grazing in a perfect N×N square grid arrangement (1≤N≤10), 
but he finds that some of them are now tipped over.
Fortunately, Farmer John has used parts from his tractor and forklift to build a glorious machine, the Cow-Untipperator 3000, 
that can flip over large groups of cows all at once, helping him put all his cows back on their feet as quickly as possible. 
He can apply the machine to any "upper-left rectangle" in his grid of cows -- a rectangular sub-grid that contains the upper-left 
cow. When he does so, the machine flips over every cow in this rectangle, placing tipped cows back on their feet, but unfortunately 
also tipping over cows that were already on their feet! In other words, the machine "toggles" the state of each cow in the rectangle.

Farmer John figures that by applying his machine sufficiently many times to the appropriate collection of rectangles, he can 
eventually restore all the cows to their rightful, un-tipped states. Please help him determine the minimum number of applications 
of his machine needed to do this.

Note that applying the machine to the same rectangle twice would be pointless, since this would have no net impact on the cows 
in the rectangle. Therefore, you should only consider applying the machine to each upper-left rectangle possibly only once.

INPUT FORMAT (file cowtip.in):
The first line of the input is the integer N.
Each of the N subsequent lines contains a string of N characters, each either 0 (representing an up-tipped cow) or 1 
(representing a tipped cow).

OUTPUT FORMAT (file cowtip.out):
Please output the minimum number of times Farmer John needs to apply the Cow-Untipperator 3000 to restore all his cows to their feet.

SAMPLE INPUT:
3
001
111
111

SAMPLE OUTPUT:
2

In this example, if FJ applies his machine to the entire herd of cows (which is a valid upper-left rectangle), he will toggle 
their state to the following:
110
000
000
All that remains is to apply the machine to the upper-left rectangle containing the two 1s, and he is finished. In total, 
this is just 2 applications.

Problem credits: Nathan Pinsker
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<string> cow(n);
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (cow[i][j] == '1') {
                ans++;
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        if (cow[x][y] == '0') {
                            cow[x][y] = '1';
                        } else {
                            cow[x][y] = '0';
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}