#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>


class Equipement
{
private:
    int idEquip;
    QString libEquip;

public:
    Equipement(int unId, QString unLib);
    QString versChaine();
};

#endif // EQUIPEMENT_H
