// USACO 2020 US Open Contest, Bronze
// Problem 3. Cowntact Tracing
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1037
/*
Farmer John is worried for the health of his cows (conveniently numbered 1…N as always) after an outbreak of the highly 
contagious bovine disease COWVID-19.
Recently, Farmer John tested all of his cows and found some of them to be positive for the disease. Using video footage from 
inside his barn, he is able to review recent interactions between pairs of cows --- it turns out that when cows greet each-other, 
they shake hooves, a gesture that can unfortunately spread the infection from one cow to another. Farmer John assembles a 
time-stamped list of interacting pairs of cows, with entries of the form (t,x,y), meaning that at time t, cow x shook hooves 
with cow y. Farmer John also knows the following:

(i) Exactly one cow on his farm could have started out carrying the disease (we'll call this cow "patient zero").
(ii) Once a cow is infected, she passes the infection along with her next K hoof shakes (possibly including the same partner 
cow several times). After shaking hooves K times, she no longer passes the infection along with subsequent hoof shakes (since 
at this point she realizes she is spreading the infection and washes her hooves carefully).
(iii) Once a cow is infected, she stays infected.

Unfortunately, Farmer John doesn't know which of his N cows is patient zero, nor does he know the value of K! Please help him 
narrow down the possibilities for these unknowns based on his data. It is guaranteed that at least one possibility is valid.

INPUT FORMAT (file tracing.in):
The first line of the input file contains N (2≤N≤100) and T (1≤T≤250). The next line contains a string of length N whose entries 
are 0s and 1s, describing the current state of Farmer John's N cows --- 0 represents a healthy cow and 1 represents a cow 
presently with the disease. Each of the next T lines describes a record in Farmer John's list of interactions and consists of 
three integers t, x, and y, where t is a positive integer time of the interaction (t≤250) and x and y are distinct integers in 
the range 1…N, indicating which cows shook hands at time t. At most one interaction happens at each point in time.

OUTPUT FORMAT (file tracing.out):
Print a single line with three integers x, y, and z, where x is the number of possible cows who could have been patient zero, 
y is the smallest possible value of K consistent with the data, and z is the largest possible value of K consistent with the 
data (if there is no upper bound on K that can be deduced from the data, print "Infinity" for z). Note that it might be possible 
to have K=0.

SAMPLE INPUT1:
4 3
1100
7 1 2
5 2 3
6 2 4

SAMPLE OUTPUT1:
1 1 Infinity

The only candidate for patient zero is cow 1. For all K>0, cow 1 infects cow 2 at time 7, while cows 3 and 4 remain uninfected.

Problem credits: Brian Dean

SAMPLE INPUT2:
4 3
1110
5 1 2
6 1 3
7 1 4

SAMPLE OUTPUT2:
2 1 2
*/
// sort contact array by t
// for all the contacts of a positive cow[i] in time order loop through K=0 to 250
// walk through all contact traces and stop as soon as condition not match and move to next K
// if all contact traces match, cow[i] is potential patient zero, continue walk over all K
// keep global min, max for K and update along the way for each cow
// note: must walk through all K values for every positive cow[i]
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int n, T;
    string cows;
    map<int, pair<int, int>> contact;
    cin >> n >> T >> cows;
    for (int i = 0; i < T; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        contact[t] = {x, y};
    }
    // for (auto i = contact.begin(); i != contact.end(); i++) {
    //     cout << "contact[" << i->first << "]: is " << i->second.first << ", " << i->second.second << '\n';
    // }
    int p = 0, mink = 250, maxk = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i] == '1') {
            bool possible_pzero = false;
            vector<bool> p_cow(n, false);
            p_cow[i] = true;
            vector<int> cow_k(n, 0);
            for (int k = 0; k < 251; k++) {
                bool possible_k = true;
                fill(p_cow.begin(), p_cow.end(), false);
                p_cow[i] = true;
                fill(cow_k.begin(), cow_k.end(), 0);
                for (auto j = contact.begin(); j != contact.end(); j++) {
                    //cout << "contact[" << j->first << "]: is " << j->second.first << ", " << j->second.second << '\n';
                    int current_cow = i+1, current_x = j->second.first, current_y = j->second.second, current_contact;
                    if (current_x == current_cow || current_y == current_cow) {
                        current_contact = current_x == current_cow ? current_y : current_x;
                        cow_k[current_cow-1] += 1;
                        if (cow_k[current_cow-1] <= k) {                            
                            if (cows[current_contact-1] == '0') {
                                possible_k = false;
                                break;
                            }
                            if (!p_cow[current_contact-1]) {
                                p_cow[current_contact-1] = true;
                            } else {
                                cow_k[current_contact-1] += 1;
                            }
                        } else if (p_cow[current_contact-1]) {
                            cow_k[current_contact-1] += 1;
                        }
                    } else {
                        if (p_cow[current_x-1] || p_cow[current_y-1]) {
                            current_cow = p_cow[current_x-1] ? current_x : current_y;
                            current_contact = p_cow[current_x-1] ? current_y : current_x;
                            cow_k[current_cow-1] += 1;
                            if (cow_k[current_cow-1] <= k) {
                                if (cows[current_contact-1] == '0') {
                                    possible_k = false;
                                    break;
                                }
                                if (!p_cow[current_contact-1]) {
                                    p_cow[current_contact-1] = true;
                                } else {                                
                                    cow_k[current_contact-1] += 1;
                                }
                            } else if (p_cow[current_contact-1]) {
                                cow_k[current_contact-1] += 1;
                            }
                        }
                    }
                }
                // once done looping all contact tracing info, compare p_cow[] and cows[] to check if match
                for (int x = 0; x < n; x++) {
                    if (p_cow[x] && cows[x] == '0') {
                        possible_k = false;
                    } else if (!p_cow[x] && cows[x] == '1') {
                        possible_k = false;
                    }
                }
                // increase patient zero count and compute min/max K
                if (possible_k) {
                    if (possible_pzero == false) {
                        possible_pzero = true;
                        p++;
                    }
                    mink = min(mink, k);
                    maxk = max(maxk, k);
                }
            }
        }
    }
    if (maxk == 250) {
        cout << p << " " << mink << " Infinity" << '\n';
    } else {
        cout << p << " " << mink << " " << maxk << '\n';
    }
    return 0;
}