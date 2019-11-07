#include "bateauvoyageur.h"
#include <QString>
#include "equipement.h"
#include <vector>

BateauVoyageur::BateauVoyageur(int unId, QString unNom, float uneLongueur, float uneLargeur, int uneVitesse, QString uneImage, std::vector<Equipement> collectionEquipement) : Bateau(unId,unNom,uneLongueur,uneLargeur)
{
    vitesseBatVoy=uneVitesse;
    imageBatVoy=uneImage;
    listeEquipement = collectionEquipement;
}


QString BateauVoyageur::versChaine()
{
    QString infoBateau = Bateau::versChaine();

    infoBateau += "Vitesse : "+QString::number(vitesseBatVoy)+" noeuds<br/>";

    //Si le bateau possede des equipement
    if(listeEquipement.size()>0)
    {
        QString lesEquipements = "Liste des équipement du bateau : <br/>";
        for(int i = 0 ; i<listeEquipement.size() ; i++)
        {
            lesEquipements +="-"+listeEquipement[i].versChaine()+"<br/>";
        }
        infoBateau +=lesEquipements;
    }

    return infoBateau;
}

QString BateauVoyageur::getImageBatVoy()
{
    QString imageDuBateau = "img/"+imageBatVoy;
    return imageDuBateau;
}

