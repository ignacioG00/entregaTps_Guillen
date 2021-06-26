#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 128

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_sortSueldo(void* thisOne, void* thisTwo);
int employee_sortHoras(void* thisOne, void* thisTwo);
int employee_sortNombre(void* thisOne, void* thisTwo);
int employee_sortId(void* thisOne, void* thisTwo);

void employee_print(Employee* this);

//EXTRA tp4

int employee_increaseSalary(void *empleadoRecibido);

#endif // employee_H_INCLUDED
