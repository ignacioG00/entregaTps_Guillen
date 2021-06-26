#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

void controller_chooseLoadText(int flagChoose,LinkedList* list);
void controller_chooseLoadBin(int flagChoose,LinkedList* list);

int controller_getMaxId(LinkedList* pArrayListEmployee);

int controller_increaseSalary(LinkedList* pArrayListEmployee);
