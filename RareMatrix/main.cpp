/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on November 16, 2017, 8:46 AM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

typedef struct _RareMatrixElement
{
    unsigned int line;
    unsigned int column;
    int value;    
}RareMatrixElement;



int main(int argc, char** argv) 
{
    RareMatrixElement matrix[20];
    unsigned int matrixDimension = 0;
    unsigned int noOfNonZeroElements = 0;
    unsigned int idx = 0, idxCol = 0, idxRare;
    int found = 0;
    
    printf("Introduceti dimensiunea matricii ");
    scanf("%u", &matrixDimension);    
    printf("Introduceti numarul de elemente != 0 ");
    scanf("%u", &noOfNonZeroElements);
    
    for (idx = 0; idx < noOfNonZeroElements; idx++)
    {
        printf("Introduceti elementul %u \n", idx);
        printf("Linia: ");
        scanf("%u",&matrix[idx].line);
        printf("Coloana: ");
        scanf("%u", &matrix[idx].column);        
        printf("Valoarea: ");
        scanf("%d", &matrix[idx].value);        
    }
    
    for (idx = 0; idx < matrixDimension; idx++)
    {
        for(idxCol = 0; idxCol < matrixDimension; idxCol++)
        {
            found = 0;
            for (idxRare = 0; idxRare < noOfNonZeroElements; idxRare++)
            {
                if (idx == matrix[idxRare].line && idxCol == matrix[idxRare].column)
                {
                    printf("%4d", matrix[idxRare].value);
                    found = 1;
                }          
            }
            if (!found)
            {
                printf("%4d", 0);
            }
        }
        printf("\n");
    }

    return 0;
}

