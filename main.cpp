#include "mainwindow.h"
#include <QApplication>
#include "GameClasses/maze.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int mazeWidth = 25;
    int mazeHeight = 25;
    Maze maze (mazeWidth,mazeHeight);
    int **map = maze.getMap();
    for (int i=0; i<mazeWidth; i++){
        for (int j=0; j<mazeHeight; j++){
            std::cout<<map[i][j]<<'\t';
        }
        std::cout<<'\n';
     }
    return a.exec();
}
