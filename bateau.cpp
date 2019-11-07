#include "bateau.h"
#include <QString>
#include "bateauvoyageur.h"

Bateau::Bateau(int unId, QString unNom, float uneLongueur, float uneLargeur)
{
    idBat=unId;
    nomBat=unNom;
    longueurBat=uneLongueur;
    largeurBat=uneLargeur;
}

QString Bateau::versChaine()
{
    //Renvoie les informations relative d'un bateau (quelconque qu'il soit bateau de fret ou de voyage)
    QString infoBateau = "Nom du bateau : "+nomBat+"<br/>"
                         "Longueur : "+QString::number(longueurBat)+" mètres<br/>"
                         "Largeur : "+QString::number(largeurBat)+" mètres<br/>";

    return infoBateau;
}

