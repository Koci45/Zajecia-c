#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *readFile(const char *path){

    FILE *filePointer = fopen(path, "r"); // opening file

    fseek(filePointer, 0, SEEK_END);
    long fileSize = ftell(filePointer);
    fseek(filePointer, 0, SEEK_SET); // checking the length of the file

    char *fileContent = (char *) malloc(fileSize + 1);

    size_t bytesRead = fread(fileContent, 1, fileSize, filePointer); //pushing the file content to fileContent variable
    fileContent[bytesRead] = '\0'; //marking end of file in the string

    fclose(filePointer);

    return fileContent;
}

char word_to_digit(const char* word) {
    if (strcmp(word, "one") == 0) {
        return '1';
    } else if (strcmp(word, "two") == 0) {
        return '2';
    } else if (strcmp(word, "three") == 0) {
        return '3';
    } else if (strcmp(word, "four") == 0) {
        return '4';
    } else if (strcmp(word, "five") == 0) {
        return '5';
    } else if (strcmp(word, "six") == 0) {
        return '6';
    } else if (strcmp(word, "seven") == 0) {
        return '7';
    } else if (strcmp(word, "eight") == 0) {
        return '8';
    } else if (strcmp(word, "nine") == 0) {
        return '9';
    } else if (strcmp(word, "zero") == 0) {
        return '0';
    }
}

int char_to_int(char digit) {
    // Check if the character is a digit
    if (digit >= '0' && digit <= '9') {
        return digit - '0'; // Convert char to int
    } else {
        // Return -1 for non-digit characters
        return -1;
    }
}

char findFirstDigitOrWordNumber(const char* line){

    int charPointer = 0;
    char firstDigit = '\0';
    char* firstWordNumber = NULL;
    int indexOfDigit = 0;
    int indexOfWordNumber = 0;

    //searching for first digit
    while(line[charPointer] != '\n'){

        if(isdigit(line[charPointer])){
            firstDigit = line[charPointer];
            indexOfDigit = charPointer;
            break;
        }
        charPointer ++;
    }

    if(firstDigit == '\0'){
        indexOfDigit == charPointer;//if didnt find any digit numbe set the index of digit number to the end of line 
    }

    //searching for first word number
    char *numberWords[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < 9; i++){

        char *result = strstr(line, numberWords[i]);//serching for substring

        if(result != NULL){

            int foundNumberIndex = result - line; 

            if(firstWordNumber == NULL || foundNumberIndex < indexOfWordNumber){

                firstWordNumber = numberWords[i];
                indexOfWordNumber = foundNumberIndex;
            }
        }
    }

    if(firstWordNumber == NULL){
        indexOfWordNumber = charPointer;
    }

    if(indexOfDigit < indexOfWordNumber){
        return firstDigit;
    }
    //printf("%d \n", indexOfDigit);
    return word_to_digit(firstWordNumber);
}

char findLastDigitOrWordNumber(const char* line){

    int charPointer = 0;
    char lastDigit = '\0'; // Change variable name to reflect last occurrence
    char* lastWordNumber = NULL; // Change variable name to reflect last occurrence
    int indexOfDigit = 0;
    int indexOfWordNumber = 0;

    // searching for last digit
    while(line[charPointer] != '\0'){ // Change condition to check end of string

        if(isdigit(line[charPointer])){
            lastDigit = line[charPointer];
            indexOfDigit = charPointer;
        }
        charPointer++;
    }

    // searching for last word number
    char *numberWords[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i = 0; i < 9; i++){

        char *result = strstr(line, numberWords[i]);

        if(result != NULL){

            int foundNumberIndex = result - line;

            if(lastWordNumber == NULL || foundNumberIndex > indexOfWordNumber){
                lastWordNumber = numberWords[i];
                indexOfWordNumber = foundNumberIndex;
            }
        }
    }

    if(lastWordNumber == NULL){
        indexOfWordNumber = charPointer;
    }

    if(indexOfDigit > indexOfWordNumber){
        return lastDigit;
    }
    return word_to_digit(lastWordNumber);
}

int decypherLine(const char* line){

    char firstNumber = findFirstDigitOrWordNumber(line);
    char lastNumber = findLastDigitOrWordNumber(line);

    int resultOfLine = char_to_int(firstNumber);
    resultOfLine = resultOfLine * 10;
    resultOfLine = resultOfLine + char_to_int(lastNumber);

    //printf("%d \n", resultOfLine);
    return resultOfLine;
}

/*
This method reads the char array "line by line",
then sends each line to decypherLine which decyphers it and returns the amount of energy,
and then the cypher accumulate all of the results for each line sent, and returns it
*/
int decypher(const char* cypher){

    int charPointer = -1; // this is in order to ensure that the last line is read
    int startOfLine = 0;
    int result = 0;

    
    while(cypher[charPointer] != '\0'){
        
        charPointer++;
        if(cypher[charPointer] == '\n' || cypher[charPointer] == '\0'){

            int lineLength = charPointer - startOfLine + 1;

            char* line = (char*) malloc(lineLength * sizeof(char));

            strncpy(line, &cypher[startOfLine], lineLength - 1);
            line[lineLength - 1] = '\0';

            int lineResult = decypherLine(line);
            result += lineResult;

            free(line);
            startOfLine = charPointer + 1; //moving the start of line pointer
        }
      
    }

    return result;
}

int main(){

    char *fileContent = readFile("szyfr.txt");
    int result = decypher(fileContent); 

    printf("%d", result);
    
}
