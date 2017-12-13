/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on December 13, 2017, 9:14 AM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _ComplexNumber
{
    double real;
    double imagine;
    
}ComplexNumber;


ComplexNumber Add(ComplexNumber firstNumber, ComplexNumber secondNumber)
{
    ComplexNumber retVal;
    
    retVal.imagine = firstNumber.imagine + secondNumber.imagine;
    retVal.real = firstNumber.real + secondNumber.real;
    
    return retVal;
}

ComplexNumber Substract(ComplexNumber firstNumber, ComplexNumber secondNumber)
{
    ComplexNumber retVal;
    retVal.imagine = firstNumber.imagine - secondNumber.imagine;
    retVal.real = firstNumber.real - secondNumber.real;
   
    return retVal;
}

ComplexNumber Multiply(ComplexNumber firstNumber, ComplexNumber secondNumber)
{
    ComplexNumber retVal;
    retVal.real = firstNumber.real*secondNumber.real - firstNumber.imagine * secondNumber.imagine;
    retVal.imagine = firstNumber.real * secondNumber.imagine + firstNumber.imagine*secondNumber.real;
    return retVal;
}

ComplexNumber ReadComplexNumber()
{
    ComplexNumber retVal;
    printf("Introduceti numarul complex \n");
    printf("RE: ");
    scanf("%lf", &retVal.real);
    printf("IM: ");
    scanf("%lf", &retVal.imagine);
    
    return retVal;
}

void DisplayComplexNumber(ComplexNumber number)
{
    printf("%4.2lf + %4.2lf*i\n", number.real, number.imagine);
}

void DoAdd()
{
    
   ComplexNumber first = ReadComplexNumber();
   ComplexNumber second = ReadComplexNumber();
   ComplexNumber result = Add(first, second);
   DisplayComplexNumber(result);
   
}

void DisplayMainMenu()
{
    printf("*************** OPERATII CU NUMERE COMPLEXE **********************\n");
    printf("1) Adunare\n");
    printf("2) Scadere\n");
    printf("3) Inmultire\n");
    printf("0) Inchide aplicatie\n");
    printf("\nOptiunea: ");
}

int ReadOption(int startValidOption, int endValidOption)
{
    int retOption = -1;
    int validOption = 0;
    do
    {
        scanf("%d", &retOption);
        if (retOption >=  startValidOption && retOption <= endValidOption)
        {
            validOption = 1;            
        }
        else
        {
            printf("Optiunea introdusa nu este valida. Introduceti o valoare intre: %d si %d\n", 
                    startValidOption, endValidOption);
        }
    }while (!validOption);
}

void DoMainMenu()
{
    int currentOption = -1;
    int continueLoop = 1;
    do
    {
        system("clear");
        DisplayMainMenu();
        currentOption = ReadOption(0, 3);

        switch(currentOption)
        {
            case 0:
                continueLoop = 0;
               break;
               
            case 1:
                printf("Adunare \n");
                DoAdd();
                getchar();
                getchar();
                break;
                
            case 2:
                printf("Scadere");
                getchar();
                getchar();
                break;
                
            case 3:
                printf("inmultire");
                getchar();                
                getchar();
                break;
                
            default:
                continueLoop = 0;
                break;
        }
    }
    while(continueLoop);
}

int main(int argc, char** argv) 
{
    DoMainMenu();
}

