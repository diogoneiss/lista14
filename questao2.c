#include <stdio.h>


int main(){

const int tamanho = 4;
float soma = 0;

float total_notas[tamanho];

for(int i = 0; i < tamanho; i++){

    printf("\nInsira um num: ");
    scanf("%f", & total_notas[i]);

    soma += total_notas[i];

}

float media;

media = soma /  (float) tamanho;

printf("\n A media e %f", media);

return 0;

}

