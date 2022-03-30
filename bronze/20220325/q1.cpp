// USACO 2022 US Open Contest, Bronze
// Problem 1. Photoshoot
// http://www.usaco.org/index.php?page=viewproblem&cpid=1215
/*
Farmer John, desperate to win the award for best cow photographer at the county fair, is trying to take the perfect photograph 
of his N cows (2≤N≤2⋅10^5, N even).

Farmer John owns cows of two potential breeds: Guernseys and Holsteins. To make his photo as aesthetic as possible, he wants to 
line up his cows so that as many Guernseys are in even-numbered positions in the line as possible (the first position in the line 
is an odd position, the next is an even position, and so on). Due to his lack of strong communication with his cows, the only way 
he can achieve his goal is by asking even length "prefixes" of his cows to reverse themselves (a prefix consists of the range of 
cows from the first cow up to the jth cow for some position j).

Please count the minimum number of reversals required for Farmer John to achieve his goal.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains the value of N.
The second line contains a string of length N, specifying the initial ordering of the cows from left to right. Each 'H' represents 
a Holstein, while each 'G' represents a Guernsey.

OUTPUT FORMAT (print output to the terminal / stdout):
Output the minimum number of reversals needed on a single line.

SAMPLE INPUT:
14
GGGHGHHGHHHGHG

SAMPLE OUTPUT:
1

In this example, it suffices to reverse the prefix consisting of the first six cows.

   GGGHGHHGHHHGHG (Before)
-> HGHGGGHGHHHGHG (After)

Before the reversal, four Guernseys were at even positions. After the reversal, six Guernseys are at even positions. 
It is impossible for there to be more than six Guernseys at even positions.

SCORING:
Test cases 2-6 satisfy N≤1000.
Test cases 7-11 satisfy no additional constraints.
Problem credits: Aryansh Shrivastava
*/
/*
INPUT:
14
HGGHGHHGHHHGHG
OUTPUT:
2

INPUT:
8
GHHGHHGH
OUTPUT:
3
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(void) {
   int n;
   string cows;
   cin >> n >> cows;
   bool dirGH = true; // initial direction searching backwards for 'GH' - true, 'HG' - false
   int answer = 0;
   for (int i = n-1; i > 0; i-=2) {
      if (dirGH) {
         if (cows[i] == 'H' && cows[i-1] == 'G') {
            answer++;
            dirGH = false;
         }
      } else {
         if (cows[i] == 'G' && cows[i-1] == 'H') {
            answer++;
            dirGH = true;
         }         
      }
   }
   cout << answer;
   return 0;
}