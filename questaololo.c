#include <stdio.h>
#include <stdlib.h>

//Assinaturas das Funcoes:
void ler_notas();
float calcular_media();
float calcular_acima_media(float media);
void escrever_resultados(float media, float acima_media);

int main() {
    float media;
    float acima_media;

    ler_notas();

    media = calcular_media();

    acima_media = calcular_acima_media(media); //Argumento: media das notas

    escrever_resultados(media, acima_media); //Argumentos: media das notas, notas acima da media

    return 0;
} //Fim: main()

void ler_notas() {
    //Ler as notas
    float nota;
    const float flag = -1;

    FILE *arq = fopen("Notas.txt", "w");

    printf("Digite uma nota ou [-1] para sair: ");
    scanf("%f", &nota);

    while (nota != flag) {
        fprintf(arq, "%f\n", nota);

        printf("Digite uma nota ou [-1] para sair: ");
        scanf("%f", &nota);
    }

    fclose(arq);
} //Fim: ler_notas()

float calcular_media() {
    //Calcular a media das notas
    float nota;
    float total_notas = 0;
    float total_alunos = 0;
    float media;

    FILE *arq = fopen("Notas.txt", "r");

    fscanf(arq, "%f", &nota);

    while (!feof(arq)) {
        total_notas += nota;
        total_alunos++;

        fscanf(arq, "%f", &nota);
    }

    fclose(arq);

    media = total_notas/total_alunos;

    return media; //Valor retornado: media das notas
} //Fim: calcular_media()

float calcular_acima_media(float media) {
    //Calcular as notas acima da media
    float nota;
    float acima_media = 0;

    FILE *arq = fopen("Notas.txt", "r");

    fscanf(arq, "%f", &nota);

    while (!feof(arq)) {
        if (nota > media) acima_media++;

        fscanf(arq, "%f", &nota);
    }

    fclose(arq);

    return acima_media; //Valor retornado: notas acima da media
} //Fim: calcular_acima_media()

void escrever_resultados(float media, float acima_media) {
    //Escrever os resultados
    printf("Media = %.2f\n", media);
    printf("Alunos Acima da Media = %.2f\n", acima_media);
} //Fim: escrever_resultados()