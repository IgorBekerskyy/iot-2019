#include <iostream>
#include <stdio.h>
class ArrayColumn
{
    friend void sortMatrix(ArrayColumn matrix[]);
    friend void inputMatrix(ArrayColumn matrix[]);
    friend void outputMatrix(ArrayColumn matrix[]);
    friend void FunctionMain(ArrayColumn matrix[]);

private:
    int column[5];

public:
    void merge(int *A, int left, int middle, int right)
    {
        int i = left, j = middle + 1, k = 0;
        int T[right - left + 1];
        while (i <= middle && j <= right)
        {
            if (A[i] > A[j])
            {
                T[k] = A[i];
                i++;
            }
            else
            {
                T[k] = A[j];
                j++;
            }
            k++;
        }
        while (i <= middle)
        {
            T[k] = A[i];
            k++;
            i++;
        }
        while (j <= right)
        {
            T[k] = A[j];
            k++;
            j++;
        }
        for (i = left; i <= right; i++)
            A[i] = T[i - left];
    }
    void mergesort(int *A, int left, int right)
    {
        /* for (int i = left; i < right; i++)
        std::cout << A[i] << '\t';
    std::cout << std::endl;*/
        int middle = (left + right) / 2;
        if ((right - left) > 0)
        {
            mergesort(A, left, middle);
            mergesort(A, middle + 1, right);
        }
        merge(A, left, middle, right);
    }
};
void inputMatrix(ArrayColumn matrix[])
{
    std::cout << "please enter matrix" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cin >> matrix[i].column[j];
        }
    }
}
void outputMatrix(ArrayColumn matrix[])
{
    std::cout << "here is matrix" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << matrix[i].column[j] << '\t';
        }
        std::cout << std::endl;
    }
}

void sortMatrix(ArrayColumn matrix[])
{
    for (int i = 0; i < 5; i++)
    {
        matrix[i].mergesort(matrix[i].column, 0, 4);
    }
}
void FunctionMain(ArrayColumn matrix[])
{
    double average, product = 1;
    for (int j = 0; j < 4; j++)
    {
        average = 0;
        for (int i = 0; i < 4 - j; i++)
        {
            average += matrix[i].column[j];
        }
        average /= 4 - j;
        product *= average;
        std::cout << "the average " << j << "=" << average << std::endl;
    }
    std::cout << "product of average =" << product << std::endl;
}
int main()
{
    ArrayColumn matrix[5];
    inputMatrix(matrix);
    outputMatrix(matrix);
    sortMatrix(matrix);
    outputMatrix(matrix);
    FunctionMain(matrix);
    return 0;
}