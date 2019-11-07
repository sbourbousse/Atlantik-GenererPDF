#ifndef BATEAU_H
#define BATEAU_H
#include <QString>


class Bateau
{
private:
    int idBat;
    QString nomBat;
    float longueurBat;
    float largeurBat;

public:
    Bateau(int unId, QString unNom, float uneLongueur, float uneLargeur);
    QString versChaine();
};

#endif // BATEAU_H
