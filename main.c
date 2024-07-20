#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Clear the buffer function:
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Remove the new line if exist function:
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

//Clear console function: 
void clear_console() {
    system("cls");
}

typedef struct shoppingInput
{
  int numberOfItem;
  char nameOfItem[265];
  int priceOfItem;
  int totalPriceOfItem;
}Shopping;

Shopping inputFunction (){
  Shopping data;
  printf("Total item: ");
  scanf("%d", &data.numberOfItem);
  clearInputBuffer();
  printf("Name of item: ");
  fgets(data.nameOfItem, sizeof(data.nameOfItem), stdin);
  remove_newline(data.nameOfItem);
  printf("Input approx. Price of item: ");
  scanf("%d", &data.priceOfItem);
  return data;
}

void printOutput (Shopping data){
  clear_console();
  printf("%d %s %d", data.numberOfItem, data.nameOfItem, data.priceOfItem);
}

int  main(){
Shopping datas;
datas = inputFunction();
printOutput(datas);
return 0;
}