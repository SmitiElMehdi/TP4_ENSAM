#include <stdio.h>
#include <stdlib.h>
int diagonale(int *T,int m){
    int k = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(j!=i){
                if(*(T+i*m+j)!=0){
                    k=0;
                }
            }
        }
    }
    return k;
}
int triangulaire_sup(int *T,int m){
    int k = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < i ; j++){
            if(j!=i){
                if(*(T+i*m+j)!=0){
                    k=0;
                }
            }
        }
    }
    return k;   
}
int triangulaire_inf(int *T,int m){
    int k = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = i ; j < m ; j++){
            if(j!=i){
                if(*(T+i*m+j)!=0){
                    k=0;
                }
            }
        }
    }
    return k;   
}
int trace(int *T,int m){
    int s=0;
    for(int i = 0; i < m ;i++){
        s+=*((T+i*m)+i);
    }
    return s;
}
int **transpo(int *M,int *T,int n,int m){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j <m ;j++){
            *(T+j*n+i)= *(M+i*m+j);
        }
    }
}
int main(){
    printf("Pour tester l une des 3 fonctions appuyez sur 1, pour calculer la trace appuyez sur 2 et pour trouver la transposee appuyez sur 3.\n");
    int choix;
    while(choix!=1 && choix!=2 && choix!=3)
    {
        printf("Choisissez une option : ");
        scanf("%d",&choix);
        if(choix!=1 && choix!=2 && choix!=3){
            printf("Option non incluse veuillez reesayer\n");
        }
    } 
    switch(choix)
    {
    case 1:{
        int m;
        printf("Entrez le nombre de ligne que vous souhaitez : ");
        scanf("%d",&m);
        int *tableau[m];
        for(int i = 0; i < m ; i++){
            tableau[i] = (int *)malloc(m*sizeof(int));
        }
        for(int i =0 ; i < m ; i++){
            for(int j = 0; j < m ; j++){
                printf("Arr[%d][%d] : ",i+1,j+1);
                scanf("%d",(tableau+i*m+j));
            }
        }
        if(diagonale(tableau,m))
        {
            printf("La matrice est diagonale \n");
        }
        else
        {
            if(triangulaire_sup(tableau,m)){
                printf("La matrice est triangulaire superieure\n");
            }
            else if (triangulaire_inf(tableau,m))
            {
                printf("La matrice est triangulaire inferieure\n");
            }
            else
            {
                printf("La matrice n'est pas triangulaire ni inf ou sup");
            }
            
        }
        }
        break;
        case 2 : {
            int m;
            printf("Entrez le nombre de ligne que vous souhaitez : ");
            scanf("%d",&m);
            int *tableau[m];
            for(int i = 0; i < m ; i++){
                tableau[i] = (int *)malloc(m*sizeof(int));
            }
            for(int i =0 ; i < m ; i++){
                for(int j = 0; j < m ; j++){
                    printf("Arr[%d][%d] : ",i+1,j+1);
                    scanf("%d",(tableau+i*m+j));
                }
            }
            printf("La trace de la matrice est : %d",trace((int*)tableau,m));
            }
            break;
        case 3 : {
            int n,m;
            printf("Entrez le nombre de lignes souhaitees : ");
            scanf("%d",&n);
            printf("Entrez le nombre de colonnes souhaitees : ");
            scanf("%d",&m);
            int M[n][m];
            for (int i = 0; i < n ; i++){
                for(int j = 0; j < m ; j++){
                    printf("M[%d][%d] : ",i+1,j+1);
                    scanf("%d",&M[i][j]);
                }
            }
            int T[m][n];
            transpo((int*)M,(int*)T,n,m);
            for(int i = 0; i< m;i++){
                for(int j = 0; j < n ; j++){
                    printf("%d ",T[i][j]);
                }
                printf("\n");
            }
        }
    
    }
    
    return 0;
}
