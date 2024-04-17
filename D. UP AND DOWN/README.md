# Time Limit: 1s    Memory Limit: 128M

 

# Description:

There is a strange elevator. It can stop at every floor and every floor has a designated Ki（0 <= Ki <= N) . The elevator has only two buttons: up and down. When you are in floor i and press "UP", you will go up Ki floors and reach the  i+Ki floor. If you press "DOWN", you will go down Ki floors and reach the i-Ki floor. For example, in a five-floor building, k1 = 3，k2 = 3，k3 = 1，k4 = 2，k5 = 5. On floor 1, if you press "UP", you will reach the 4-th floor. If you press "DOWN", the elevator cannot do this task, because there is no -2 floor.

Given this information, find the following for a given A and B: If you are on floor A and want to go to floor B, what is the minimum number of times you have to press the "UP" or "DOWN " buttons?

 

# Input Format:

There are multiple sets of test data, each set contains 2 rows.<br>

The first line contains three integers N，A，B（1 <= N，A，B <= 200）<br>

The second line contains N integers k1，k2，...... kn<br>

A single 0 means the end of input<br>

 

# Output Format:

Output the minimum number button presses needed. If it can not be achieved, print -1.<br>

 

# Sample Input:

5 1 5<br>
3 3 1 2 5<br>
0<br>
# Sample Output:

3<br>

# Sample Input:

5 1 5<br>
1 2 3 4 5<br>
0<br>
# Sample Output:

-1<br>

# Sample Input:

5 1 5<br>
1 1 1 1 1<br>
0<br>
# Sample Output:

4<br>
