# BadHorse
Brute Forcing Bad Horse Problem Google Kick Start
Before we approach the problem we need to understand what is it that question asking. The ultimate goal of this problem is to divide each pair of bad horses to two different sets such that there is no troublesome pair in neither of the sets. More information can be found under this link; https://code.google.com/codejam/contest/2933486/dashboard

Input Format
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a positive integer M on a line by itself which represents the of troublesome pairs of League members. The next M lines each contain names of troublesome pairs, separated by a single space.

Output Format
For each test case, output one line containing “Case #x: y”, where x is the case number (starting from 1) and y is either “Yes” or “No”, depending on whether the League members mentioned in the input can be split into two groups with neither of the groups containing a troublesome pair.

The ideal solution to this problem would be using graphs, where edges are troublesome pairs and goal is to see if the graph can be divided into 2 (Same as checking if the graph is bipartite). However, I will be talking in detail about that solution in a different post.
Iwill be talking how to brute force this problem. In order to do so, I came up with this solution by getting inspired by Insertion Sort. The idea behind this solution is, you can only add new names to 2 distinct sets if and only if there adding this new element doesn’t have any trouble with the one that are already in the list.

T is # of Tests
test_size is # of names in the current test
There are three for loops, the outermost loop iterates between different tests (Iterator t = 1 to T). Middle for loop (Iterator i = 0 to test_size) will be traversing the list from the beginning and in every iteration pairs in the current index will be compared with the ones that are already in the list (Elements with index less than i). So innermost loop (Iterator j = i-1 to 0)will be checking if list1[i] is not causing trouble with list1[j] where j is from i-1 to 0. This will be done for list2 as well. And if either list1[i] or list2[i] is causing problem, then we swap them and start checking starting from index j = i-1 to 0. If Swapping fixes the problem then we are good and keep checking until i equals test_size, if swapping doesn’t fixes the we output “NO”. If every check passes we toggle passed variable and return “YES”
