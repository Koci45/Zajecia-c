#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int char_to_int(char digit) {
    // Check if the character is a digit
    if (digit >= '0' && digit <= '9') {
        return digit - '0'; // Convert char to int
    } else {
        // Return -1 for non-digit characters
        return -1;
    }
}

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

int CalculatePowerOfLine(const char* line){

    int charPointer = -1;
    int minGreen = 0;
    int minBlue = 0;
    int minRed = 0;
    int finalMinGreen = 0;
    int finalMinBlue = 0;
    int finalMinRed = 0;
    int gameNr = 0;
    int digitCounter = 0;
    
    while(line[charPointer] != '\0'){

        charPointer ++;
        
        if(isdigit(line[charPointer]) && digitCounter != 0){

            //reading the number, even if its more than one char
            int number = 0;
            int dummyCounter = charPointer;

            while(isdigit(line[dummyCounter])){

                number = number * 10;
                number += char_to_int(line[dummyCounter]);

                dummyCounter ++;
                charPointer ++;
            }

            //printf("%d \n", number);

            if(line[dummyCounter + 1] == 'z'){
                minGreen += number;
                //printf("z %d ", number);
            }
            if(line[dummyCounter + 1] == 'c'){
                minRed += number;
                //printf("c %d ", number);
            }
            if(line[dummyCounter + 1] == 'n'){
                minBlue += number;
                //printf("n %d ", number);
            }

        }

        if(line[charPointer] == ';' || line[charPointer] == '\0'){

            if(minBlue > finalMinBlue){
                finalMinBlue = minBlue;
            }
            if(minRed > finalMinRed){
                finalMinRed = minRed;
            }
            if(minGreen > finalMinGreen){
                finalMinGreen = minGreen;
            }

            minBlue = 0;
            minGreen = 0;
            minRed = 0;
        }

        if(isdigit(line[charPointer]) && digitCounter == 0){

            gameNr = char_to_int(line[charPointer]);
        
            digitCounter++;
        }

    }

    printf("Gra nr %d, Min zielonych: %d  Min niebieskich: %d  Min czerwonych: %d \n", gameNr, finalMinGreen, finalMinBlue, finalMinRed);
    return finalMinBlue * finalMinGreen * finalMinRed;
}

int CalculatePower(const char* gry){

    int charPointer = -1; // this is in order to ensure that the last line is read
    int startOfLine = 0;
    int result = 0;

    
    while(gry[charPointer] != '\0'){
        
        charPointer++;
        if(gry[charPointer] == '\n' || gry[charPointer] == '\0'){

            int lineLength = charPointer - startOfLine + 1;

            char* line = (char*) malloc(lineLength * sizeof(char));

            strncpy(line, &gry[startOfLine], lineLength - 1);
            line[lineLength - 1] = '\0';

            int lineResult = CalculatePowerOfLine(line);
            //printf("%d \n", lineResult);
            result += lineResult;

            free(line);
            startOfLine = charPointer + 1; //moving the start of line pointer
        }
      
    }

    return result;
}


int main() {
    
    char *fileContent = readFile("gry.txt");
    //printf("%s", fileContent);
    int result = CalculatePower(fileContent);

    printf("Koncowa moc wynosi: %d", result);
    return 0;
}
