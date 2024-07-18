#include <stdio.h>
#include <stdlib.h>


extern int count;
int increment();
int  main(){

int value;
value = increment();
value = increment();
value = increment();
count+=3;
value = count;
printf("%d\n", value);

return 0;
}