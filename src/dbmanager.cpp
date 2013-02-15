/*
 * =====================================================================================
 *
 *       Filename:  dbmanager.cpp
 *
 *    Description:  Database manager
 *
 *        Version:  0.1
 *        Created:  15/02/13 21:49:01
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

// Headers
#include "dbmanager.h"

DatabaseManager::DatabaseManager(std::string database_name) {
 dbname = database_name;
}
