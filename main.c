#include <stdio.h>
#include "lr.h"

int main(){
    int numberOfLaba;
    scanf("%d", &numberOfLaba);
    switch(numberOfLaba){
    case 1: return laba1();
    case 2: return laba2();
    case 3: return laba3();
    case 4: return laba4();
    case 5: return laba5();
    case 6: return laba6();
    case 7: return laba7();
    }
    return 0;
}
