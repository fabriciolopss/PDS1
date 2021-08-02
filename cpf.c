#include <stdio.h>


int main(){
    long int cpf;
    int fator = 1, digits[9], contador = 0, totalSoma1 = 0, dezVerificador = 0, unidVerificador = 0, 
    restoDezena = 0, restoUnid = 0, totalSoma2 = 0;
    scanf ("%ld", &cpf);
    while (cpf > 0)
    {
        digits[contador] = cpf % 10;
        cpf = cpf / 10;
        contador++;
    }
    totalSoma1 = digits[0] * 2 + digits[1] * 3 + digits[2] * 4 + digits[3] * 5 + digits[4] * 6 + digits[5] * 7 + digits [6] * 8 + digits[7] * 9 + digits[8] * 10;
    if (totalSoma1 % 11 == 1 || totalSoma1 % 11 == 0) 
    /* dezena verificador */  
    {
      dezVerificador = 0;

    }else
    {
      restoDezena = totalSoma1 % 11;
      dezVerificador = 11 - restoDezena;


    }
    totalSoma2 = dezVerificador * 2 + digits[0] * 3 + digits[1] * 4 + digits[2] * 5 + digits[3] * 6 + digits[4] * 7 + digits[5] * 8 + digits [6] * 9 + digits[7] * 10 + digits[8] * 11;
    if (totalSoma2 % 11 == 1 || totalSoma2 % 11 == 0)
    {
      unidVerificador = 0;
    }else
    {
      restoUnid = totalSoma2 % 11;
      unidVerificador = 11 - restoUnid;
    }
    printf("%d%d", dezVerificador, unidVerificador);
    
    
    
}
