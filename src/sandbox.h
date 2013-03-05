/*
 * =====================================================================================
 *
 *       Filename:  sandbox.h
 *
 *    Description:  TouchNet 2 sandbox headers
 *
 *        Version:  0.1
 *        Created:  05/03/13 14:45:10
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

#ifndef SANDBOX_H
#define SANDBOX_H

#include "config.h"
#include "json/json.h"

// Standard headers
#include <iostream>
#include <stdio.h>
#include <string>

class Sandbox {
private:
 Json::Value parseJSON(std::string);
 std::string exec(std::string);
public:
 Sandbox();
};

#endif /* SANDBOX_H */
