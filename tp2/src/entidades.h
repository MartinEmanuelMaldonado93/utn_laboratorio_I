#define len_text 51
struct
{
    int id_emp;
    int sector;
    char name[len_text];
    char lastName[len_text];
    float salary;
    int isEmpty;

}typedef worker;

int init_employe(worker* employe, int lenght);
void hardcode_employee(worker* employee,int lenght,int* id_emp);
int findEmptySpace_employe(worker* employee, int lenght,int* empty_position);
void show_employee(worker* employee,int position);
void print_signboard();
int add_employee(worker* employee,int lenght,int* id_employee);
int show_employees(worker* employee,int lenght);
int findEmployeeById(worker* employee,int lenght,int id_finded,int* position);
int modify_employee(worker* employee,int lenght);
int delete_employee(worker* employee,int lenght);
int order_employee_alphabetic(worker* employee,int lenght);
int promedy_salary(worker* employee,int lenght);
