#include <stdio.h>


float entrada_array(int tamanho);
float media_array(float *ptr, int tamanho);
float acima_media(float *ptr, int tamanho, float media);

int main(){


int tamanho = 3;
int maioresQueAMedia;

float media;

float *arrayPtr;

*arrayPtr = entrada_array(tamanho);

media = media_array(arrayPtr, tamanho);

maioresQueAMedia = acima_media(arrayPtr, tamanho, media);

printf("\nA media do array e %f", media);
printf("\n %d alunos ficaram acima da media", maioresQueAMedia);




return 0;

}

float entrada_array(int tamanho){

    float array_numeros[tamanho];

    for(int i = 0; i < tamanho; i++){

        printf("\nInsira um num: ");
        scanf("%f", &array_numeros[i]);


}

return array_numeros[tamanho];

}

float media_array(float *ptr, int tamanho){

float array[tamanho];

array[tamanho] = * ptr;

    float soma = 0;

        for(int c =0; c < tamanho; c++){

        soma += array[c];


        }


return  soma /((float) tamanho);

}

float acima_media(float *ptr, int tamanho, float media){

float array[tamanho];

array[tamanho] = *ptr;

  float maior_media = 0;

        for(int c =0; c < tamanho; c++){
            
            if (array[c] > media)
                maior_media++;


        }

return maior_media;
}
