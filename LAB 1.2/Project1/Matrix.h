#pragma once

class Matrix
{
private:
    float** matrix;
    int rows;
    int cols;

public:
    float** getMatrix() const { return matrix; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    bool setRows(int);
    bool setCols(int);
    bool setMatrix(float**);

    bool Init(int rows, int cols);
    void Read();
    void Display() const;

    void SetElement(int row, int col, float value);
    float GetElement(int row, int col) const;

    float getMin() const;
    float getMax() const;
    float getSum() const;

    ~Matrix();
};

Matrix makeMatrix(int rows, int cols);
