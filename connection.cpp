#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{

db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("smart_tech_store");
db.setUserName("meriem");//inserer nom de l'utilisateur
db.setPassword("meriem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
