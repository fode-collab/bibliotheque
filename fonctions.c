
void menu(){
  int chx;
  char rep[6];
    printf("Donne votre nom pour commencer:");scanf("%s",name_unit);
    printf("Tu es utilisateur(oui ou non):");
    scanf("%s",rep);
    if(strcmp(rep,"oui")==0 ||strcmp(rep,"OUI")==0){
  printf("--------------GESTION DES LIVRES D'UNE BIBLITHEQUE------------\n");
  do{
  bye:
  printf("1-Afficher les livres\n");
  printf("2-Rechercher un livre\n");
  printf("3-Trier les livres\n");
  printf("0-Fin de traitement\n\n");
  do{
  printf("Donne votre choix:");
  scanf("%d",&chx);
  }while(chx!=0 &&chx!=1 && chx!=2 && chx!=3);
   switch(chx){

  case 1:{afficher();break;}
  case 2:{rechercher();break;}
  case 3:{trier();break;}
  case 0:{printf("Fin de traitement");break;}
  default : printf("Choix errone !!! choisir(0,3)\n");


  }
   if(chx!=0){
printf("Tu es utilisateur(oui ou non):");
    scanf("%s",rep);
        if(strcmp(rep,"oui")!=0 ||strcmp(rep,"OUI")!=0)
   goto start;
   }

}while(chx!=0 );

    }
    else
    {
        do{
                start:
  printf("\n1-Ajouter un livre\n");
  printf("2-Modifier un livre\n");
  printf("3-Supprimer un livre\n");
  printf("4-Stocker les livre\n");
  printf("0-Fin de traitement\n\n");
  do{
  printf("Donne votre choix:");
  scanf("%d",&chx);
  }while(chx!=0 &&chx!=1 && chx!=2 && chx!=3);
   switch(chx){
  case 1:{ajouter();break;}
  case 2:{modifier();break;}
  case 3:{supprimer();break;}
  case 4:{stocker();break;}
  case 0:{printf("Fin de traitement\n");break;}
  default :
      printf("Choix errone !!! choisir(0,4)\n");


    }
         if(chx!=0){

   printf("Tu es utilisateur(oui ou non):");
    scanf("%s",rep);
        if(strcmp(rep,"oui")==0||strcmp(rep,"OUI")==0)
   goto bye;
         }


   } while(chx!=0);

}
}

 void ajouter(){
  tp=fopen("csv.txt","a+");
  char ident[5],idt[5];
  int tr=0;
  Livre lv;
  printf("Donne l'id du livre a ajouter:");scanf("%s",ident);
  while(!feof(tp)){
    fscanf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           &lv.prix,lv.cathe,lv.dispo);
           if(strcmp(ident,lv.id)==0){
            tr=1;
            break;
           }
  }
   if(tr==1)
    printf("Le livre existe deja\n");

    else{
   strcpy(lv.id,ident);
   strcpy(lv.name_user,name_unit);

   printf("Donne le titre:");fflush(stdin);gets(lv.titre);
   printf("Donne l'auteur:");gets(lv.auteur);
   printf("Donne la description:");gets(lv.description);
    printf("Donne le prix:");scanf("%f",&lv.prix);
     printf("Donne la cathegorie:");fflush(stdin);gets(lv.cathe);
     do{
     printf("l'etat du livre(dispo ou emprunter):");gets(lv.dispo);
     }while(strcmp(lv.dispo,"dispo")!=0 && strcmp(lv.dispo,"emprunter")!=0);
     fprintf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           lv.prix,lv.cathe,lv.dispo);

    }
    fclose(tp);

}
void modifier(){

  tp=fopen("csv.txt","r");
  FILE*ts=fopen("temps.txt","w");
  Livre lv;
  char ident[5];
  int tr=0;
  printf("Donne l'id du livre a modifier:");
  scanf("%s",ident);
  while(!feof(tp)){
    fscanf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           &lv.prix,lv.cathe,lv.dispo);
        if(strcmp(ident,lv.id)==0){
                tr=1;
                printf("Donne le nouveau titre:");scanf("%s",lv.titre);
                printf("Donne le nouveau auteur:");scanf("%s",lv.auteur);
        }
    fprintf(ts,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           lv.prix,lv.cathe,lv.dispo);



}
   fclose(tp); fclose(ts);
   remove("csv.txt");
   rename("temps.txt","csv.txt");
   if(tr==1)
    printf("Le livre est modifier\n");
   else
    printf("Le livre n'existe pas\n");
}
void supprimer(){

 tp=fopen("csv.txt","r");
  FILE*ts=fopen("temps.txt","w");
  Livre lv;
  char ident[5];
  int tr=0;
  printf("Donne l'id du livre a supprimer:");
  scanf("%s",ident);
  while(!feof(tp)){
    fscanf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           &lv.prix,lv.cathe,lv.dispo);
        if(strcmp(ident,lv.id)!=0)


    fprintf(ts,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           lv.prix,lv.cathe,lv.dispo);
           else
            tr=1;





}
   fclose(tp); fclose(ts);
   remove("csv.txt");
   rename("temps.txt","csv.txt");
   if(tr==1)
    printf("Le livre est supprimer\n");
   else
    printf("Le livre n'existe pas\n");



}

void afficher(){
 tp=fopen("csv.txt","r");
 Livre lv;
   while(!feof(tp)){
     fscanf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           &lv.prix,lv.cathe,lv.dispo);
        printf("ID:%s\nTitre:%s\nAuteur:%s\nDescription:%s\nUser name:%s\nPrix:%f\nCathegorie:%s\nDisponibilite:%s\n",
               lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           lv.prix,lv.cathe,lv.dispo);


   }

  fclose(tp);


}
void stocker(){
  tp=fopen("csv.txt","a");
  Livre lv;
  int n,i;
  printf("Donne le nombre de livre a stocker:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    ajouter();
  }

fclose(tp);

}
void rechercher(){
  tp=fopen("csv.txt","r");
  int tr=0;
  Livre lv;
  char tit[15],aut[15];
  printf("Donne le titre a chercher:");scanf("%s",tit);
    printf("Donne l'auteur a chercher:");scanf("%s",aut);
 while(!feof(tp)){
     fscanf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           &lv.prix,lv.cathe,lv.dispo);
           if(strcmp(tit,lv.titre)==0 && strcmp(aut,lv.auteur)==0){
            tr=1;
            printf("ID:%s\nTitre:%s\nAuteur:%s\nDescription:%s\nUser name:%s\nPrix:%f\nCathegorie:%s\nDisponibilite:%s\n",
               lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           lv.prix,lv.cathe,lv.dispo);
           }

}
  fclose(tp);
  if(tr==0)
    printf("Le livre n'existe pas\n");
}
void trier(){
  tp=fopen("csv.txt","r");
   Livre lv,k;

   Livre T[100];
   int n=0,i,j;
   while(!feof(tp)){
     fscanf(tp,"%s\n%s\n%s\n%s\n%s\n%f\n%s\n%s\n",lv.id,lv.titre,lv.auteur,lv.description,lv.name_user,
           &lv.prix,lv.cathe,lv.dispo);
           T[n]=lv;
           n++;

}
 for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(strcmp(T[i].titre,T[j].titre)>0 &&strcmp(T[i].cathe,T[j].cathe)>0){
            k=T[i];
            T[i]=T[j];
            T[j] =k;
        }
    }
   }

   for(i=0;i<n;i++){
         printf("ID:%s\nTitre:%s\nAuteur:%s\nDescription:%s\nUser name:%s\nPrix:%f\nCathegorie:%s\nDisponibilite:%s\n",
               T[i].id,T[i].titre,T[i].auteur,T[i].description,T[i].name_user,
           T[i].prix,T[i].cathe,T[i].dispo);
   }

}
