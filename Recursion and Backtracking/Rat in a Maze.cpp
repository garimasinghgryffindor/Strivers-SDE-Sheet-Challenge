Rat in a Maze


Problem Statement: Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.



Solution 1: Recursion
Intuition:
The best way to solve such problems is using recursion.


Approach:
Start at the source(0,0) with an empty string and try every possible path i.e upwards(U), downwards(D), leftwards(L) and rightwards(R).
As the answer should be in lexicographical order so it’s better to try the directions in lexicographical order i.e (D,L,R,U)
Declare a 2D-array named visited because the question states that a single cell should be included only once in the path,so it’s important to keep track of the visited cells in a particular path.
If a cell is in path, mark it in the visited array.
Also keep a check of the “out of bound” conditions while going in a particular direction in the matrix. 
Whenever you reach the destination(n,n) it’s very important to get back as shown in the recursion tree.
While getting back, keep on unmarking the visited array for the respective direction.Also check whether there is a different path possible while getting back and if yes, then mark that cell in the visited array.


void recur(vector<vector<int>>maze,int n,vector<vector<int>>&res,vector<int>temp,int r,int c) {
  if(r==n-1 && c==n-1) {
    res.push_back(temp);
    return;
  }

  // i can either of go right, or left, or top , or bottom
  // secondly i don't have to repeat same node in a path


  // go right
  if(c<n-1 && !temp[(r)*(n)+c+1] && maze[r][c+1]) {
    temp[(r)*(n)+c+1] = 1;
    recur(maze,n,res,temp,r,c+1);
    temp[(r)*(n)+c+1] = 0;
  }

  // go down
  if(r<n-1 && !temp[(r+1)*(n)+c] && maze[r+1][c]) {
    temp[(r+1)*(n)+c] = 1;
    recur(maze,n,res,temp,r+1,c);
    temp[(r+1)*(n)+c] = 0;
  }

  // go left
  if(c>0 && !temp[(r)*(n)+c-1] && maze[r][c-1]) {
    temp[(r)*(n)+c-1] = 1;
    recur(maze,n,res,temp,r,c-1);
    temp[(r)*(n)+c-1] = 0;
  }

  // go top
  if(r>0 && !temp[(r-1)*(n)+c] && maze[r-1][c]) {
    temp[(r-1)*(n)+c] = 1;
    recur(maze,n,res,temp,r-1,c);
    temp[(r-1)*(n)+c] = 0;
  }

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> res;
  vector<int>temp(n*n,0);
  temp[0] = 1;
  recur(maze,n,res,temp,0,0);

  sort(res.begin(),res.end());

  return res;

}
