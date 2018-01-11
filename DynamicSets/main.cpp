/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on January 11, 2018, 8:31 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _IntSet
{
    unsigned int noElements;
    int* elements;
}IntSet;

void AllocateElements(IntSet* set)
{
    if (set->noElements > 0)
    {
        if (set->elements == NULL)
        {
            set->elements = (int*)malloc(set->noElements * sizeof(int));
        }
        else
        {
            set->elements = (int*)realloc(set->elements, set->noElements* sizeof(int));
        }
    }
}

void FreeElements(IntSet* set)
{
    if (set->elements)
    {
        free(set->elements);
        set->elements = NULL;
    }
}

void ReadIntSet(IntSet* set)
{
    unsigned int i = 0;
    printf("Introduceti numarul de elemente: ");
    scanf("%u", &set->noElements);
    AllocateElements(set);
    for (i = 0; i < set->noElements; i++)
    {
        printf("Elementul %u: ", i);
        scanf("%d",&set->elements[i]);
    }
    
}

void PrintIntSet(IntSet set)
{
    unsigned int i = 0;
    printf("Multimea are %u elemente\n", set.noElements);
    printf("------------------------------------------------------------\n");
    for (i = 0; i < set.noElements; i++)
    {
        printf("%4d", set.elements[i]);
    }
    printf("\n-------------------------------------------------------------\n");
}

int IsIntInSet(IntSet setToSearch, int searchedNumber)
{
    unsigned int i = 0;
    int found = 0;
    
    for ( i = 0; i < setToSearch.noElements; i++)
    {
        if (setToSearch.elements[i] == searchedNumber)
        {
            found = 1;
            break;
        }
    }
    
    return found;
}

IntSet Reunion(IntSet firstSet, IntSet secondSet)
{
    IntSet retSet = {0};
    unsigned int i = 0;
    unsigned int crtIdx = 0;
    retSet.noElements = firstSet.noElements;
    
    for ( i = 0; i < secondSet.noElements; i++)
    {
        if (!IsIntInSet(firstSet, secondSet.elements[i]))
            retSet.noElements++;
    }
    
    AllocateElements(&retSet);
    
    memcpy(retSet.elements, firstSet.elements, firstSet.noElements * sizeof(int));
    crtIdx = firstSet.noElements;
    
    for ( i = 0; i < secondSet.noElements; i++)
    {
        if (!IsIntInSet(retSet, secondSet.elements[i]))
        {
            retSet.elements[crtIdx] = secondSet.elements[i];
            crtIdx++;
        }
    }    
    
    return retSet;
}

int main(int argc, char** argv) 
{
    IntSet setA = {0};
    IntSet setB = {0};
    IntSet setR = {0};
    
    ReadIntSet(&setA);
    ReadIntSet(&setB);
    
    PrintIntSet(setA);
    PrintIntSet(setB);
    
    setR = Reunion(setA, setB);
    
    PrintIntSet(setR);
    
    FreeElements(&setA);
    FreeElements(&setB);
    FreeElements(&setR);
    return 0;
}

