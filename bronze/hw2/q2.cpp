// USACO 2019 December Contest, Bronze
// Problem 2. Where Am I?
// http://www.usaco.org/index.php?page=viewproblem2&cpid=964
/*
Farmer John has gone out for a walk down the road and thinks he may now be lost!
Along the road there are N farms (1≤N≤100) in a row. Farms unfortunately do not have house numbers, making it hard for Farmer 
John to figure out his location along the road. However, each farm does have a colorful mailbox along the side of the road, 
so Farmer John hopes that if he looks at the colors of the mailboxes nearest to him, he can uniquely determine where he is.

Each mailbox color is specified by a letter in the range A..Z, so the sequence of N mailboxes down the road can be represented 
by a string of length N containing letters in the range A..Z. Some mailboxes may have the same colors as other mailboxes. 
Farmer John wants to know what is the smallest value of K such that if he looks at any sequence of K consecutive mailboxes, 
he can uniquely determine the location of that sequence along the road.

For example, suppose the sequence of mailboxes along the road is 'ABCDABC'. Farmer John cannot set K=3, since if he sees 'ABC', 
there are two possible locations along the road where this consecutive set of colors might be. The smallest value of K that 
works is K=4, since if he looks at any consecutive set of 4 mailboxes, this sequence of colors uniquely determines his position 
along the road.

INPUT FORMAT (file whereami.in):
The first line of input contains N, and the second line contains a string of N characters, each in the range A..Z.

OUTPUT FORMAT (file whereami.out):
Print a line containing a single integer, specifying the smallest value of K that solves Farmer John's problem.

SAMPLE INPUT:
7
ABCDABC

SAMPLE OUTPUT:
4

Problem credits: Brian Dean
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    string input;
    cin >> input;
    int size;
    for (size = 1; size < n; size++) {
        bool same = false;
        for (int i = 0; i <= n-size; i++) {
            for (int j = i+1; j <= n-size; j++) {
                int k = 0;
                for (; k < size; k++) {
                    if (input[i+k] != input[j+k]) {
                        break;
                    }
                }
                if (k == size) {
                    same = true;
                    break;
                }
            }
            if (same) {
                break;
            }
        }
        if (!same) break;
    }   
    cout << size;
    return 0;
}

// It is possible to do faster by using a data structure known as a set. 
// Sets cannot store duplicate elements but are able to quickly identify if a given element is already part of the set. 
// Therefore, to check if a given value of K is valid using a set, we can check if a substring is present in the set before 
// inserting it. If some substring is already present, then the given value of K is invalid.
// Here is Brian Dean's solution using a set.
/*
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;
 
int N;
string S;
 
bool dups(int len)
{
  set<string> X;
  for (int i=0; i<=N-len; i++) {
    if (X.count(S.substr(i,len)) > 0) return true;
    X.insert(S.substr(i,len));
  }
  return false;
}
 
int main(void)
{
  ifstream fin ("whereami.in");
  ofstream fout ("whereami.out");
  fin >> N >> S;
  int ans = 1;
  while (dups(ans)) ans++;
  fout << ans << "\n";
  return 0;
}
*/