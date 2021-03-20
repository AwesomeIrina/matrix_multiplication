#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <random>
#include "omp.h"

////число столбцов первой матрицы = числу строк второй матрицы
////у результирующей матрицы столько строк, сколько в первой матрице
////и столько столбцов, сколько во второй

void printMatrix(std::vector<std::vector<double>> & matrix)
{
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.at(0).size(); j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


void matrixMultiplication(std::vector<std::vector<double>> & firstMatrix, std::vector<std::vector<double>> & secondMatrix)
{
    int i = 0, j = 0, k = 0;
    int rows = firstMatrix.size(); //строки первой матрицы
    int columns = secondMatrix.at(0).size(); //столбцы второй
    int secondMatrixRows = secondMatrix.size(); //строки второй

    std::vector<std::vector<double>> result(rows, std::vector<double>(columns));
    //идём по строкам первой матрицы
    //умножаем результат на столбцы второй матрицы
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            for(k = 0; k < secondMatrixRows; k++){
                result[i][j] += firstMatrix[i][k]*secondMatrix[k][j];
            }
        }
    }
    printMatrix(result);
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
    bool isEqual = false;

    while(!isEqual){
        std::cout<<"Input the rows and columns of the first matrix"<<std::endl;
        std::cin>>firstMatrixRows>>firstMatrixCols;

        std::cout<<"Input the rows and columns of the second matrix"<<std::endl;
        std::cin>>secondMatrixRows>>secondMatrixCols;

        if(secondMatrixRows != firstMatrixCols){
            std::cout<<"Incorrect size!"<<std::endl;
        }
        else{
            isEqual = true;
        }
    }




    std::vector<std::vector<double>> firstMatrix(firstMatrixRows, std::vector<double>(firstMatrixCols));
    std::vector<std::vector<double>> secondMatrix(secondMatrixRows, std::vector<double>(secondMatrixCols));

    std::cout<<"The first matrix: "<<std::endl;
    fillMatrix(firstMatrix);
    std::cout<<std::endl;

    std::cout<<"The second matrix: "<<std::endl;
    fillMatrix(secondMatrix);
    std::cout<<std::endl;

    std::cout<<"Result of multiplication is: "<<std::endl;
    matrixMultiplication(firstMatrix, secondMatrix);

    system("pause");
    return 0;
}
