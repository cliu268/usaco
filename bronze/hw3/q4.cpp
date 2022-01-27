// USACO 2015 December Contest, Bronze
// Problem 2. Speeding Ticket
// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
/*
Always the troublemaker, Bessie the cow has stolen Farmer John's tractor and taken off down the road!
The road is exactly 100 miles long, and Bessie drives the entire length of the road before ultimately being pulled over by a 
police officer, who gives Bessie a ticket for exceeding the speed limit, for having an expired license, and for operating a 
motor vehicle while being a cow. While Bessie concedes that the last two tickets are probably valid, she questions whether 
the police officer was correct in issuing the speeding ticket, and she wants to determine for herself if she has indeed driven 
faster than the speed limit for part of her journey.

The road is divided into N segments, each described by a positive integer length in miles, as well as an integer speed limit 
in the range 1…100 miles per hour. As the road is 100 miles long, the lengths of all N segments add up to 100. For example, 
the road might start with a segment of length 45 miles, with speed limit 70, and then it might end with a segment of length 
55 miles, with speed limit 60.

Bessie's journey can also be described by a series of segments, M of them. During each segment, she travels for a certain 
positive integer number of miles, at a certain integer speed. For example, she might begin by traveling 50 miles at a speed 
of 65, then another 50 miles at a speed of 55. The lengths of all M segments add to 100 total miles. Farmer John's tractor 
can drive 100 miles per hour at its fastest.

Given the information above, please determine the maximum amount over the speed limit that Bessie travels during any part of 
her journey.

INPUT FORMAT (file speeding.in):
The first line of the input contains N and M, separated by a space.
The next N lines each contain two integers describing a road segment, giving its length and speed limit.

The next M lines each contain two integers describing a segment in Bessie's journey, giving the length and also the speed at 
which Bessie was driving.

OUTPUT FORMAT (file speeding.out):
Please output a single line containing the maximum amount over the speed limit Bessie drove during any part of her journey. 
If she never exceeds the speed limit, please output 0.

SAMPLE INPUT:
3 3
40 75
50 35
10 45
40 76
20 30
40 40

SAMPLE OUTPUT:
5
In this example, the road contains three segments (40 miles at 75 miles per hour, followed by 50 miles at 35 miles per hour, 
then 10 miles at 45 miles per hour). Bessie drives for three segments (40 miles at 76 miles per hour, 20 miles at 30 miles 
per hour, and 40 miles at 40 miles per hour). During her first segment, she is slightly over the speed limit, but her last 
segment is the worst infraction, during part of which she is 5 miles per hour over the speed limit. The correct answer is 
therefore 5.

Problem credits: Austin Bannister and Brian Dean
*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> road(n);
    vector<pair<int, int>> bess(m);
    for (int i = 0; i < n; i++) {
        cin >> road[i].first >> road[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> bess[i].first >> bess[i].second;
    }
    int ans = 0, r = 0, b = 0, rl = road[0].first, bl = bess[0].first;
    for (int i = 1; i <= 100; i++) {
        if (rl < i) {
            r++;
            rl += road[r].first;
        }
        if (bl < i) {
            b++;
            bl += bess[b].first;
        }
        ans = max(ans, bess[b].second - road[r].second);
    }
    cout << ans;
    return 0;
}