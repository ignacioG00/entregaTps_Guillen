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
Employee* employee_newParametrosTxt(char* nombreStr,char* sueldo,char* idStr,char* horasTrabajadasStr);

void employee_delete();

int employee_setId(Employee* empleado,int id);
int employee_getId(Employee* empleado,int* id);

int employee_setNombre(Employee* empleado,char* nombre);
int employee_getNombre(Employee* empleado,char* nombre);

int employee_setHorasTrabajadas(Employee* empleado,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* empleado,int* horasTrabajadas);

int employee_setSueldo(Employee* empleado,int sueldo);
int employee_getSueldo(Employee* empleado,int* sueldo);

int employee_sortSueldo(void* thisOne, void* thisTwo);
int employee_sortHoras(void* thisOne, void* thisTwo);
int employee_sortNombre(void* thisOne, void* thisTwo);

void employee_print(Employee* this);

#endif // employee_H_INCLUDED
