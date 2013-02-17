/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main entry for the manager
 *
 *        Version:  0.1
 *        Created:  15/02/13 21:56:47
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
 *   Organization:  TouchLay 
 *
 * =====================================================================================
 */

// Standard headers
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Internal headers
#include "config.h"
#include "manager.h"

/* versioninfo: Show information about this build */
void versioninfo(bool booting) {
 std::cout << "[INFO ] " << NAME_TAG << " [main        ] " << NAME << " v" << VERSION;
 #ifdef VERSION_TAG
 std::cout << " (" << VERSION_TAG << ")";
 #endif
 if (booting) std::cout << " booting..." << std::endl;
 else std::cout << " built at " << __DATE__ << ", " << __TIME__ << "." << std::endl;
 std::cout << "[INFO ] " << NAME_TAG << " [main        ]  Copyright (c) 2013 Daniel Bugl <daniel.bugl@touchlay.com>" << std::endl;
 if (!booting) {
  std::cout << "[INFO ] " << NAME_TAG << " [main        ] Compilation configuration:" << std::endl;
  #ifdef DEBUG
  std::cout << "[INFO ] " << NAME_TAG << " [main        ]  DEBUG=true" << std::endl;
  #else
  std::cout << "[INFO ] " << NAME_TAG << " [main        ]  DEBUG=false" << std::endl;
  #endif
 }
}

/* main: Main function */
int main(int argc, char *argv []) {
 char c;
 opterr = 0;
 while ((c=getopt(argc, argv, "v")) != -1) {
  switch (c) {
   case 'v':
    versioninfo(false);
    return EXIT_SUCCESS;
    break;
   case '?':
    if (isprint((char)optopt)) std::cout << "[ERROR] " << NAME_TAG << " [main        ] Unknown option: -" << (char)optopt << "." << std::endl;
    else std::cout << "[ERROR] " << NAME_TAG << " [main        ] Unknown option character: " << (char)optopt << "." << std::endl;
    return EXIT_FAILURE;
   default:
    abort();
  }
 }
 
 // Print info messages
 versioninfo(true);
 
 Manager *m = new Manager();
 free(m);
}
