// USACO 2022 December Contest, Silver
// Problem 3. Range Reconstruction
// http://www.usaco.org/index.php?page=viewproblem&cpid=1244
/*
Bessie has an array a1,…,aN, where 1≤N≤300 and 0≤ai≤10^9 for all i. She won't tell you a itself, but she will tell you the range 
of each subarray of a. That is, for each pair of indices i≤j, Bessie tells you r(i,j)=maxa[i…j]−mina[i…j]. Given these values of 
r, please construct an array that could have been Bessie's original array. The values in your array should be in the 
range [−10^9,10^9].

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains N.
Another N lines follow. The ith of these lines contains the integers r(i,i),r(i,i+1),…,r(i,N).
It is guaranteed that there is some array a with values in the range [0,10^9] such that for all i≤j, 
r(i,j)=maxa[i…j]−mina[i…j].

OUTPUT FORMAT (print output to the terminal / stdout):
Output one line containing N integers b1,b2,…,bN in the range [−10^9,10^9] representing your array. They must satisfy 
r(i,j)=maxb[i…j]−minb[i…j] for all i≤j.

SAMPLE INPUT:
3
0 2 2
0 1
0

SAMPLE OUTPUT:
1 3 2
For example, r(1,3)=maxa[1…3]−mina[1…3]=3−1=2.

SAMPLE INPUT:
3
0 1 1
0 0
0

SAMPLE OUTPUT:
0 1 1
This example satisfies the constraints for subtask 1.

SAMPLE INPUT:
4
0 1 2 2
0 1 1
0 1
0

SAMPLE OUTPUT:
1 2 3 2
This example satisfies the constraints for subtask 2.

SAMPLE INPUT:
4
0 1 1 2
0 0 2
0 2
0

SAMPLE OUTPUT:
1 2 2 0

SCORING:
Test 5 satisfies r(1,N)≤1.
Tests 6-8 satisfy r(i,i+1)=1 for all 1≤i<N.
Tests 9-14 satisfy no additional constraints.

Problem credits: Danny Mittal
*/