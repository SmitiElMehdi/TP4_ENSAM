#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void p_tab(int n,int T[n][n]){
    int count = 1;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            T[i][j]=count++;
        }
    }
}
void d_tab(int n,int T[n][n]){
    int count = 1;
    for(int i = 0 ; i < n ; i++){
        int k = pow(-1,i);
        for(int j = ((n-1)*(i%2)) ; j != n*((i+1)%2)-(i%2); j+=k){
            T[i][j]=count++;
        }
    }
}

void t_tab(int n,int T[n][n]){ //Aktar tableau m3nkch
    int count = 1;
    int k = 1;
    int v = 1;
    int i = 0; 
    int j = 0;
    T[i][j]=count++;
    for(int o = 0 ; o <((n*n)/2)-1 ;  o++ ){
        if((i==0 || i==n-1 || j==0 || j==n-1)&&v!=0){
            i+=k%2;
            j+=(k+1)%2;
            k++;
            v=0;
        }
        else{
            i+=pow(-1,k+1);
            j+=pow(-1,k);
            v=1;
        }
        T[i][j]=count++;
    }
    for(int o = 0 ; o < (n*n)/2 + n%2;o++ ){
        if((i==0 || i==n-1 || j==0 || j==n-1)&&v!=0){
            i+=(k+1)%2;
            j+=k%2;
            k++;
            v=0;
        }
        else{
            i+=pow(-1,k+1);
            j+=pow(-1,k);
            v=1;
        }
        T[i][j]=count++;
    }
}

void q_tab(int n,int T[n][n]){
    int l1_i=0;
    int l2_i=n-1;
    int l3_j=0;
    int l4_j=n-1;
    int i_coef;
    int j_coef;
    int i = 0;
    int j=0;
    int count = 1;
    int k=0;
    while(count<=n*n){
        T[i][j]=count++;
        if(i==l1_i&& k%4==0){
            i_coef = 0;
            j_coef = 1;
            l1_i++;
            k++;
        }
        else if(j==l4_j&&k%4==1){
            i_coef = 1;
            j_coef = 0;
            l4_j--;
            k++;
        }
        else if(i==l2_i&&k%4==2){
            i_coef = 0;
            j_coef = -1;
            l2_i--;
            k++;
        }
        else if(j==l3_j&&k%4==3){
            i_coef=-1;
            j_coef=0;
            l3_j++;
            k++;
        }
        i+=i_coef;
        j+=j_coef;
    }
}
int main(){
    int n,choix;
    printf("Choisissez un nombre n : ");
    scanf("%d",&n);
    int T[n][n];
    while(choix!=1 && choix!=2 && choix!=3 && choix!=4){
        printf("Choisissez un nombre de 1 a 4 pour selectionner un tableau a realiser : ");
        scanf("%d",&choix);
    }
    switch (choix)
    {
    case 1:
        p_tab(n,T);
        break;
    case 2:
        d_tab(n,T);
        break;
    case 3:
        t_tab(n,T);
        break;
    case 4:
        q_tab(n,T);
        break;
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%0.2d  ",T[i][j]);
        }
        printf("\n");
    }
    return 0;
}