#include <stdio.h>
#include <stdlib.h>

int ver_mag(int n,int T[n][n]){
    int control = 0;
    int test_val3=0;
    for(int i = 0 ; i < n;i++){
        control += T[i][i];
        test_val3+=T[n-1-i][n-1-i];
    }
    if(test_val3!=control){
        return 0;
    }
    int test_val1=0;
    int test_val2=0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            test_val1+=T[i][j];
            test_val2+=T[j][i];
        }
        if(test_val1!=control || test_val2!=control){
            return 0;
        }
        test_val1=0;
        test_val2=0;
    }
    return 1;
}
/*Méthodologie pour la construite du carré : position initiale de 1 se trouvant au milieu, on peut se répérer en l'utilisant donc pour n'importe quel n
ensuite pour les autres chiffres il suffit  de faire un mouvement en bas soit i++ et un mouvement à droite soit j++
si la case qu'on cible par ce déplacement est remplie par un autre chiffre on descend de deux cases au lieu
au niveau de las extremums de la matrice s'il n'y a plus de place pour descendre en bas dans notre déplacement nous apparaiterons en haut et de même pour la gauche et la droite*/
int square_maker(int n, int T[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            T[i][j] = 0;
        }
    }
    int c = n/2 + 1;
    int l = n/2;
    int count = 1;
    for(int i = 0; i < (n*n)  ; i++){
    T[c][l] = count;
    if(count%n == 0){
        c += 2;
        if(c > n-1){
            c = c -n;
        }
    }
    else
    {
    if( c + 1 > n-1){
        c = 0;
        }
        else{
            c++;
        }
        if ( l + 1 > n-1){
            l = 0;
        } 
        else{
        l++;
        }
    }
    count ++;
    }
}
int main(){
    int n=0;
    while(n%2!=1){
        printf("Entrez un nombre n impaire : ");
        scanf("%d",&n);
    }
    int T[n][n];
    square_maker(n,T);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%0.2d  ",T[i][j]);
        }
        printf("\n");
    }
    if(ver_mag(n,T)){
        printf("La matrice est bien un carre parfait");
    }
    else{
        printf("Il ne s'agit pas d'un carré parfait");
    }
    return 0;
}