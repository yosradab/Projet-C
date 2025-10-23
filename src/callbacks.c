#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "capteur.h"
#include<string.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdlib.h>





void
on_button1_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Ajouter ;

 Capteur=lookup_widget(button,"Capteur");
gtk_widget_destroy(Capteur);
Ajouter=create_Ajouter();
 gtk_widget_show(Ajouter);
}


void
on_button2_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Afficher ;

 Capteur=lookup_widget(button,"Capteur");
gtk_widget_destroy(Capteur);
Afficher=create_Afficher();
 gtk_widget_show(Afficher);
}


void
on_button3_modifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Modifier ;

 Capteur=lookup_widget(button,"Capteur");
gtk_widget_destroy(Capteur);
Modifier =create_Modifier ();
 gtk_widget_show(Modifier);
}


void
on_button4_supprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Supprimer ;

 Capteur=lookup_widget(button,"Capteur");
gtk_widget_destroy(Capteur);
Supprimer =create_Supprimer ();
 gtk_widget_show(Supprimer);
}


void
on_button5_controle_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Controle ;

 Capteur=lookup_widget(button,"Capteur");
gtk_widget_destroy(Capteur);
Controle=create_Controle();
 gtk_widget_show(Controle);
}


void
on_button2_date_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Date ,*Ajouter ;

 Ajouter=lookup_widget(button,"Ajouter");
gtk_widget_destroy(Ajouter);
Date=create_Date();
 gtk_widget_show(Date);
}


void
on_button1_enregister_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
capteur p;
GtkWidget *input1,*input2,*input3,*input4; 
GtkWidget *Ajouter;



input1=lookup_widget(button, "entrynombre") ;
input2=lookup_widget(button, "entrylieu") ;
input3=lookup_widget(button, "entrytype") ;
input4=lookup_widget(button, "entrymarque") ;

strcpy(p.nombre, gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.lieu, gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.type, gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.marque, gtk_entry_get_text(GTK_ENTRY(input4)));

ajouter_capteur (p);

}


void
on_button3_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Ajouter ;

 Ajouter=lookup_widget(button,"Ajouter");
gtk_widget_destroy(Ajouter);
Capteur=create_Capteur();
 gtk_widget_show(Capteur);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nombre;
gchar* lieu;
gchar* type;
gchar* marque;
 capteur p;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nombre,1,&lieu,2,&type,3,&marque,-1);
	strcpy(p.nombre,nombre);
	strcpy(p.lieu,lieu);
	strcpy(p.type,type);
	strcpy(p.marque,marque);
	
	afficher_capteur(treeview);
}
}




void
on_button1_check_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher ,*CheckOut ;

 Afficher=lookup_widget(button,"Afficher");
gtk_widget_destroy(Afficher);
CheckOut=create_CheckOut();
 gtk_widget_show(CheckOut);
}
int etat[]={0,0};
void on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)


{
if (gtk_toggle_button_get_active(togglebutton))
{etat[0]=1;
}
else
{etat[0]=0;
}
}
void
on_button1_done_clicked                (GtkButton       *button,
                                        gpointer         user_data)



{
char texte[100]="";


GtkWidget *output;
output=lookup_widget(button,"label17");
CHECK(etat,texte);
gtk_label_set_text(GTK_LABEL(output),texte);

}
void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if (gtk_toggle_button_get_active(togglebutton))
{etat[1]=1;
}
else {etat[1]=0;
}
}









void
on_button4_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*CheckOut ;

 CheckOut=lookup_widget(button,"CheckOut");
gtk_widget_destroy(CheckOut);
Capteur=create_Capteur();
 gtk_widget_show(Capteur);
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
capteur e;
GtkWidget *input1,*input2,*input3,*input4; 
GtkWidget *Modifier;



input1=lookup_widget(button, "entry5") ;
input2=lookup_widget(button, "entry6") ;
input3=lookup_widget(button, "entry7") ;
input4=lookup_widget(button, "entry8") ;

strcpy(e.nombre, gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.lieu, gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.type, gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.marque, gtk_entry_get_text(GTK_ENTRY(input4)));

modifier_capteur (e);
}


void
on_button2back_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Modifier ;

 Modifier=lookup_widget(button,"Modifier");
gtk_widget_destroy(Modifier);
Capteur =create_Capteur ();
 gtk_widget_show(Capteur);
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
capteur p;
GtkWidget *input1,*input2,*input3,*input4; 
GtkWidget *Supprimer;



input1=lookup_widget(button, "entry9") ;
input2=lookup_widget(button, "entry10") ;
input3=lookup_widget(button, "entry11") ;
input4=lookup_widget(button, "entry12") ;

strcpy(p.nombre, gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.lieu, gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.type, gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.marque, gtk_entry_get_text(GTK_ENTRY(input4)));

Supprimer_capteur(p);
}


void
on_button14_backe_clicked              (GtkButton       *button,
                                        gpointer         user_data)

{
GtkWidget *Capteur ,*Supprimer ;

 Supprimer=lookup_widget(button,"Supprimer");
gtk_widget_destroy(Supprimer);
Capteur=create_Capteur();
 gtk_widget_show(Capteur);
}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *combobox3;

char empla[30];
char emplacement;
char nombcap[50][50];
date d;
int i,n,cap_used;

jour=lookup_widget(button,"jour");
mois=lookup_widget(button,"mois");
annee=lookup_widget(button,"annee");
combobox1=lookup_widget(button,"combobox1");
combobox2=lookup_widget(button,"combobox2");
combobox3=lookup_widget(button,"combobox3");
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if(strcmp("temperature ", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	cap_used=1;
	else cap_used=2;

strcpy(emplacement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))==0);

emplacement=empla[0];
n=disponible_capt(nombcap,emplacement , d,  cap_used);
for (i=0;i<n,i++;)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox3),(nombcap[i]));
}
}




void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *combobox2;
GtkWidget *combobox3;
GtkWidget *sortie;

char Emplacement[20];
capteur p;

combobox1=lookup_widget(button,"combobox1");
jour=lookup_widget(button,"jour");
mois=lookup_widget(button,"mois");
annee=lookup_widget(button,"annee");
combobox2=lookup_widget(button,"combobox2");
combobox3=lookup_widget(button,"combobox3");


p.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
p.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
p.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


	if(strcmp("8h==>17h", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
	
	p.cap_used=1;
	else 
	p.cap_used=2;
	
	
	
strcpy(Emplacement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

p.emplacement=Emplacement[0];

strcpy(p.nombre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));


use_cap(p);
gtk_label_set_text(GTK_LABEL(sortie),"bien reçu");
 	


}








void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Controle ;

 Controle=lookup_widget(button,"Controle");
gtk_widget_destroy(Controle);
Capteur=create_Capteur();
 gtk_widget_show(Capteur);
}


int check[]= {0,0};
void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                       gpointer         user_data)



{
if (gtk_toggle_button_get_active(togglebutton))
{check[0]=1;
}
else
{check[0]=0;
}
}
void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)


{
char out[100]="";
{

GtkWidget *output;
output=lookup_widget(button,"Label38");
checkout(check,out);
gtk_label_set_text(GTK_LABEL(output),out);
}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)


{


if (gtk_toggle_button_get_active(togglebutton))
{check[1]=1;
}
else
{check[1]=0;
}
}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Capteur ,*Afficher ;

 Afficher=lookup_widget(button,"Afficher");
gtk_widget_destroy(Afficher);
Capteur =create_Capteur ();
 gtk_widget_show(Capteur);
}




