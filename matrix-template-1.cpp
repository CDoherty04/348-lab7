#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix
{
private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin()
    {

        char filename[] = "";
        cin >> filename;
        ifstream file(filename);

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                file >> data[i][j];
            }
        }
        file.close();
    };

    // 2. Display a matrix
    void display() const
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    };

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix &other) const
    {
        Matrix result;

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix &other) const
    {
        Matrix result;

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; ++k)
                {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const
    {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            sum += data[i][i];
            // Don't count something twice
            if (i != SIZE - i - 1)
                sum += data[i][SIZE - i - 1];
        }
        return sum;
    };

    // 6. Swap matrix rows
    void swapRows(int row1, int row2)
    {
        if (row1 == row2) {
            cout << "\nSame row can't be swapped... Printing matrix anyway" << endl;
        }
        else if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                swap(data[row1][j], data[row2][j]);
            }
            cout << "\nMatrix after swapping rows:" << endl;
        }
        else
        {
            cerr << "Invalid row indices: " << row1 << " and " << row2 << endl;
        }
    };
};

int main()
{
    // Example usage:
    Matrix mat1;
    cout << "\nEnter filename for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "\nMatrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    cout << "\nEnter filename for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "\nMatrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "\nSum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "\nProduct of matrices:" << endl;
    product.display();

    cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    int row1, row2;
    // Get row 1 input
    while (1)
    {
        cout << "\nEnter row one index to switch:\n";
        cin >> row1;
        if (row1 >= 0 && row1 < SIZE) {
            break;
        }
        else {
            cout << "Enter a valid row\n";
        }
    }

    // Get row 2 input
    while (1)
    {
        cout << "\nEnter row two index to switch:\n";
        cin >> row2;
        if (row2 >= 0 && row2 < SIZE) {
            break;
        }
        else {
            cout << "Enter a valid row\n";
        }
    }
    
    mat1.swapRows(row1, row2);
    mat1.display();

    return 0;
}