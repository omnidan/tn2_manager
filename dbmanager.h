/*
 * =====================================================================================
 *
 *       Filename:  dbmanager.h
 *
 *    Description:  Database manager - headers
 *
 *        Version:  0.1
 *        Created:  15/02/13 21:49:56
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

// Standard headers
#include <iostream>

class DatabaseManager {
private:
 std::string dbname;
public:
 DatabaseManager(std::string);
}

#endif /* DATABASEMANAGER_H */
