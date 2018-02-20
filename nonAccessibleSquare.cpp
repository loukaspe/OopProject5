#include "nonAccessibleSquare.h"
#include "Square.h"
#include "Living.h"


nonAccessibleSquare::nonAccessibleSquare(int givenX, int givenY):Square(SQUARE_TYPE_NON_ACCESSIBLE, givenX, givenY)
{}

nonAccessibleSquare::~nonAccessibleSquare(){}

void nonAccessibleSquare::displayMenu(Hero*){}

