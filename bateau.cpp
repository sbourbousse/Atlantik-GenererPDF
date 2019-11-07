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
    QString infoBateau = "Nom du bateau : "+nomBat+"<br/>"
                         "Longueur : "+QString::number(longueurBat)+" mètres<br/>"
                         "Largeur : "+QString::number(largeurBat)+" mètres<br/>";

    return infoBateau;
}

