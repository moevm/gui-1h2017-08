#ifndef MAZE_H
#define MAZE_H

#include <stdlib.h>
#include <string.h>
#include <vector>
#include <ctime>

using std::vector;

class Maze{
    struct Cell{ //структура, хранящая координаты клетки в матрице
        int x;
        int y;
    };

    struct CellString{
        Cell *cells;
        int size;
    };

    bool haveBraids;

    Cell  startPoint;
    Cell  exitPoint;
    Cell  cellNext;
    int unvisitedNum;

    vector <Cell> stack;
    vector <Cell> rooms;

    int **maze;
    int height;
    int width;

public:

    enum { CELL, WALL, VISITED };

    Maze();
    Maze (int width,int height, bool braids=true, bool rooms=true, int roomNum=-1);
    int** getMap();

protected:
    void generate ();
    void backtrackGeneration();
    CellString getNeighbours(Cell c,int distance);
    void makeBraid(Cell c);
    void removeWall(Cell first, Cell second);
    void setMode(Cell c, int mode);
    int randomRange( int low, int high);
    CellString getUnvisitedCells();
    int unvisitedCount();
    void makeRooms(int num);

};

#endif
