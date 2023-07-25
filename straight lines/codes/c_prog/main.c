#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include"lib.h"

int main() {
    int m=3,n=1;
    double **e1, **e2;
    double **solution;
    
    e1=loadtxt("e1.dat",m,n);
    e2=loadtxt("e2.dat",m,n);
    solution=lin_solv(e1,e2);
    
    print(solution,2,n);
    save(solution,2,n);
    

    return 0;
}
