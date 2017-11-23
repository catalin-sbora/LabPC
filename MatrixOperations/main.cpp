/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on November 16, 2017, 9:19 AM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

//adunare
//scadere
//inmultire

void ReadMatrix(int M[10][10], unsigned int* dimension)
{
    printf("Introduceti dimensiune matrice");
    scanf("%u", dimension);
    
    unsigned int iL = 0, iC = 0;
    for (iL = 0; iL < *dimension; iL++)
    {
        for (iC = 0; iC < *dimension; iC++)
        {
            printf("Introduceti elementul %4u %4u: ", iL, iC);
            scanf("%d", &M[iL][iC]);
        }        
    }
}

void DisplayMatrix(int M[10][10], unsigned int dimension)
{
    unsigned int iL = 0, iC = 0;
    for (iL = 0; iL < dimension; iL++)
    {
        for (iC = 0; iC < dimension; iC++)
        {
            printf("%4d", M[iL][iC]);
        }
        printf("\n");
    }
}

void AddMatrix(int A[10][10], int B[10][10], unsigned int dimension, int R[10][10])
{
    unsigned int iL = 0, iC = 0;
    for (iL = 0; iL < dimension; iL++)
    {
        for (iC = 0; iC < dimension; iC++)
        {
            R[iL][iC] = A[iL][iC] + B[iL][iC];
        }
    }
}



/*
 * 
 */
int main(int argc, char** argv) 
{
    int M1[10][10], M2[10][10], M3[10][10];
    unsigned int d1, d2, d3;
    ReadMatrix(M1,&d1);    
    ReadMatrix(M2, &d2);
    AddMatrix(M1, M2, d1, M3);
    
    DisplayMatrix(M1, d1);
    DisplayMatrix(M2, d2);    
    DisplayMatrix(M3, d1);

    return 0;
}

