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

Shopping inputFunction (){
  int mainMenu;
  Shopping data;
  printf("\n");
  printf("Total item: ");
  scanf("%d", &data.numberOfItem);
  clearInputBuffer();
  printf("Name of item: ");
  fgets(data.nameOfItem, sizeof(data.nameOfItem), stdin);
  removeNewline(data.nameOfItem);
  printf("Input approx. Price of item: ");
  scanf("%d", &data.priceOfItem);
  printf("\\n");
  printf("Your list has been added! Press 0 to Menu...");
  scanf("%d", &mainMenu);
  return data;
}

void printOutput (Shopping data){
  clearConsole();
  printf("%d %s %d", data.numberOfItem, data.nameOfItem, data.priceOfItem);
}




int  main(){
//Variable:
int optionNumber;
Shopping datas;

do{
clearConsole();
printWelcomeMessage();
printf("Enter your option: ");
scanf("%d", &optionNumber);
clearConsole();

  switch(optionNumber){
    case 1: 
    datas = inputFunction();
    break; 

    case 2: 
    printOutput(datas);

  }
}while (optionNumber != 0);

return 0;
}