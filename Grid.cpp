#include "Grid.h"
#include <ctime>
#include <cstring>
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
    cout << "1";
    int r;
        cout << "2";

    srand(time(NULL));
    cout << "3";

    grid = new Square**[y];
    for(int i = 0; i < y; ++i)
        grid[i] = new Square*[x];
            cout << "4";


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
            cout << "5";


    *currentPosition = *grid[0][0];
        cout << "6";

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
            if(currentPosition->getY() != 0)
            {
                if(grid[currentPosition->getX()][currentPosition->getY() - 1]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setY(currentPosition->getY() - 1);
                    *currentPosition = *grid[currentPosition->getX()][currentPosition->getY()];
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
            if(currentPosition->getX() != 0)
            {
                if(grid[currentPosition->getX() - 1][currentPosition->getY()]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setX(currentPosition->getX() - 1);
                    *currentPosition = *grid[currentPosition->getX()][currentPosition->getY()];
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
            if(currentPosition->getY() != (dimensionY - 1))
            {
                if(grid[currentPosition->getX()][currentPosition->getY() + 1]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setY(currentPosition->getY() + 1);
                    *currentPosition = *grid[currentPosition->getX()][currentPosition->getY()];
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
            if(currentPosition->getX() != (dimensionX - 1))
            {
                if(grid[currentPosition->getX() + 1][currentPosition->getY()]->getSquareType() != SQUARE_TYPE_NON_ACCESSIBLE)
                {
                    currentPosition->setX(currentPosition->getX() + 1);
                    *currentPosition = *grid[currentPosition->getX()][currentPosition->getY()];
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

/* Function displayMap which will show a map of the grid to the user about market, n-accessible and common
   squares and the location of the hero */
   void Grid::displayMap()
   {
        string squareTyype;
       cout << "gejuhskje";
       int squareNo = 1;
       cout << "\n\nt\n";
       cout << "jhjshfkdjhfskjdhfks";

       for(int i = 0; i < dimensionX; i++)
       {
            for(int j = 0 ; j < dimensionY; j++)
            {
                    cout << "1 ";

                if(grid[i][j]->getSquareType() == SQUARE_TYPE_COMMON)
                    squareTyype = "C";
                else if(grid[i][j]->getSquareType() == SQUARE_TYPE_MARKET)
                    squareTyype = "M";
                else if(grid[i][j]->getSquareType() == SQUARE_TYPE_NON_ACCESSIBLE)
                    squareTyype = "N-A";
                else
                    exit(1);
                        cout << "2 ";


                if(currentPosition->getX() == i && currentPosition->getY() == j)
                    squareTyype += "H";
                        cout << "3 ";


                cout << squareNo++ << squareTyype << "\t";
                    cout << "4 ";


                squareTyype = "";
                    cout << "5 ";

            }

            cout << endl;
       }
   }
