// USACO 2023 January Contest, Bronze
// Problem 3. Moo Operations
// http://www.usaco.org/index.php?page=viewproblem&cpid=1265
/*
Because Bessie is bored of playing with her usual text string where the only characters are 'C,' 'O,' and 'W,' Farmer John gave 
her Q new strings (1≤Q≤100), where the only characters are 'M' and 'O.' Bessie's favorite word out of the characters 'M' and 'O' 
is obviously "MOO," so she wants to turn each of the Q strings into "MOO" using the following operations:
    1. Replace either the first or last character with its opposite (so that 'M' becomes 'O' and 'O' becomes 'M').
    2. Delete either the first or last character.
Unfortunately, Bessie is lazy and does not want to perform more operations than absolutely necessary. For each string, please help 
her determine the minimum number of operations necessary to form "MOO" or output −1 if this is impossible.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input contains the value of Q.
The next Q lines of input each consist of a string, each of its characters either 'M' or 'O'. Each string has at least 1 and at 
most 100 characters.

OUTPUT FORMAT (print output to the terminal / stdout):
Output the answer for each input string on a separate line.

SAMPLE INPUT:
3
MOMMOM
MMO
MOO

SAMPLE OUTPUT:
4
-1
0

A sequence of 4 operations transforming the first string into "MOO" is as follows:
Replace the last character with O (operation 1)
Delete the first character (operation 2)
Delete the first character (operation 2)
Delete the first character (operation 2)
The second string cannot be transformed into "MOO." The third string is already "MOO," so no operations need to be performed.

SCORING:
Inputs 2-4: Every string has length at most 3.
Inputs 5-11: No additional constraints.
Problem credits: Aryansh Shrivastava
*/