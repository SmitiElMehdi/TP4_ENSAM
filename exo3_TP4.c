#include <stdio.h>
#include <stdlib.h>

int ver_ligne(int G[9][9],int i){
    int k = 1;
    for(int j = 0 ; j < 8; j++){
        for(int l = j+1 ; l < 9 ; l++){
            if(G[i][l]==G[i][j]){
                k = 0;
            }
        }
    }
    return k;
}

int ver_col(int G[9][9],int j){
    int k = 1;
    for(int i = 0 ; i < 8 ; i++){
        for(int l = i+1; l < 9 ; l++){
            if(G[i][j]==G[l][j]){
                k = 0;
            }
        }
    }
    return k;
}

int ver_reg(int G[9][9],int i, int j){
    int k = 1;
    for(int m = 0 ; m <3;m++){
        for(int n = 0 ; n < 3; n++){
            for(int a=m ; a < 3; a++){
                for(int b=n ; b < 3 ; b++){
                    if((G[m][n]==G[a][b])&&(m+n!=a+b)){
                        k = 0;
                    }
                }
            }

        }
    }
    return k;
}

int ver_gri(int G[9][9]){
    int k1 = 1;
    for(int i = 0; i < 9; i++){
        if(!ver_ligne(G,i)){
            k1=0;
        }
    }
    int k2 = 1;
    for(int i = 0; i < 9; i++){
        if(!ver_col(G,i)){
            k2=0;
        }
    }
    int k3 = 1;
    for(int i = 0; i < 9 ; i+=3){
        for(int j = 0; j < 9 ; j+=3){
            if(!ver_reg(G,i,j)){
                k3 = 0;
            }
        }
    }
    if(k1+k2+k3==3){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int G[9][9]={
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
        };
    if(ver_gri(G)){
        printf("La grille est complete\n");
    }
    else{
        printf("La grille n'est pas complete");
    }
    return 0;
}