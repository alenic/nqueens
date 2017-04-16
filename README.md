# nqueens
A simple program for counting the N-queens problem

## The N-Queens problem:
How many ways are there to arrange N non-attacking
queens on an N x N chessboard?

This simple program count all solutions of N-Queens problem using
a backtracking approach optimized with bit operators.

This is a table of some known results:

N    |   # Solutions
------------|------------
1    |   1
2    |   0 
3    |   0 
4    |   2 
5    |   10 
6    |   4 
7    |   40  
8    |   92  
9    |   352 
10   |   724 
11   |   2680  
12   |   14200 
13   |   73712 
14   |   365596
15   |   2279184 
16   |   14772512 
17   |   95815104 
18   |   666090624
19   |   4968057848 
20   |   39029188884
21   |   314666222712
22   |   2691008701644
23   |   24233937684440

## Installation

In a terminal:

```
$ git clone https://github.com/alenic/nqueens.git
$ cd nqueens
$ chmod +x make.sh
$ ./make.sh
```

or just compile it with command:
```
$ gcc -O3 -o nqueens nqueens.c
```

Run it!

```
$ ./nqueens
```



