/*
 * =====================================================================================
 *
 *       Filename:  scheduler.cpp
 *
 *    Description:  TouchNet 2 Scheduler
 *
 *        Version:  0.1
 *        Created:  05/03/13 15:54:32
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

// Headers
#include "scheduler.h"

void Scheduler::reset(void) {
 start = clock();
}

unsigned long Scheduler::elapsedTime(void) {
 return ((unsigned long) clock() - start) / CLOCKS_PER_SEC;
}

int Scheduler::addEvent(void *func, int timeout) {
 // TODO: add an event to the array
}

void Scheduler::delEvent(int id) {
 // TODO: remove event by id
}

void Scheduler::tick(void) {
 // TODO: loop through events and check if one occured
}

Scheduler::Scheduler() {
 std::cout << "[TEST ] [scheduler   ] Starting scheduler test..." << std::endl;
 #ifdef DEBUG
 std::cout << "[DEBUG] [scheduler   ] Starting scheduler loop..." << std::endl;
 #endif
 while (true) tick();
}
