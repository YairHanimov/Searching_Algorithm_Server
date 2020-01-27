**Created by**: Yair Hanimov and Eyal Golan

**Link to Github**: https://github.com/YairHanimov/Searching_Algorithm_Server

##Overview
In this program we use a solid principle to solve generic problems that the client send to us, using algorithms.
After the design template is implemented, the following algorithms are used:
* BestFirstSearch
* DFS
* BFS (breadth first search)
* Astar

And we will do an empirical experiment to test which one works best:
1. We will set up a collection of 10 NxN size matrices for N increasing from N = 10 to N = 50 at each.
A cell will set some integer value that expresses the price to tread in that cell. For example, 0 is free or plain,
The greater the value, the more difficult it is, and infinitely it is a wall that cannot be crossed. The entrance
The area will be defined in cell 0,0 while the exit in cell 1-N, 1-N.
2. Run each of the algorithms 10 times on each of the 10 matrices)
10 x 10 runs matrices (and check how many vertices each algorithm has developed and whether it has solved -
That is the cheapest route
3. Display the data on the graph where the X axis is the N values ​​and the Y axis is the number of vertices that each developed.
Algorithm averages over the 10 runs.
By the lines created in the graph you can see which exercise is most effective. This is the realization chosen to embed on the side
The server. Emphasis: All implementations exist on the server side, but in the main we will connect only the best.
Implement the server-side algorithm

We used the Adapter Object to resolve the issue and uphold any principles
**SOLID** we learned.

**MyClientHandler**

Create the MyClientHandler class to fit the following communication protocol:
• The customer sends line by line until a line with the value “end” is received
• Each row applies a comma-separated numeric value, so the row collection creates a matrix of
Values.
• Then the customer sends two more lines. Each row has two comma-separated values: a row
Row, Col. and Column
o The values ​​in the first row indicate the entrance to the area
o The values ​​in the second row indicate the exit from the area
• Now the server returns only one string, with comma-separated values. The values ​​will be the type of words
} Right, Left, Down, Up} that indicate the direction to move in order to traverse the area
On the cheapest route.

**MyParallelServer**

We also implemented MyParallelServer to handle all clients at the same time, using threads.