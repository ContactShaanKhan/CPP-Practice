#include <iostream>

using namespace std;

// Stores a 2D array as a 1D array
class Matrix
{
private:
    int *arr, len;

public:
    Matrix(int size)
    {
        // Create an array of size size^2
        arr = (int *)calloc(size * size, sizeof(int));
        len = size;
    }

    void set(int row, int col, int val)
    {
        if (row < 0 || col < 0 || row >= len || col >= len)
            throw "Out of bounds";

        arr[(len * row) + col] = val;
    }

    int get(int row, int col)
    {
        if (row < 0 || col < 0 || row >= len || col >= len)
            throw "Out of bounds";

        return arr[(len * row) + col];
    }

    void printMatrix()
    {
        for (int row = 0; row < len; row++)
        {
            cout << "[ ";
            for (int col = 0; col < len; col++)
            {
                cout << to_string(get(row, col)) << ", ";
            }
            cout << "]\n";
        }
    }
};

int main()
{
    string s;
    int size;

    // Get the size we want
    cout << "Please enter the height/width of the matrix (e.g. `100`)\n";
    cin >> s;

    cout << "You entered: " << s << "\n";

    size = stoi(s);

    Matrix *m = new Matrix(size);

    m->set(2, 2, 100);
    m->set(3, 3, 1212);

    m->printMatrix();

    return 0;
}
