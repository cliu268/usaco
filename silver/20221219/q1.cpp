// USACO 2022 December Contest, Silver
// Problem 1. Barn Tree
// http://www.usaco.org/index.php?page=viewproblem&cpid=1242
/*
**Note: the time limit for this problem is 4s, two times the default. The memory limit is also twice the default.**
Farmer John's farm has N barns (2≤N≤2⋅10^5) numbered 1…N. There are N−1 roads, where each road connects two barns and it is 
possible to get from any barn to any other barn via some sequence of roads. Currently, the jth barn has hj hay bales (1≤hj≤10^9).

To please his cows, Farmer John would like to move the hay such that each barn has an equal number of bales. He can select any 
pair of barns connected by a road and order his farmhands to move any positive integer number of bales less than or equal to 
the number of bales currently at the first barn from the first barn to the second.

Please determine a sequence of orders Farmer John can issue to complete the task in the minimum possible number of orders. 
It is guaranteed that a sequence of orders exists.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains the value of N.
The second line of input contains the space-separated values of hj for j=1…N.
The final N−1 lines of input each contain two space-separated barn numbers ui vi, indicating that there is a bidirectional road 
connecting ui and vi.

OUTPUT FORMAT (print output to the terminal / stdout):
Output the minimum possible number of orders, followed a sequence of orders of that length, one per line.
Each order should be formatted as three space-separated positive integers: the source barn, the destination barn, and the third 
describes the number of hay bales to move from the source to the destination.

If there are multiple solutions, output any.

SAMPLE INPUT:
4
2 1 4 5
1 2
2 3
2 4

SAMPLE OUTPUT:
3
3 2 1
4 2 2
2 1 1
In this example, there are a total of twelve hay bales and four barns, meaning each barn must have three hay bales at the end. 
The sequence of orders in the sample output can be verbally translated as below:

From barn 3 to barn 2, move 1 bale.
From barn 4 to barn 2, move 2 bales.
From barn 2 to barn 1, move 1 bale.

SCORING:
Test cases 2-8 satisfy N≤5000
Test cases 7-10 satisfy vi=ui+1
Test cases 11-16 satisfy no additional constraints

Problem credits: Aryansh Shrivastava
*/