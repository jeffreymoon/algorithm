#include "MazeSolver.h"
#include <stdio.h>

int main(int argc, char** argv)
{
  MazeInfo Maze;
  if(argc<2) {
    printf("Usage: MazeSolver <MazeFile>\n");
    return 0;
  }

  if(GetMaze(argv[1], &Maze) == FAIL) {
    return 0;
  }
  if(Solve(&Maze) == FAIL) {
    return 0;
  }
  for(int i = 0; i < Maze.RowSize; i++) {
    for(int j = 0; j < Maze.ColumnSize; j++) {
      printf("%c", Maze.Data[i][j]);
    }
    printf("\n");
  }
  return 0;
}