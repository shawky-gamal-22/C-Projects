#include <stdio.h>
#include <stdlib.h>
#include "english_words.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>

//char arr []={} ;
int trials = 10 ;
void printStrings(char strings[], int num_strings) {
    printf("( ");
    for (int i = 0; i < num_strings; ++i) {
        printf("%c", strings[i]);
    }
    printf(") you still have %d trials\n",trials) ;
}

void initial (char arr[], int len){
    for(int i = 0 ; i < len ; i++){
        arr[i]= '_' ;
    }
}

int main()
{
    int siz = sizeof(englishWords)/sizeof(englishWords[0]) ;

    srand(time(NULL));

    int random_index = rand() % siz;

    int len = strlen(englishWords[random_index]) ;
    int still = len ;
    char arr [len];
    initial(arr,len) ;
    while(trials && still){
        printStrings(arr,len);
        printf("Try enter a character\n") ;
        char c ;
        scanf(" %c",&c) ;
        bool flag = false ;
        for(int j = 0 ; j < len ; j++){
            if(c == englishWords[random_index][j]){
                flag = true ;
                arr[j]= c ;
                still -- ;
            }
        }
        if(!flag) trials -- ;
    }

    if (!trials && !still) printf("WIIIIN\n");
    else if(!trials){
        printf("Sorry the word was %s\nMan is Executed!\n",englishWords[random_index]);

    }
    else if(!still) printf("WIIIIN\n") ;

    return 0;
}
