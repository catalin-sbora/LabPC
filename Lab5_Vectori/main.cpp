/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on November 23, 2017, 8:17 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{

    int*    intV = NULL;
    int     nElem = 0;
    int     i = 0;
    int     suma = 0;
    int lungimeSir = 0;
    
    char    sirCaractere[100] = {0};
    char    sirCaractere1[100] = {0};
    char    sirCaractere2[200] = {0};
       
    
    printf("Numarul de elemente este: ");
    scanf("%d", &nElem);
    
    intV = (int*)malloc(sizeof(int) * (nElem));
    
    for ( i = 0; i < nElem; i++)
    {
        printf("Introduceti valoarea elem de pe poz: %d", i);
        scanf("%d", &intV[i]);
    }
    
    for (i = 0; i < nElem; i++)
    {
        suma += intV[i];
    }
    
    for (i = 0; i < nElem; i++)
    {
        printf("%4d", intV[i]);
    }
    
    printf("\nSuma este: %d\n", suma);
    
    if (intV)
    {
        free(intV);
    }
    /*
    printf("Introduceti sirul de caractere: ");
    //scanf("%s", sirCaractere);
    fgets(sirCaractere, sizeof(sirCaractere), stdin);
    lungimeSir = strlen(sirCaractere);
    if (lungimeSir > 0)
    {
        sirCaractere[lungimeSir - 1] = 0;
    }
    //gets(sirCaractere);
    printf("Sirul citit este: %s\n",sirCaractere);
    
    //lungimea sirului - strlen
    //copierea sirului - strcpy
    //concatenarea a doua siruri - strcat
    //comparatia intre doua siruri - strcmp, stricmp, strcasecmp
    //cautare substring - strstr
    printf("Caracterul de pe pozitia 5 este: %c \n", sirCaractere[10]);
   
    printf("Lungimea sirului citit este: %d\n", strlen(sirCaractere) );
    printf("Introduceti cel de-al doilea sir: ");
    fgets(sirCaractere1, sizeof(sirCaractere1), stdin);
    lungimeSir = strlen(sirCaractere1);
    if (lungimeSir > 0)
    {
        sirCaractere1[lungimeSir - 1] = 0;
    }
    
    strcpy(sirCaractere2, sirCaractere);
    printf("Sirul copiat este: %s\n", sirCaractere2);
    strcat(sirCaractere2, sirCaractere1);
    printf("Sirul concatenat este: %s\n", sirCaractere2);
    if (strcasecmp(sirCaractere, sirCaractere1) == 0)
    {
        printf("Cele doua siruri sunt egale\n");
    }
    else if (strcasecmp(sirCaractere, sirCaractere1) < 0)
    {
        printf("Sirul 1 este mai mic decat sirul 2\n");
    }
    else
    {
        printf("Sirul 2 este mai mic decat sirul 1\n");
    }
    char* found = strstr(sirCaractere, sirCaractere1);
    if (found)
    {
        printf("%s este in %s pe pozitia: %d\n", sirCaractere1, sirCaractere, (found - sirCaractere));
    }
    else
    {
        printf("%s nu este in %s\n", sirCaractere1, sirCaractere);
    }
    */
    return 0;
}

