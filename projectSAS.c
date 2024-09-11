
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100

struct etudiant{
    int id;
    char nom[50];
    char prenom[50];
    char date_naissance[20];
    char departement[50];
    float note_generale;
};


struct etudiant etudiants [MAX_ETUDIANTS];

int total_etudiants = 0;
int i,j,test;
struct etudiant temp; 
struct etudiant tmp;
float moyenne;
// function Ajoute
void afficherMenuAjout();
void Ajoute_etudiant_simple();
 void Ajoute_etudiant_Multiple();
 
 // function afficher
 void afficher_etudiant();
 
 //
 void Modifier_etudiant();
 //
 void Calculer_moyenne_generale();
 //
 void Supprimer_etudiant();
 //
 void Rechercher_Etudiant();
 //
 void Trier_etudiant_par();
 void Trier_etudiant_par_nom();
 void Tri_par_note_generale();
 // 
 void Afficher_statistiques();
 void Afficher_nombre_total ();
 void Afficher_moyenne_generale_superieure();
void Afficher_nombre_departement();
void Afficher_etudiants_ayant_meilleures3();
void Afficher_nombre_etudiants_departement();
int main(){
   
   

    int travail = 1;

    // La menu principale
    while (travail)
    {
        puts("#### Gestion des etudiant ####");
        puts("\n\t1. Ajouter un etudiant ");
        puts("\t2.Afficher un etudiant");
        puts("\t3.  Modifier un etudiant");
        puts("\t4. Supprimer un etudiant");
        puts("\t5.Calculer la moyenne generale");
        puts("\t6.Afficher les statistiques");
        puts("\t7.Rechercher un etudiant ");
         puts("\t8. ");
        printf("\nEntrer votre choix: ");
        int choix;
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix)
        {
        case 1:
            afficherMenuAjout();
            continue;
        case 2:
           afficher_etudiant();
            break;
        case 3:
         Modifier_etudiant();
         break;
        case 4:
         Supprimer_etudiant();
            break;
        case 5:
         Calculer_moyenne_generale();
            break;
            case 6:
         Afficher_statistiques();
            break;
        case 7:
         Rechercher_Etudiant();
            break;
        case 8 :
        Trier_etudiant_par();
          break;
        case 9:
            travail = 0;
            break;
       
        default:
            puts("Choix invalid.");
        }

        // Pour retour au menu principal
        choix = 0;
        while (choix != 1 && travail != 0) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }

   
    return 0;
}






// --------- Les Fonction D'Ajoutation ---------
void afficherMenuAjout(){
    int choix;

    while (1) {
       
        puts("\n\t1. Ajoute etudiant");
        puts("\t2. Ajoute Multiple etudiant");
        puts("\t3. Retour au menu principal");
       
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
            Ajoute_etudiant_simple();
                break;
            case 2:
            Ajoute_etudiant_Multiple();
                break;
            case 3:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}

void Ajoute_etudiant_simple(){
 if (total_etudiants < MAX_ETUDIANTS) {
     
        printf("Numero unique : ");
        scanf("%d", &etudiants[total_etudiants].id);
        printf("Nom : ");
        scanf("%s", etudiants[total_etudiants].nom);
        printf("Prenom : ");
        scanf("%s", etudiants[total_etudiants].prenom);
        printf("Date de naissance (jj/mm/aaaa) : ");
        scanf("%s", etudiants[total_etudiants].date_naissance);
        printf("Departement : ");
        scanf("%s", etudiants[total_etudiants].departement);
        printf("Note generale : ");
        scanf("%f", &etudiants[total_etudiants].note_generale);
       
       
        total_etudiants++;
        printf("Etudiant ajoute avec succes.\n");
    } else {
        printf("La capacite maximale des etudiants a ete atteinte.\n");
    }
}

void  Ajoute_etudiant_Multiple(){
int size;
printf("Entrez size");
scanf("%d",&size);
for(int i=0 ; i<size;i++){
printf("**********Entrez quelqu un d autre*********** \n");

printf("Numero unique : ");
        scanf("%d", &etudiants[total_etudiants].id);
        printf("Nom : ");
        scanf("%s", etudiants[total_etudiants].nom);
        printf("Prenom : ");
        scanf("%s", etudiants[total_etudiants].prenom);
        printf("Date de naissance (jj/mm/aaaa) : ");
        scanf("%s", etudiants[total_etudiants].date_naissance);
        printf("Departement : ");
        scanf("%s", etudiants[total_etudiants].departement);
        printf("Note generale : ");
        scanf("%f", &etudiants[total_etudiants].note_generale);
       
       
        total_etudiants++;
        printf("Etudiant ajoute avec succes.\n");
 
}
}


// ---------Fonction pour afficher ---------
void afficher_etudiant() {
   
    for (int i = 0; i < total_etudiants; i++) {
printf("=======================================================================================================================\n");

printf("    id        Nom        Prenom      Date de naissance       Departement      Note générale                                          \n");

printf("=======================================================================================================================\n");
printf("   [%d]      %s      %s      %s      %s      %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
           
       
    }
    printf("Étudiant non trouvé.\n");
}


 void Modifier_etudiant(){
  int nwe_id;
  printf(" Enterz id que vous Modifier ");
  scanf("%d",&nwe_id);
  for (int i = 0; i < total_etudiants; i++) {
  if(nwe_id==etudiants[i].id){
  printf("   [%d]      %s      %s      %s      %s      %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
           
        printf("Numero unique : ");
        scanf("%d", &etudiants[i].id);
        printf("Nom : ");
        scanf("%s", etudiants[i].nom);
        printf("Prenom : ");
        scanf("%s", etudiants[i].prenom);
        printf("Date de naissance (jj/mm/aaaa) : ");
        scanf("%s", etudiants[i].date_naissance);
        printf("Departement : ");
        scanf("%s", etudiants[i].departement);
        printf("Note generale : ");
        scanf("%f", &etudiants[i].note_generale);
}
}
       
       
 
 }


  void Supprimer_etudiant(){

    int nwe_id2;
    printf("Enter the ID to delete: ");
    scanf("%d", &nwe_id2);

    for (int i = 0; i < total_etudiants; i++) {
        if (etudiants[i].id == nwe_id2) {
            for (int j = i; j < total_etudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            total_etudiants--;
            break;  
        }
    }

   
}
void Rechercher_Etudiant(){
  char nwe_Rechercher[MAX_ETUDIANTS];
  printf(" Enterz le nom que vous Rechercher ");
  scanf("%s",&nwe_Rechercher);
  for (int i = 0; i < total_etudiants; i++) {
  if(strcmp(nwe_Rechercher,etudiants[i].nom)==0){
  printf("   [%d]      %s      %s      %s      %s      %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
           
}
     
  }
   
}

void Calculer_moyenne_generale(){
    char calc[MAX_ETUDIANTS];
    int sum=0;
    int count=0;
    printf("enter la departement ");
    scanf("%s",&calc);
    for (int i = 0; i < total_etudiants; i++) {
    if(strcmp(etudiants[i].departement,calc)==0){
       
        count++;
        sum+=etudiants[i].note_generale;
    }
   
    }
 
    if(count>0){
        float moyenne = sum / count;
        printf("  la moyenne generale pour le departement %s est %.2f\n",calc,moyenne);
    }else{
 printf("  Aucun etudiant trouve pour le deprartment %s \n ",calc);
    }
     for (int i = 0; i < total_etudiants; i++) {
       
        sum+=etudiants[i].note_generale;
          count++;
       
     }
      if(count > 0){
           float moyenne = sum / count;
           printf("  la moyenne generale pour l unviersite %s est %.2f\n",moyenne);
      }else{
           printf("  Aucun etudiant trouve pour l unviersite\n");
      }
         
}



//
void Afficher_statistiques(){
        int der=1;
       int choix2;
       int choix3;
   puts("  #### Trier_etudiant_par ####   ");
        puts("\n\t1.Afficher le nombre total d etudiants ");
        puts("\t2.Afficher le nombre d etudiants dans chaque departement.");
        puts("\t3.Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.");
        puts("\t4.Afficher les 3 etudiants ayant les meilleures notes.");
        puts("\t5.Afficher le nombre d etudiants ayant reussi dans chaque departement");
        puts("\t6. Retour");
    
    while(der) {
    printf("\nEntrer votre choix: ");
     
        scanf("%d", &choix2);
        switch (choix2)
        {
        case 1:
         Afficher_nombre_total();
        break;
        case 2 :
         Afficher_nombre_departement();
         break;;
        case 3 :
        Afficher_moyenne_generale_superieure();
        break;
        case 4:
        Afficher_etudiants_ayant_meilleures3();
        break;
        case 5:      
        Afficher_nombre_etudiants_departement();
        break;
        case 6:
        der=0;
        break;
        } 
    }while (choix3 != 1 && der != 0) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix3);
            while (getchar() != '\n');
    }
}

void Afficher_nombre_total (){
    float sum1=0;
    for (int i = 0; i < total_etudiants; i++) {
        sum1 += etudiants[i].note_generale;
    }
    float moyenne1 = sum1 / total_etudiants;

     
     if(total_etudiants > 0)
           printf("  la moyenne generale pour l unviersite est %.2f \n",moyenne1);
     else
           printf("  Aucun etudiant trouve pour l unviersite\n");

}

void Afficher_nombre_departement(){

      char departem[MAX_ETUDIANTS];
    
    int count=0;
    printf("enter la departement ");
    scanf("%s",&departem);
    for (int i = 0; i < total_etudiants; i++) {
    if(strcmp(etudiants[i].departement,departem)==0){
      count++;
    }
    }
   printf(" le nombre d etudiants dans chaque departement %s est %d\n", departem,count);
    
}


void Afficher_moyenne_generale_superieure(){
    float new_note;
    printf("enter la nwe not ");
    scanf("%f",&new_note);
for ( i = 0; i < total_etudiants; i++) {
        if(new_note < etudiants[i].note_generale){
           printf("   [%d]      %s      %s      %s      %s   %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);

        }
   }
}


void Afficher_etudiants_ayant_meilleures3(){
    int num = 3;
    for(i = 0 ;i<total_etudiants;i++){
    for( int j = 0; j < total_etudiants - i - 1 ;j++){
        if(etudiants[j].note_generale < etudiants[j+1].note_generale){
            tmp=etudiants[j];
            etudiants[j]=etudiants[j+1];
            etudiants[j+1] = tmp;


        }else if(total_etudiants < 3){
         num=2;
        }
    }
  }
  for (int i = 0; i < num; i++)
    {
        printf("   [%d]      %s      %s      %s      %s   %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
    } 
} 

void Afficher_nombre_etudiants_departement(){
    int moyanne=10;
    for(i = 0 ; i < total_etudiants ; i++){
        if(etudiants[i].note_generale>moyanne){
             printf("   [%d]      %s      %s      %s      %s   %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
        }else
        printf("is not found \n");
    }
}







// 
void Trier_etudiant_par()
{
       int choix1;
   puts("  #### Trier_etudiant_par ####   ");
        puts("\n\t1.Trier etudiant par nom ");
        puts("\t2.Tri par note generale");
        puts("\t3.");
        puts("4. Retour");
    do
    {
    printf("\nEntrer votre choix: ");
     
        scanf("%d", &choix1);
        switch (choix1)
        {
        case 1:
        Trier_etudiant_par_nom();
        continue;
        case 2 :
        Tri_par_note_generale();
        case 3 :
        
        continue;
        case 4:
        continue;
        } }while (choix1 != 3);
}

void Trier_etudiant_par_nom(){
  
        
  for (int i = 0; i < total_etudiants; i++) {
    for (int j = 0 ; j<total_etudiants-i-1; j++) {
        if(strcmp(etudiants[j].nom,etudiants[j+1].nom)>0){
                temp = etudiants[j];
                etudiants[j] = etudiants[j+1];
                etudiants[j+1] = temp;
          }
    }
  }

    for (int i = 0; i < total_etudiants; i++)
    {
        printf("   [%d]      %s      %s      %s      %s      %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
    } 
}

void Tri_par_note_generale(){


    for(i = 0 ;i<total_etudiants;i++){
    for( int j = 0; j < total_etudiants - i - 1 ;j++){
        if(etudiants[j].note_generale < etudiants[j+1].note_generale){
            tmp=etudiants[j];
            etudiants[j]=etudiants[j+1];
            etudiants[j+1] = tmp;


        }
    }
  }
  for (int i = 0; i < total_etudiants; i++)
    {
        printf("   [%d]      %s      %s      %s      %s   %.2f\n", etudiants[i].id,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance, etudiants[i].departement,etudiants[i].note_generale);
    } 
}











