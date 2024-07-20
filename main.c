#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Clear the buffer function:
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Remove the new line if exist function:
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

//Clear console function: 
void clearConsole() {
    system("cls");
}

//Welcome message function: 
void printWelcomeMessage() {
    printf("*********************************************************\n");
    printf("*                                                       *\n");
    printf("*                  W E L C O M E  T O                   *\n");
    printf("*                                                       *\n");
    printf("*                  T o - C - S h o p                    *\n");
    printf("*                                                       *\n");
    printf("*        Manage your shopping list efficiently!         *\n");
    printf("*                                                       *\n");
    printf("*    +---------------------------------------------+    *\n");
    printf("*    | 1. Add list                                 |    *\n");
    printf("*    | 2. Show list                                |    *\n");
    printf("*    | 3. Remove list / Mark                       |    *\n");
    printf("*    | 4. Search list                              |    *\n");
    printf("*    | 5. Exit                                     |    *\n");
    printf("*    +---------------------------------------------+    *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");
}

typedef struct shoppingInput
{
  int numberOfItem;
  char nameOfItem[265];
  int priceOfItem;
  int totalPriceOfItem;
}Shopping;

void inputFunction (Shopping *data){
  clearConsole();
  printf("\n");
  printf("Total item: ");
  scanf("%d", &data->numberOfItem);

  if(data->numberOfItem == 0){
    return;
  }

  clearInputBuffer();
  printf("Name of item: ");
  fgets(data->nameOfItem, sizeof(data->nameOfItem), stdin);
  removeNewline(data->nameOfItem);
  printf("Input approx. Price of item: ");
  scanf("%d", &data->priceOfItem);
  printf("\n");
}

void printOutput (Shopping *data, int currentSize){
  clearConsole();
  for(int i = 0; i < currentSize; i++){
    printf("-> %d %s %d\n", data[i].numberOfItem, data[i].nameOfItem, data[i].priceOfItem);
  }
}

//Malloc function:
void memorryAllocation (Shopping **shoppingData, int currentSize){
  *shoppingData = (Shopping*)malloc(currentSize * sizeof(Shopping));
  if(*shoppingData == NULL){
    printf("Memory allocation failed\n");
        exit(1);
  }
}

//Realloc function:
void memorryReallocation (Shopping **shoppingData, int size){
  *shoppingData = (Shopping*)realloc(*shoppingData, size * sizeof(Shopping));
  if(*shoppingData == NULL){
    printf("Memory reallocation failed\n");
        exit(1);
  }
}

int  main(){

Shopping *shoppingData = NULL;
int size = 1;
int currentSize = 0;

memorryAllocation(&shoppingData, size);

while(1){
if(currentSize == size){
  size *= 2;
  memorryReallocation(&shoppingData, size);
}

inputFunction(&shoppingData[currentSize]);

if(shoppingData[currentSize].numberOfItem == 0) break;
currentSize++;
}

printOutput(shoppingData, currentSize);

free(shoppingData);
shoppingData = NULL;

return 0;
}