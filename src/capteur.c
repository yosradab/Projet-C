#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include"capteur.h"
#include<gtk/gtk.h>


enum 
{
	NOMBRE,
	LIEU,
	TYPE,
	MARQUE,
	
};

void ajouter_capteur(capteur p)
{
FILE* f;
f=fopen("capteur.txt","a");
	if(f!=NULL)
	{ fprintf(f,"%s %s %s %s \n",p.nombre,p.lieu,p.type,p.marque);
	fclose(f);
	}

}
void afficher_capteur(GtkWidget *liste)
{

  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
   GtkTreeIter *store;




  char nombre[30];
  char lieu[30];
  char type[30];
  char marque[30]; 
  capteur p;
  store=NULL;
   FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(  "  marque",renderer,"text",marque,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(  "  lieu",renderer,"text",lieu,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
					column=gtk_tree_view_column_new_with_attributes(  "   nombre",renderer,"text",NOMBRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(  "  type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
store=gtk_list_store_new(column,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("capteur.txt","a+");
if(f==NULL)
{	return;
}
else
{f=fopen("capteur.txt","r");
		while(fscanf(f,"%s %s %s %s \n",p.nombre,p.lieu,p.type,p.marque)!=EOF);
	{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,MARQUE,p.marque,LIEU,p.lieu,TYPE,p.type,NOMBRE,p.nombre,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
	}
}

void CHECK(int etat[], char texte[] )
{
strcpy(texte,"tous les informations du capteurs sont  :");
if(etat[0]==1)
strcat(texte," Disponibles ");
if(etat[0]==0)
strcat(texte," ");
if(etat[1]==1)
strcat(texte,"Manquantes : Priere d'ajouter les informations le plus tot possible");
if(etat[1]==0)
strcat(texte," ");
}
void modifier_capteur(capteur e)
{
FILE*f=NULL;
FILE*f1=NULL;
capteur p;

f=fopen("capteur.txt","r");
f1=fopen("capteurS.txt","w+");

while(fscanf(f,"%s %s %s %s \n ",p.nombre,p.lieu,p.type,p.marque)!=EOF){
		if(strcmp(p.nombre,e.nombre)!=0||strcmp(p.lieu,e.lieu)!=0||strcmp(p.type,e.type)!=0||strcmp(p.marque,e.marque)!=0){
			fprintf(f1,"%s %s %s %s \n",p.nombre,p.lieu,p.type,p.marque);
		}
			else{

			fprintf(f1,"%s %s %s %s \n",e.nombre,e.lieu,e.type,e.marque);

			}
		
		}
		fclose(f);	
		fclose(f1);
		
	remove("capteur.txt");
	rename("capteurS.txt","capteur.txt");
	

}
void Supprimer_capteur(capteur p)
{
char nombre[50];
char lieu[50];
char type[50];
char marque[50];

FILE*f,*f1;

f=fopen("capteur.txt","r");
f1=fopen("capteurS.txt","w+");
if (f==NULL || f1==NULL)
	{
	return;
	}	
else{
	while(fscanf(f,"%s %s %s %s \n ",p.nombre,p.lieu,p.type,p.marque)!=EOF){
			if(strcmp(p.nombre,nombre)!=0||strcmp(p.lieu,lieu)!=0||strcmp(p.type,type)!=0||strcmp(p.marque,marque)!=0)
				fprintf(f1,"%s %s %s %s \n",nombre,lieu,type,marque);
			}
			fclose(f);
			fclose(f1);
		
	remove("capteur.txt");
	rename("capteurS.txt","capteur.txt");
	}
}
int capteur_used(capteur tab[])
{
int n=0;
FILE* f=fopen("capN.txt","r");
if(f!=NULL)
{	while (fscanf(f,"%s %c %d %d %d %d",tab[n].nombre,&tab[n].emplacement,&tab[n].d.jour,&tab[n].d.mois,&tab[n].d.annee,&tab[n].cap_used)!=EOF)
	{n++;}
fclose(f);
}
return n;
}
int verif_capused(capteur cap)
{ 
capteur p;
int v=0; 
FILE* f=fopen("capN.txt","r");
if(f!=NULL)
{	while (!v && fscanf(f,"%s %c %d %d %d %d",p.nombre,&p.emplacement,&p.d.jour,&p.d.mois,&p.d.annee,&p.cap_used)!=EOF)
		{if(strcmp(p.nombre,cap.nombre)==0)
			
			{if((p.d.jour==cap.d.jour) && (p.d.mois==cap.d.mois) && (p.d.annee==cap.d.annee))
				{v=1;}
		}

}
fclose(f);
}
return v;
}
int disponible_capt(char nombcap[100][50],char emplacement ,date d,int  cap_used)
{
int i,nc=0;
FILE* f=fopen("capN.txt","r");
capteur p;
p.emplacement=emplacement;
p.cap_used=cap_used;
p.d=d;
if(f!=NULL)
{
	while (fscanf(f,"%s",p.nombre)!=EOF)
		if(p.nombre[0]==emplacement)
		{
			int v=verif_capused(p);
		    		if(!v)
				{strcpy(nombcap[nc],p.nombre);
				nc++;
				}
		}
}

fclose(f);
return nc;
}
void use_cap( capteur p)
{
	FILE* f=fopen("capused.txt","r");
	if(f!=NULL)
	{ fprintf(f,"%s %c %d %d %d %d \n",p.nombre,p.emplacement,p.d.jour,p.d.mois,p.d.annee,p.cap_used);
	fclose(f);
	}
}
void checkout(int check[], char out[] )
{
strcpy(out,"vos capteurs sont :");
if(check[0]==1)
strcat(out," AU COURS DE REPARATION ");
if(check[0]==0)
strcat(out," ");
if(check[1]==1)
strcat(out," EN BON ETAT ");
if(check[1]==0)
strcat(out,"  ");
}
