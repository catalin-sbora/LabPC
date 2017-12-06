/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <math.h>
#include <string.h>

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on December 6, 2017, 9:09 AM
 */
#include <stdio.h>

typedef double (*CustomFunction)(char** arguments, int nArgs);
struct FMat
{
    char name[1024];
    CustomFunction functionToExecute;
    int nArg;    
};

double CustomPow(char** args, int nArgs)
{
    if (nArgs != 2)
    {
        return -1;
    }
    double number = atof(args[0]);
    double power = atof(args[1]);
    
    return pow(number, power);
}

double CustomSqrt(char** args, int nArgs)
{
    if (nArgs != 1)
    {
        return -1;
    }
    double number = atof(args[0]);
    return sqrt(number);
}
/*
 * 
 */
int main(int argc, char** argv) 
{

    char currentName[256] = {0};
    char* arguments[100] = {0};
    int processed = 0;
    struct FMat functionsList[2];
    int i = 0;
    int j = 0;
    strcpy(functionsList[0].name, "ridicare_la_putere");
    functionsList[0].nArg = 2;
    functionsList[0].functionToExecute = CustomPow;
    
    strcpy(functionsList[1].name, "radical");
    functionsList[1].nArg = 1;
    functionsList[1].functionToExecute = CustomSqrt;
    
    
    printf("Functia care trebuie executata: ");
    scanf("%s", currentName);
    
    for (i = 0; i < sizeof(functionsList)/sizeof(struct FMat); i++)
    {
        if (strcasecmp(functionsList[i].name, currentName) == 0)
        {
            for (j  = 0; j < functionsList[i].nArg; j++)
            {
                printf("Arg. %d", j);
                arguments[j] = (char*)malloc(256);
                scanf("%s", arguments[j]);
            }
            
            double result = functionsList[i].functionToExecute(arguments, functionsList[i].nArg);
            printf("Rezultatul este: %lf\n", result);
            processed = 1;
        }
    }
    
    if (processed == 0)
    {
        printf("Functia nu este recunoscuta.\n");
    }
    return 0;
}

