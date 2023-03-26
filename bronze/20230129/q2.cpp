// USACO 2023 January Contest, Bronze
// Problem 2. Air Cownditioning II
// http://www.usaco.org/index.php?page=viewproblem&cpid=1264
/*
With the hottest recorded summer ever at Farmer John's farm, he needs a way to cool down his cows. Thus, he decides to invest in 
some air conditioners.

Farmer John's N cows (1≤N≤20) live in a barn that contains a sequence of stalls in a row, numbered 1…100. Cow i occupies a range 
of these stalls, starting from stall si and ending with stall ti. The ranges of stalls occupied by different cows are all disjoint 
from each-other. Cows have different cooling requirements. Cow i must be cooled by an amount ci, meaning every stall occupied by 
cow i must have its temperature reduced by at least ci units.

The barn contains M air conditioners, labeled 1…M (1≤M≤10). The ith air conditioner costs mi units of money to operate (1≤mi≤1000) 
and cools the range of stalls starting from stall ai and ending with stall bi. If running, the i
th air conditioner reduces the temperature of all the stalls in this range by pi (1≤pi≤10^6). Ranges of stalls covered by air 
conditioners may potentially overlap.

Running a farm is no easy business, so FJ has a tight budget. Please determine the minimum amount of money he needs to spend 
to keep all of his cows comfortable. It is guaranteed that if FJ uses all of his conditioners, then all cows will be comfortable.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains N and M.

The next N lines describe cows. The ith of these lines contains si, ti, and ci.

The next M lines describe air conditioners. The ith of these lines contains ai, bi, pi, and mi.

For every input other than the sample, you can assume that M=10.

OUTPUT FORMAT (print output to the terminal / stdout):
Output a single integer telling the minimum amount of money FJ needs to spend to operate enough air conditioners to satisfy all 
his cows (with the conditions listed above).

SAMPLE INPUT:
2 4
1 5 2
7 9 3
2 9 2 3
1 6 2 8
1 2 4 2
6 9 1 5

SAMPLE OUTPUT:
10

One possible solution that results in the least amount of money spent is to select those that cool the intervals [2,9], [1,2], 
and [6,9], for a cost of 3+2+5=10.

Problem credits: Aryansh Shrivastava and Eric Hsu
*/