#include "Grid.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Square.h"
#include "CommonSquare.h"
#include "MarketSquare.h"
#include "nonAccessibleSquare.h"

using namespace std;

/* Class Ctor */
Grid::Grid(int x, int y): dimensionX(x), dimensionY(y)
{
    int r;
    srand(time(NULL));

    grid = new Square**[y];
    for(int i = 0; i < y; ++i)
        grid[i] = new Square*[x];

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
        {
            r = rand()/100;
            if( r > COMMON_SQUARE_POSSIBILITY)
                grid[i][j] = new CommonSquare(i, j);
            else if( r > MARKET_SQUARE_POSSIBILITY)
                grid[i][j] = new MarketSquare(i, j);
            else
                grid[i][j] = new nonAccessibleSquare(i, j);
        }

    currentPosition = *grid[0][0];
}

/* Class Dtor */
Grid::~Grid()
{
    for(int i = 0; i < dimensionX; i++)
        for(int j = 0; j < dimensionY; j++)
            delete grid[i][j];

    for(int i = 0; i < dimensionY; ++i)
        delete[] grid[i];

    delete[] grid;
}

/* Getter for the X dimension of the grid */
int Grid::getDimX()
{
    return dimensionX;
}

/* Getter for the Y dimension of the grid */
int Grid::getDimY()
{
    return dimensionY;
}

/* Function to move the hero onto the Grid */
void Grid::moveGrid(char direction)
{
    switch(direction)
    {
        case 'w':
            if(currentPosition.getY() != 0)
            {
                if(grid[currentPosition.getX()][currentPosition.getY() - 1]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition.setY(currentPosition.getY() - 1);
                    currentPosition = *grid[currentPosition.getX()][currentPosition.getY()];
                }
                else
                {
                    cout << "You can't move forward because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move forward because you're at the top of the map" << endl;
            }

            break;

        case 'a':
            if(currentPosition.getX() != 0)
            {
                if(grid[currentPosition.getX() - 1][currentPosition.getY()]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition.setX(currentPosition.getX() - 1);
                    currentPosition = *grid[currentPosition.getX()][currentPosition.getY()];
                }
                else
                {
                    cout << "You can't move to the left because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move to the left because you're at the left edge of the map" << endl;
            }

            break;

        case 's':
            if(currentPosition.getY() != (dimensionY - 1))
            {
                if(grid[currentPosition.getX()][currentPosition.getY() + 1]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition.setY(currentPosition.getY() + 1);
                    currentPosition = *grid[currentPosition.getX()][currentPosition.getY()];
                }
                else
                {
                    cout << "You can't move backward because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move backward because you're at the bottom of the map" << endl;
            }

            break;

        case 'd':
            if(currentPosition.getX() != (dimensionX - 1))
            {
                if(grid[currentPosition.getX() + 1][currentPosition.getY()]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition.setX(currentPosition.getX() + 1);
                    currentPosition = *grid[currentPosition.getX()][currentPosition.getY()];
                }
                else
                {
                    cout << "You can't move to the right because that's a non Accessible Map Area" << endl;
                }
            }
            else
            {
                cout << "You can't move to the right because you're at the right edge of the map" << endl;
            }

            break;

    }
}

