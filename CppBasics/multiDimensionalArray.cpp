#include <iostream>
using namespace std;

int main()
{
    // Declare a 10x10 array
    int numRows = 10;
    int numCols = 10;
    int product[numRows][numCols] = { 0 };
 
    // Calculate a multiplication table
    for (int row = 0; row < numRows; ++row)
        for (int col = 0; col < numCols; ++col)
            product[row][col] = row * col;
 
    // Print the table
    for (int row = 1; row < numRows; ++row)
    {
        for (int col = 1; col < numCols; ++col)
            std::cout << product[row][col] << "\t";
 
        std::cout << '\n';
    }
 
    return 0;
}
