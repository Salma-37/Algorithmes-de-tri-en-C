#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#define TAILLE_MAX 10000000
#define TAILLE 100
int T[TAILLE_MAX];
int N;
//Tri à bulles: (complxité O(n^2))
void tri_a_bulle(int T[]){
    int i,j,aide;
    bool temoin;
    for(i=0;i<N;i++){
        temoin=false;
         for(j=0;j<N-1;j++){
        if(T[j]>T[j+1]){
            aide=T[j];
            T[j]=T[j+1];
            T[j+1]=aide;
            temoin=true;
        }
        if(!temoin)
            break;
    }
    }
    for(i=0;i<N;i++)
        printf("%d\t",T[i]);
}
//Tri par sélection:
void tri_par_selection(int T[]){
    int i,j,k,indice_min=0,min,l=N,indice;
    for(k=0;k<l-1;k++){
        min=T[indice_min];
        for(i=indice_min;i<l;i++){
            if(T[i]<=min){
                min=T[i];
                indice=i;
            }
        }
        if(indice!=indice_min){ // si l'element est déjà à sa place
            for(j=indice;j>indice_min;j--){
                T[j]=T[j-1];
            }
            T[indice_min]=min;
        }
        indice_min++;
    }
}
//Tri par insertion
void tri_par_insertion(int T[]){
    int i,j,indice,aide;
    for(i=1;i<N;i++){
        if(T[i]<T[i-1]){
            for(j=0;j<i;j++)
                if(T[i]<T[j]){
                    aide=T[i];
                    T[i]=T[j];
                    T[j]=aide;
                }
        }
    }
}
//Tri de shell
void tri_de_shell(int T[]){
    int intervalle,i,j;
    for(intervalle=N;intervalle>0;intervalle=intervalle/2){
        for(j=intervalle;j<N;j++){
            for(i=j-intervalle;i>=0;i=i-intervalle){
                if(T[i]<=T[i+intervalle])
                    break;
                else{
                    int aide=T[i];
                    T[i]=T[i+intervalle];
                    T[intervalle]=aide;
                }
            }
        }
    }
}
//Tri par tas
void tas(int T[],int taille,int i){
    taille=N;
    int maxIdx=i;
    int g=2*i+1;
    int d=2*i+2;
    if(g<taille && T[g]>T[maxIdx])
        maxIdx=g;
    if(d<taille && T[d]>T[maxIdx])
        maxIdx=d;
    if(maxIdx!=i){
        int aide=T[i];
        T[i]=T[maxIdx];
        T[maxIdx]=aide;
        tas(T,taille,maxIdx);
    }
}
void tri_par_tas(int T[]){
    int i;
    for(i=N/2-1;i>=0;i--)
        tas(T,N,i);
    for(i=N-1;i>=0;i--){
        int aide=T[i];
        T[i]=T[0];
        T[0]=aide;
        tas(T,i,0);
    }
}
//Tri par comptage
void tri_par_comptage(int T[]){
    int N1[N];
    int i,max=T[0];
    for(i=1;i<N;i++){
        if(T[i]>max)
            max=T[i];
    }
    int compte[max+1];
    for(i=0;i<=max;i++)
        compte[i]=0;
    for(i=0;i<N;i++)
        compte[T[i]]++;
    for(i=1;i<max;i++)
        compte[i]+=compte[i-1];
    for(i=N-1;i>=0;i--){
        compte[T[i]]--;
        N1[compte[T[i]]]=T[i];
    }
    for(i=0;i<N;i++)
        T[i]=N1[i];
}
//Tri rapide
int partition(int T[],int low,int high){
    int pivot=T[high],i=low-1,j;
    for(j=low;j<high;j++){
        if(T[j]<=pivot){
            i++;
            int aide=T[j];
            T[j]=T[i];
            T[i]=aide;
        }
    }
    int aux=T[i+1];
    T[i+1]=T[high];
    T[high]=aux;
    return i+1;
}
void tri_rapide(int T[],int low,int high){
    if(low<high){
        int indice_pivot=partition(T,low,high);
        tri_rapide(T,low,indice_pivot-1);
        tri_rapide(T,indice_pivot+1,high);
    }
}
void tri_rapide_wrapper(int T[]){
    tri_rapide(T,0,N-1);
}
//Tri par fusion
void fusion(int T[],int debut,int milieu,int fin){
    int i,j,k;
    int n1=milieu-debut+1;
    int n2=fin-milieu;
    int Tgauche[n1],Tdroit[n2];
    for(i=0;i<n1;i++)
        Tgauche[i]=T[debut+i];
    for(j=0;j<n2;j++)
        Tdroit[i]=T[milieu+1+j];
    i=0;
    j=0;
    k=debut;
    while(i<n1 && j<n2){
        if(Tgauche[i]<=Tdroit[j]){
            T[k]=Tgauche[i];
            i++;
        }else{
            T[k]=Tdroit[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        T[k]=Tgauche[i];
        i++;
        k++;
    }
    while(j<n2){
        T[k]=Tdroit[j];
        j++;
        k++;
    }
}
void tri_par_fusion(int T[],int debut,int fin){
    if(debut<fin){
        int milieu=(debut+fin)/2;
        tri_par_fusion(T,debut,milieu);
        tri_par_fusion(T,milieu+1,fin);
        fusion(T,debut,milieu,fin);
    }
}
void tri_par_fusion_wrapper(int T[]){
    tri_par_fusion(T,0,N-1);
}
//remplissage du tableau par les valeurs aléatoires
void remplir(){
    for(int i=0;i<N;i++)
    T[i]=rand();
}
//affichage
void affichage(int T[]){
    for(int i=0;i<N;i++)
        printf("%d\t",T[i]);
}
//calcul du temps d'exécution
double temps_execution(void (*tri)(int*),int T[]){
    clock_t debut=clock();
    tri(T);
    clock_t fin=clock();
    return (double)(fin-debut)/CLOCKS_PER_SEC;
}
int main(){
    int tailles[TAILLE],rep=10;
    tailles[0]=1000;
    for(int k=1;k<100;k++)
        tailles[k]=tailles[k-1]+1000;
    int nbr_taille=sizeof(tailles)/sizeof(tailles[0]);
    FILE *F=fopen("Resultat.csv","w");
    if(F==NULL){
        printf("Erreur d'ouverture du fichier.");
        exit(-1);
    }
    fprintf(F,"Taille,bulle,selection,insertion,shell,tas,comptage,rapide,fusion\n");
    for(int i=0;i<nbr_taille;i++){
        N=tailles[i];
        remplir();
        int copie[N];
        double t_bulle,t_selection,t_insertion,t_shell,t_tas,t_comptage,t_rapide,t_fusion;
        memcpy(copie,T,N*sizeof(int));
        t_bulle=temps_execution(tri_a_bulle,copie);
        memcpy(copie,T,N*sizeof(int));
        t_selection=temps_execution(tri_par_selection,copie);
        memcpy(copie,T,N*sizeof(int));
        t_insertion=temps_execution(tri_par_insertion,copie);
        memcpy(copie,T,N*sizeof(int));
        t_shell=temps_execution(tri_de_shell,copie);
        memcpy(copie,T,N*sizeof(int));
        t_tas=temps_execution(tri_par_tas,copie);
        memcpy(copie,T,N*sizeof(int));
        t_comptage=temps_execution(tri_par_comptage,copie);
        memcpy(copie,T,N*sizeof(int));
        t_rapide=temps_execution(tri_rapide_wrapper,copie);
        memcpy(copie,T,N*sizeof(int));
        t_fusion=temps_execution(tri_par_fusion_wrapper,copie);
        fprintf(F,"%d,%f,%f,%f,%f,%f,%f,%f,%f\n",N,t_bulle,t_selection,t_insertion,t_shell,t_tas,t_comptage,t_rapide,t_fusion);
        fflush(F);
    }
    fclose(F);
   return 0; 
}

