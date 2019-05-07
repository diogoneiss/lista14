#include <stdio.h>

void verificacao_existencia();

void inserir_no_arquivo();

float calcular_media();

int acima_da_media(float media);

void mostrar_respostas(float media, int acima_media);


int main() {

    int acima_media = 0;


    float media = 0.0;


    verificacao_existencia();

    inserir_no_arquivo();

    media = calcular_media();


    acima_media = acima_da_media(media);

    
    mostrar_respostas(media, acima_media);

    return 0;

}


void inserir_no_arquivo() {

    FILE *arq = fopen("leitura.dat", "w");

    const int flag = -1;

    float entrada;

    printf("\nInsira a nota a ser inserida, ou algum numero menor de zero para sair: ");

    scanf("%f", &entrada);


    while (entrada != -1) {

        fprintf(arq, "%.1f\n", entrada);

        printf("\nInsira a nota a ser inserida, e algum num menor de zero para sair: ");

        scanf("%f", &entrada);

    }
    

    fclose(arq);


}

void verificacao_existencia() {

    FILE *arq = fopen("leitura.dat", "w");

    
    fclose(arq);
}

float calcular_media() {

    FILE *arq = fopen("leitura.dat", "r");

    float media;

    float total = 0;
    float contador = 0;

    float entrada =0;

    fscanf(arq, "%f", &entrada);

    total += entrada;
    contador++;

    while (!feof(arq)) {

        fscanf(arq, "%f", &entrada);

        total += entrada;
        
        contador++;
    }

    printf("\n\tO contador e total sao %.2f e %.2f\n", contador, total);

    media = total / contador;

    
    fclose(arq);


    return media;

}

int acima_da_media(float media) {

    float entrada = 0;
    int acima_media = 0;

    FILE *arq = fopen("leitura.dat", "r");

    fscanf(arq, "%f", &entrada);

   
    while (!feof(arq)) {

        if (entrada > media)
            acima_media++;



        fscanf(arq, "%f", &entrada);

        
    }
    
    fclose(arq);

    return acima_media;
}

void mostrar_respostas(float media, int acima_media){

printf("\nA nota media da turma e %f", media);

printf("\n%d alunos ficaram acima da media", acima_media);

}
