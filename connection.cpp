#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("projet_qt");
db.setUserName("youssef");//inserer nom de l'utilisateur
db.setPassword("youssef");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
