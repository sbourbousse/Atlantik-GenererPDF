#ifndef JEUENREGISTREMENT_H
#define JEUENREGISTREMENT_H

#include <QString>
#include <QVariant>
#include <QSqlQuery>


class JeuEnregistrement : public QSqlQuery
{
private:
    bool end;
public:
    JeuEnregistrement(QString chaineSQL);
    void suivant();
    bool fin();
    QVariant getValeur(QString nomChamp);
    void fermer();
};

#endif // JEUENREGISTREMENT_H
