# sudoku-8x8
EZSUDOKU - Easy modified sudoku Do you know the old famous game, sudoku? It is a logic-based,combinatorial number-placement puzzle. 
The objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 sub-grids that compose the grid 
(also called "boxes", "blocks", "regions", or "sub-squares") contains all of the digits from 1 to 9. The puzzle setter provides a 
partially completed grid, which for a well-posed puzzle has a unique solution. Completed puzzles are always a type of Latin square with 
an additional constraint on the contents of individual regions. For example, the same single integer may not appear twice in the same row, 
column or in any of the nine 3×3 subregions of the 9x9 playing board. French newspapers featured variations of the puzzles in the 19th 
century, and the puzzle has appeared since 1979 in puzzle books under the name Number Place.However, the modern Sudoku only started to 
become mainstream in 1986 by the Japanese puzzle company Nikoli, under the name Sudoku, meaning single number. It first appeared in a US 
newspaper and then The Times (UK) in 2004, from the efforts of Wayne Gould, who devised a computer program to rapidly produce distinct 
puzzles. Since the Sudoku game is pretty hard, Mr. Bruce Banner, who is also fond in sudoku games, creates a new modified version of 
normal sudoku. It is tiled by 8x8 grids and divided into 4 areas of 4x4 grids. The rule is also simplified. You need to place numbers 
from 1 to 8 to the empty grids(denoted by a number 0) to the sudoku puzzle. Each number in the same columns or row must be distinct. 
In each area of 4x4 grids, it is allowed to have duplicate numbers up to 2 numbers. Now, your task is to help Mr. Bruce Banner to 
determine whether the modified sudoku puzzle he has created is of a valid puzzle or not. If it is a valid puzzle, you will also need to 
output the solution. Note: It is guaranteed that here is a unique answer in each test cases t  Input The first line of input contains an 
integer T(1 ≤ T ≤ 100), the number of testcases. Then, it will be followed by 8*T lines which contain the modified sudoku puzzles. 
Each testcases will be separated by a newline. Output For each case print "Test case #X: ", where X (1 ≤ X ≤ T) is the case number, 
followed by an answer "YES" or "NO" and a newline. If there exists a valid solution, print the solution of each puzzles, and then print 
a newline. 
Example Input: 
2 
1 2 3 4 5 6 7 0 
5 6 2 1 3 4 0 7 
6 5 0 7 2 1 3 4 
3 4 7 8 6 5 2 1 
2 1 5 6 8 7 4 3 
4 3 6 5 7 8 1 2 
0 7 1 2 4 3 5 6 
7 0 4 3 1 2 6 5  

1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1   

Output: 
Test case #1: YES 
1 2 3 4 5 6 7 8 
5 6 2 1 3 4 8 7 
6 5 8 7 2 1 3 4 
3 4 7 8 6 5 2 1 
2 1 5 6 8 7 4 3 
4 3 6 5 7 8 1 2 
8 7 1 2 4 3 5 6 
7 8 4 3 1 2 6 5 
Test case #2: NO
