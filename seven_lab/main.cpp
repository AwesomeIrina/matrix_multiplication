#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <random>
#include "omp.h"


//template<typename T>
//class matrix
//{
//public:

//    int columns = 0;
//    int rows = 0;
//    matrix(int rows, int columns)
//    {
//        this->rows = rows;
//        this->columns = columns;

//        multiplicationMatrix.resize(rows, std::vector<T>(columns));
//        doThings();
//    }
//    const std::vector<T> *operator[](int i) const {
//        return multiplicationMatrix[i];
//    }
//    void doThings();
//    void fillMatrix();
//    void printMatrix();
//    void matrixMultiplication();

//};


//template<typename T>
//void matrix<T>::doThings()
//{
//    fillMatrix();
//}


//template<typename T>




////число столбцов первой матрицы = числу строк второй матрицы
////у результирующей матрицы столько строк, сколько в первой матрице
////и столько столбцов, сколько во второй

//template<typename T>
//void matrixMultiplication(matrix<double> firstMatrix, matrix<double> secondMatrix)
//{
//    int i = 0, j = 0, k = 0;
//    int rows = firstMatrix.rows; //строки первой матрицы
//    int columns = secondMatrix.columns; //столбцы второй
//    int secondMatrixrows = secondMatrix.rows; //строки второй

//    std::vector<std::vector<T>> result(rows, std::vector<T>(columns));
//    //идём по строкам первой матрицы
//    //умножаем результат на столбцы второй матрицы
//    for(i = 0; i < rows; i++){
//        for(j = 0; j < columns; j++){
//            for(k = 0; k < secondMatrixrows; k++){
//                result[i][j] += firstMatrix[i][j]*secondMatrix[j][k];
//            }
//        }
//    }
//}



void printMatrix(std::vector<std::vector<double>>&matrix)
{
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.at(0).size(); j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void fillMatrix(std::vector<std::vector<double>>&matrix)
{
    std::default_random_engine random_engine(rand()%10);
    std::uniform_real_distribution<double> distrib(0, 100);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.at(0).size(); j++){
            matrix[i][j] = distrib(random_engine);
        }
    }
    printMatrix(matrix);
}

int main()
{
    int firstMatrixRows = 0, firstMatrixCols = 0;
    int secondMatrixRows = 0, secondMatrixCols = 0;
    std::cout<<"Input the rows and columns of the first matrix"<<std::endl;
    std::cin>>firstMatrixRows>>firstMatrixCols;
    std::cout<<"Input the rows and columns of the second matrix"<<std::endl;
    std::cin>>secondMatrixRows>>secondMatrixCols;
    std::vector<std::vector<double>> firstMatrix(firstMatrixRows, std::vector<double>(firstMatrixCols));
    std::vector<std::vector<double>> secondMatrix(secondMatrixRows, std::vector<double>(secondMatrixCols));
    fillMatrix(firstMatrix);
    std::cout<<std::endl;
    fillMatrix(secondMatrix);
    system("pause");
    return 0;
}
