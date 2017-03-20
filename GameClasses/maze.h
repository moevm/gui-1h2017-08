#ifndef MAZE_H
#define MAZE_H

#include <stdlib.h>
#include <string.h>
#include <vector>
using std::vector;

class Maze{
    struct Cell{ //структура, хранящая координаты клетки в матрице
        unsigned int x;
        unsigned int y;
    };

    struct CellString{
        Cell *cells;
        unsigned int size;
    };



    Cell  startPoint;
    Cell  exitPoint;
    Cell  cellNext;
    int unvisitedNum;

    vector <Cell> stack;

    int **maze;
    int height;
    int width;

public:
    Maze();
    Maze (int width,int height);
    int** getMap();

protected:
    void generate ();
    void backtrackGeneration();
    CellString getNeighbours(Cell c,int distance);
    void removeWall(Cell first, Cell second);
    void setMode(Cell c, int mode);
    unsigned int randomRange(unsigned int low, unsigned int high);
    CellString getUnvisitedCells();
    unsigned int unvisitedCount();

};

#endif
