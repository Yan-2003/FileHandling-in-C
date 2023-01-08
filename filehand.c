#include <stdio.h>
#include <stdlib.h>
int main(){
    int size = 0;
    int element;
    FILE * gettingTheSize = fopen("me.txt", "r");
    while(fscanf(gettingTheSize, "%d", &element) != EOF)
    {
        size++;
    } 
    fclose(gettingTheSize);
    int i = 0;
    int * array = malloc(size * sizeof(int));
    int THESIZE = (sizeof(*array) * size) / sizeof(int);

    FILE * readingTheFile = fopen("me.txt", "r");
    while(fscanf(readingTheFile, "%d", &array[i]) != EOF)
    {
        i++;
    }
    fclose(readingTheFile);
    int temp;
     
    for(int i = 0; i < THESIZE-1; i++){
        printf("sorting:");
        for(int j = 0; j < THESIZE; j++){
            if(array[j] > array[j+1] && j+1 != THESIZE){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
             printf(" %d ", array[j]); 
        }
        printf("\n");
    }
    FILE * myfile = fopen("me.txt", "w");
    for(int i = 0; i < THESIZE; i++){
        fprintf(myfile, "%d ", array[i]);
    }
    fclose(myfile);
    printf("size of the array: %d ", THESIZE);
    return 0;
}