typedef struct
{
    double real;
    double image;
}Cplex;
void readcomplex(Cplex &a,Cplex &b);
Cplex complexOperation(Cplex &a,Cplex &b,char c);
void printfComplex(Cplex results[]);

