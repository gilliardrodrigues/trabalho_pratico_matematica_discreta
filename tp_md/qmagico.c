#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int get_numMagico(int n){ //Função que calcula o número mágico;
    return((n*(pow(n, 2)+1))/2);
}
void exibir_num_magico(int n){
    printf("n = %d, soma = %d\n", n, get_numMagico(n)); //Exibe o "n" e a soma(número mágico);
}
void exibir_matriz(int **mat, int n){ //Exibe a matriz na tela;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("[ %d ]", mat[i][j]);
        }
        printf("\n");
    }
}
void liberar_matriz(int **mat, int n){ //Libera a memória alocada para a matriz;
    for(int i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
}

int main(){
    int **matriz, n;
    while(1){ //Garante que o programa só prossiga após o usuário digitar um valor válido;
        printf("Insira o valor de n para gerar um quadrado mágico(entre 3 e 6): ");
        scanf("%d", &n);
        if(n >= 3 && n <= 6){
            break;
        }
    }
    matriz = (int **) malloc(n * sizeof(int *)); //Alocando memória dinamicamente para as linhas;
        for(int i = 0; i < n; i++){ 
            matriz[i] = (int *) malloc(n * sizeof(int)); //Alocando memória dinamicamente para as colunas;
        }
    
    switch (n){
    case 3: { //Caso em que o usuário quer um quadrado mágico de lado 3;
        for(int i = 0; i < 3; i++){ //Criando uma matriz 3x3 de zeros;
            for(int j = 0; j < 3; j++){
                matriz[i][j] = 0;
            }
        }
        int i = 0, j = 1; //Esses valores de j se referem a posição superior do meio na matriz;
        for(int num = 0; num < 9; num++){
            if(matriz[i][j] == 0){
                matriz[i][j] = num + 1;
                i--;
                j++;
                if(i < 0){
                    i += 3;
                }
                if(j >= 3){
                    j -= 3;
                }
            }
            else{
                i += 2;
                j--;
                if(i >= 3){
                    i -= 3;
                }
                if(j < 0){
                    j += 3;
                }
                matriz[i][j] = num + 1;
                i--;
                j++;
                if(i < 0){
                    i += 3;
                }
                if(j >= 3){
                    j -= 3;
                }
            }
        }
        exibir_num_magico(3);
        exibir_matriz(matriz, 3);
        liberar_matriz(matriz, 3);
    } break;
    
    case 4: {
        int elemento = 1;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                matriz[i][j] = elemento; //Atribuindo o valor de elemento para a posição [i][j] da matriz.
                elemento++;
            }
        }
        //Invertendo os elementos das diagonais externas:
        int auxiliar;
        auxiliar = matriz[0][0];
        matriz[0][0] = matriz[3][3];
        matriz[3][3] = auxiliar;

        auxiliar = matriz[0][3];
        matriz[0][3] = matriz[3][0];
        matriz[3][0] = auxiliar;
        //Invertendo os elementos das diagonais internas:
        auxiliar = matriz[1][1];
        matriz[1][1] = matriz[2][2];
        matriz[2][2] = auxiliar;

        auxiliar = matriz[1][2];
        matriz[1][2] = matriz[2][1];
        matriz[2][1] = auxiliar;
        //Exibindo na tela:
        exibir_num_magico(4);
        exibir_matriz(matriz, 4);
        liberar_matriz(matriz, 4);
    } break;
    
    case 5: {
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                matriz[i][j] = 0;
            }
        }
        int i = 0, j = 2;
        for(int num = 0; num < 25; num++){
            if(matriz[i][j] == 0){
                matriz[i][j] = num + 1;
                i--;
                j++;
                if(i < 0){
                    i += 5;
                }
                if(j >= 5){
                    j -= 5;
                }
            }
            else{
                i += 2;
                j--;
                if(i >= 5){
                    i -= 5;
                }
                if(j < 0){
                    j += 5;
                }
                matriz[i][j] = num + 1;
                i--;
                j++;
                if(i < 0){
                    i += 5;
                }
                if(j >= 5){
                    j -= 5;
                }
            }
        }
        exibir_num_magico(5);
        exibir_matriz(matriz, 5);
        liberar_matriz(matriz, 5);
    } break;

    case 6: {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                matriz[i][j] = 0;
            }
        }
        int i = 0, j = 1;
        for(int num = 0; num < 9; num++){
            if(matriz[i][j] == 0){
                matriz[i][j] = num + 1;
                i--;
                j++;
                if(i < 0){
                    i += 3;
                }
                if(j >= 3){
                    j -= 3;
                }
            }
            else{
                i += 2;
                j--;
                if(i >= 3){
                    i -= 3;
                }
                if(j < 0){
                    j += 3;
                }
                matriz[i][j] = num + 1;
                i--;
                j++;
                if(i < 0){
                    i += 3;
                }
                if(j >= 3){
                    j -= 3;
                }
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                matriz[i+3][j+3] = matriz[i][j] + 9;
                matriz[i][j+3] = matriz[i][j] + 18;
                matriz[i+3][j] = matriz[i][j] + 27;
            }
        }

        int auxiliar = matriz[0][0];
        matriz[0][0] = matriz[3][0];
        matriz[3][0] = auxiliar;

        auxiliar = matriz[1][1];
        matriz[1][1] = matriz[4][1];
        matriz[4][1] = auxiliar;

        auxiliar = matriz[2][0];
        matriz[2][0] = matriz[5][0];
        matriz[5][0] = auxiliar;
        exibir_num_magico(6);
        exibir_matriz(matriz, 6);
        liberar_matriz(matriz, 6);
    } break;
    
    }
    
}