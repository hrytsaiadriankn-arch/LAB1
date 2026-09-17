#include "Matrix.h"
#include <iostream>
#include <cstdlib>
using namespace std;

bool Matrix::setRows(int value)
{
    if (value > 0)
    {
        rows = value;
        return true;
    }
    else
    {
        rows = 0;
        return false;
    }
}

bool Matrix::setCols(int value)
{
    if (value > 0)
    {
        cols = value;
        return true;
    }
    else
    {
        cols = 0;
        return false;
    }
}

bool Matrix::setMatrix(float** value)
{
    if (value != nullptr)
    {
        matrix = value;
        return true;
    }
    else
    {
        matrix = nullptr;
        return false;
    }
}

bool Matrix::Init(int rows, int cols)
{
    if (!setRows(rows) || !setCols(cols))
        return false;

    matrix = new float* [rows];

    for (int i = 0; i < rows; i++)
        matrix[i] = new float[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;

    return true;
}

void Matrix::Read()
{
    int rows, cols;

    do
    {
        cout << "Rows = ? ";
        cin >> rows;

        cout << "Columns = ? ";
        cin >> cols;
    } while (!Init(rows, cols));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
}

void Matrix::Display() const
{
    cout << "Matrix:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";

        cout << endl;
    }
}

void Matrix::SetElement(int row, int col, float value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
        matrix[row][col] = value;
}

float Matrix::GetElement(int row, int col) const
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
        return matrix[row][col];

    return 0;
}

float Matrix::getMin() const
{
    float min = matrix[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] < min)
                min = matrix[i][j];

    return min;
}

float Matrix::getMax() const
{
    float max = matrix[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];

    return max;
}

float Matrix::getSum() const
{
    float sum = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += matrix[i][j];

    return sum;
}

Matrix::~Matrix()
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
}

Matrix makeMatrix(int rows, int cols)
{
    Matrix m;

    if (!m.Init(rows, cols))
    {
        cout << "Wrong arguments!" << endl;
        exit(1);
    }

    return m;
}