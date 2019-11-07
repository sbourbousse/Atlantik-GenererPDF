#include "jeuenregistrement.h"
#include <QDebug>

JeuEnregistrement::JeuEnregistrement(QString chaineSQL) : QSqlQuery(chaineSQL)
{
    QString requeteText = chaineSQL;
    qDebug()<<requeteText;
    end=false;
    first();

}

void JeuEnregistrement::suivant()
{
    end = !next();
}

bool JeuEnregistrement::fin()
{
    return end;
}

QVariant JeuEnregistrement::getValeur(QString nomChamp)
{
    return value(nomChamp);
}

void JeuEnregistrement::fermer()
{
    clear();
}
