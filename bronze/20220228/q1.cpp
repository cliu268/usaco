// USACO 2022 February Contest, Bronze
// Problem 1. Sleeping in Class
// http://www.usaco.org/index.php?page=viewproblem&cpid=1191
/*
Bessie the cow was excited to recently return to in-person learning! Unfortunately, her instructor, Farmer John, is a very 
boring lecturer, and so she ends up falling asleep in class often.
Farmer John has noticed that Bessie has not been paying attention in class. He has asked another student in class, Elsie, to 
keep track of the number of times Bessie falls asleep in a given class. There are N class periods (1≤N≤105), and Elsie logs 
that Bessie fell asleep ai times (0≤ai≤106) in the i-th class period. The total number of times Bessie fell asleep across all 
class periods is at most 106.

Elsie, feeling very competitive with Bessie, wants to make Farmer John feel like Bessie is consistently falling asleep the same 
number of times in every class -- making it appear that the issue is entirely Bessie's fault, with no dependence on Farmer John's 
sometimes-boring lectures. The only way Elsie may modify the log is by combining two adjacent class periods. 
For example, if a=[1,2,3,4,5], then if Elsie combines the second and third class periods the log will become [1,5,4,5].

Help Elsie compute the minimum number of modifications to the log that she needs to make so that she can make all the numbers in 
the log equal.

INPUT FORMAT (input arrives from the terminal / stdin):
Each input will contain T (1≤T≤10) test cases that should be solved independently.
The first line contains T, the number of test cases to be solved. The T test cases follow, each described by a pair of lines. 
The first line of each pair contains N, and the second contains a1,a2,…,aN.

It is guaranteed that within each test case, the sum of all values in a is at most 106. It is also guaranteed that the sum of N 
over all test cases is at most 105.

OUTPUT FORMAT (print output to the terminal / stdout):
Please write T lines of output, giving the minimum number of modifications Elsie could perform to make all the log entries equal 
for each case.

SAMPLE INPUT:
3
6
1 2 3 1 1 1
3
2 2 3
5
0 0 0 0 0

SAMPLE OUTPUT:
3
2
0

For the first test case in this example, Elsie can change her log to consist solely of 3s with 3 modifications.
   1 2 3 1 1 1
-> 3 3 1 1 1
-> 3 3 2 1
-> 3 3 3

For the second test case, Elsie can change her log to 7 with 2 modifications.
   2 2 3
-> 2 5
-> 7

For the last test case, Elsie doesn’t need to perform any operations; the log already consists of equal entries.

Problem credits: Jesse Choe
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    int T, t;
    cin >> T;
    t = T;
    vector<int> ans(t, 0);
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        // try all possible answers from 0 modifications to n-1 modifications
        // if you mod x times, you must form n-x groups and each group should have value sum/groups
        for (int i = 0; i < n; i++) {
            int groups = n - i;
            if (sum % groups) continue; // number of groups don't work if sum cannot be divided 
            int value = sum / groups;
            int cur_sum = 0, cur_group = 0;
            bool good = true;
            for (int j = 0; j < n; j++) {
                cur_sum += a[j];
                if (cur_sum > value) {
                    good = false;
                    break;
                }                
                if (cur_sum == value) {
                    cur_group += 1;
                    cur_sum = 0;
                    if (cur_group > groups) {
                        good = false;
                        break;
                    }
                } 
            }
            if (good) {
                ans[T] = i;
                break;
            } 
        }
    }
    for (int i = 0; i < t; i++) {
        cout << ans[t-i-1] << '\n';
    }
    return 0;
}