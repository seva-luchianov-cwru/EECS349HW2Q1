#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *searchString = "I want to learn PE file format!";
	int foundString = 0;
	
	int bufferSize = 256;
	char currLine[bufferSize];
	
	FILE *pe1;
	
	pe1 = fopen("/PE1.txt", "a+");
	
	while (fgets(currLine, bufferSize, pe1) != NULL) {
        printf("%s\n", currLine);
        currLine[strcspn(currLine, "\n")] = 0;
        if (strstr(currLine, searchString)) {
        	printf("Found match!\n");
            foundString = 1;
            break;
        }
    }
	
	if (foundString == 0) {
        printf("No match, write to file\n");
		fputs(searchString, pe1);
	}
	
	fclose(pe1);
	
	printf("Press ENTER key to Continue\n");  
	getchar();
	
	return 0;
}
