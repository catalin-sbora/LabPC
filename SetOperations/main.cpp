/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on November 29, 2017, 9:11 AM
 */
#include <stdio.h>
#include <string.h>
typedef struct _StaticSet
{
    unsigned int size;
    int elements[100];
    
}StaticSet;


void ReadStaticSet(StaticSet* setToRead)
{
    unsigned int i = 0;
    if (setToRead)
    {
        printf("Introduceti numarul de elemente din multime: ");
        scanf("%u",&(setToRead->size));
        
        for(i = 0; i < setToRead->size; i++)
        {
            printf("Introduceti elementul %u: ", i);
            scanf("%d",&(setToRead->elements[i]));
        }
    }
    else
    {
        printf("Variabila pentru citirea multimii nu este specificata\n");
    }    
}

void DisplayStaticSet(const StaticSet* setToDisplay)
{
    unsigned int i = 0;
    if (setToDisplay)
    {
        if (setToDisplay->size == 0)
        {
            printf("Multimea este vida\n");
        }
        else
        {
            printf("Numarul de elemente din multime este: %u\n", setToDisplay->size);
            for(i = 0; i < setToDisplay->size; i++)
            {
                printf("%4d ", setToDisplay->elements[i]);            
            }
            printf("\n");
        }
    }
    else
    {
        printf("Variabila pentru afisarea multimii nu este specificata\n");
    }    
}

void Intersect(const StaticSet* firstSet, const StaticSet* secondSet, StaticSet* result)
{
    unsigned int i = 0;
    unsigned int j = 0;
    if (firstSet && secondSet && result)
    {
        result->size = 0;
        for ( i =0; i < firstSet->size; i++)
        {
            for (j = 0; j < secondSet->size;j++)
            {
                if (firstSet->elements[i] == secondSet->elements[j])
                {
                    result->elements[result->size++] = firstSet->elements[i];
                }
            }
        }
    
    }
    else
    {
        printf("Cel putin una dintre multimi este invalida\n");
    }
}

void Reunion(StaticSet* firstSet, StaticSet* secondSet, StaticSet* result)
{
    unsigned int i, j;
    int elementFound = 0;
    
    if (firstSet && secondSet && result)
    {
        result->size = 0;
        if (firstSet->size > 0)
        {            
            memcpy(result->elements, firstSet->elements, firstSet->size*sizeof(int));
            result->size = firstSet->size;
        }
        for (i = 0; i < secondSet->size; i++)
        {
            j = 0;
            elementFound = 0;
            while (j < result->size)
            {
                if (secondSet->elements[i] == result->elements[j])
                {
                    elementFound = 1;
                }
                j++;
            }
            
            if (elementFound == 0)
            {
                result->elements[result->size++] = secondSet->elements[i];
            }
        }
        
    }
    else
    {
        printf("Cel putin una dintre multimi este invalida.\n");
    }
}

int main(int argc, char** argv) 
{
    StaticSet firstSet;
    StaticSet secondSet;
    StaticSet intersection;
    StaticSet reunion;
    
    ReadStaticSet(&firstSet);
    ReadStaticSet(&secondSet);
    
    printf("**************** AFISARE MULTIMI ***********************\n");
    printf("Prima multime: \n");
    DisplayStaticSet(&firstSet);
    
    printf("A doua multime: \n");
    DisplayStaticSet(&secondSet);

    printf("Intersectia multimilor este: \n");
    Intersect(&firstSet, &secondSet, &intersection);
    DisplayStaticSet(&intersection);
    
    printf("Reuniunea elementelor este: \n");
    Reunion(&firstSet, &secondSet, &reunion);
    DisplayStaticSet(&reunion);
    
    return 0;
}

