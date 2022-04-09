#include <stdio.h>
#include <windows.h>

void meow(int n);

int main(void){

    meow(5);
}

void meow(int n){
    
    for(int i = 0; i < n; i++){
    printf("meow\n");
    Sleep(1000);
    }
}