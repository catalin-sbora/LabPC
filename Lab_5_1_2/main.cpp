/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: catalin
 *
 * Created on December 7, 2017, 8:31 AM
 */

#include <stdio.h>
#include <string.h>
#define N1 128
#define N2 255

int encode(const char* bufferToEncode, unsigned int bufferLen, int randomNumber, unsigned char* outputBuffer)
{
    int retVal = -1;
    int idx = 0;
    int encodedChar = 0;
    
    if (outputBuffer != NULL && bufferToEncode != NULL && (randomNumber >= 1 && randomNumber <= N2 - N1))
    {
        for (idx = 0; idx < bufferLen; idx++)
        {
            encodedChar = bufferToEncode[idx] + randomNumber;           
            
            encodedChar = N1 + encodedChar;            
            
            if (encodedChar > N2)
            {
                encodedChar =  encodedChar % (N2 - N1);
                encodedChar = N1 + encodedChar;                
            }       
            
            outputBuffer[idx] = (char)encodedChar;            
        }
        retVal = bufferLen;
    }
    
    return retVal;
}

int decode(const unsigned char* bufferToDecode, unsigned int bufferLen, int randomNumber, char* outputBuffer)
{
    int retVal = -1;
    int idx = 0;
    int decodedChar = 0;
    
    if (outputBuffer != NULL && bufferToDecode != NULL && (randomNumber >= 1 && randomNumber <= N2 - N1))
    {
        for (idx = 0; idx < bufferLen; idx++)
        {
            decodedChar = bufferToDecode[idx] - randomNumber;            
            decodedChar = decodedChar - 2;            
            if (decodedChar >= N1)
            {
                decodedChar = decodedChar - N1 + 2;
            }
            
            outputBuffer[idx] = (char)decodedChar;
            
        }
        retVal = bufferLen;
    }
    
    return retVal;

}

int encodeFile(const char* fileToEncode, const char* resultFile)
{
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    char dataBuffer[4096];
    unsigned char encodedBuffer[4096];
    size_t readData;
    
    int retVal = -1;
    inputFile = fopen(fileToEncode, "rb");
    if (inputFile != NULL)
    {
        outputFile = fopen(resultFile, "wb");
        if (outputFile)
        {
            readData = fread(dataBuffer, 1, 1024, inputFile);
            if (readData > 0)
            {
                encode(dataBuffer, readData, 76, encodedBuffer);
                fwrite(encodedBuffer, readData, 1, outputFile);
            }
            retVal = readData;
            fclose(outputFile);
        }
        fclose(inputFile);
    }
    
}

int decodeFile(const char* fileToDecode, const char* resultFile)
{
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    char dataBuffer[4096];
    unsigned char encodedBuffer[4096];
    size_t readData;
    
    int retVal = -1;
    inputFile = fopen(fileToDecode, "rb");
    if (inputFile != NULL)
    {
        outputFile = fopen(resultFile, "wb");
        if (outputFile)
        {
            readData = fread(dataBuffer, 1, 1024, inputFile);
            if (readData > 0)
            {
                decode((const unsigned char*)dataBuffer, readData, 76, (char*)encodedBuffer);
                fwrite(encodedBuffer, readData, 1, outputFile);
            }
            retVal = readData;
            fclose(outputFile);
        }
        fclose(inputFile);
    }
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    /*const char* toEncode = "ana are mere";
    unsigned char encoded[260] = {0};
    char decoded[260] = {0};
    int encodedLen;
    int decodedLen = 0;
    unsigned int bufLen = strlen(toEncode);
    
 
    encodedLen = encode(toEncode, bufLen, 76, encoded);
    if (encodedLen != -1)
    {
        printf("Encoded buffer with len: %d; Data: %s\n", encodedLen, encoded);
    }
    decodedLen = decode(encoded, encodedLen, 76, decoded);
    if (decodedLen != -1)
    {
        printf("Valoarea decodificata: %s \n", decoded);
    }*/
    
    int encodeResult = 0;
    char inputFile[260] = {0};
    char outputFile[260] = {0};
    
    printf("Fisierul de intrare: ");
    scanf("%s", inputFile);
    printf("Fisierul de iesire: ");
    scanf("%s", outputFile);
    
    encodeResult = encodeFile(inputFile, outputFile);
    
    decodeFile(outputFile, "/home/catalin/decoded.txt");
    printf("Encode result: %d\n", encodeResult);


    
    
    
    
    return 0;
}

