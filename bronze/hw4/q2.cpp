// USACO 2015 February Contest, Bronze
// Problem 1. Censoring (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=526
/*
Farmer John has purchased a subscription to Good Hooveskeeping magazine for his cows, so they have plenty of material to read 
while waiting around in the barn during milking sessions. Unfortunately, the latest issue contains a rather inappropriate 
article on how to cook the perfect steak, which FJ would rather his cows not see (clearly, the magazine is in need of better 
editorial oversight).

FJ has taken all of the text from the magazine to create the string S of length at most 10^6 characters. From this, he would 
like to remove occurrences of a substring T of length <= 100 characters to censor the inappropriate content. To do this, Farmer 
John finds the _first_ occurrence of T in S and deletes it. He then repeats the process again, deleting the first occurrence of 
T again, continuing until there are no more occurrences of T in S. Note that the deletion of one occurrence might create a 
new occurrence of T that didn't exist before.

Please help FJ determine the final contents of S after censoring is complete.

INPUT FORMAT: (file censor.in)
The first line will contain S. The second line will contain T. The length of T will be at most that of S, and all characters of 
S and T will be lower-case alphabet characters (in the range a..z).

OUTPUT FORMAT: (file censor.out)
The string S after all deletions are complete. It is guaranteed that S will not become empty during the deletion process.

SAMPLE INPUT:
whatthemomooofun
moo

SAMPLE OUTPUT:
whatthefun

[Problem credits: Mark Gordon, 2015]
*/
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void) {
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string S, T, ans="";
    cin >> S >> T;
    for (int i = 0; i < S.length(); i++) {
        ans += S[i];
        if (ans.length() >= T.length()) {
            if (ans.substr(ans.length() - T.length()) == T) {
                ans.erase(ans.length() - T.length());
            }
        } 
    }
    cout << ans;
    return 0;
}