#include <stdio.h>
#include <stdlib.h>
int ver_ligne(int m,int n,int **T,int i){
    int z = 0;
    for(int j = 0 ; j < n; j++){
        if(T[i][j]>z){
            z = T[i][j];
        }
    }
    for(int j = 0; j < n ; j++){
        if(z==T[i][j]){
        int *Test_unit;
        Test_unit = malloc(n*sizeof(int));
        for(int k =0 ; k < n ; k++){
            Test_unit[k]=T[k][j];
            }
        if(ver_col(n,Test_unit,m,i)){
            printf("point col : %d de position (%d,%d)\n",T[i][j],i,j);
            }
            free(Test_unit);
        }
        
    }
}
    
int ver_col(int n,int *T,int m,int pos){
    int k = 1;
    for(int i = 0 ; i < m ;i++){
        if(T[i]<T[pos]){
            k = 0;
            break;
        }
    }
    return k;
}
int main(){
    int m,n;
    printf("Entrez le nombre de lignes de votre matrice :");
    scanf("%d",&m);
    printf("Entrez le nombre de colonnes de votre matrice :");
    scanf("%d",&n);
    int **matrice;
    matrice = malloc(m*sizeof(int));
    for(int i = 0 ; i < m ; i++){
        matrice[i] = malloc(n*sizeof(int));
    }
    printf("Entrez les elements de votre matrice : \n");
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n ; j++){
            printf("matrice[%d][%d] : ",i,j);
            scanf("%d",&matrice[i][j]);
        }
    }
    for(int i = 0; i < m ; i++){
        ver_ligne(m,n,matrice,i);
    }
    free(matrice);
    return 0;
}
