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
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

// Headers
#include "scheduler.h"

unsigned long Scheduler::elapsedTime(Event *event) {
 return ((unsigned long) clock() - event->start) / CLOCKS_PER_SEC;
}

int Scheduler::addEvent(void (*func)(void), int timeout) {
 #ifdef DEBUG
 std::cout << "[DEBUG] [scheduler   ] Adding event " << events.size() << " with timeout " << timeout << "s" << std::endl;
 #endif
 Event *e = new Event;
 e->id = events.size();
 e->start = clock();
 e->func = func;
 e->timeout = timeout;
 events.push_back(e);
 return events.size()-1;
}

void Scheduler::delEvent(int id) {
 #ifdef DEBUG
 std::cout << "[DEBUG] [scheduler   ] Removing event " << id << std::endl;
 #endif
 events.erase(events.begin() + id);
}

void Scheduler::tick(void) {
 for (int i; i < events.size(); i++) {
  if (elapsedTime(events[i]) >= events[i]->timeout) {
   #ifdef DEBUG
   std::cout << "[DEBUG] [scheduler   ] Event " << i << " triggered..." << std::endl;
   #endif
   events[i]->func();
   delEvent(i);
  }
 }
}

void test() { std::cout << "[TEST ] [scheduler   ] Test() called" << std::endl; }

Scheduler::Scheduler() {
 std::cout << "[TEST ] [scheduler   ] Starting scheduler test..." << std::endl;
 #ifdef DEBUG
 std::cout << "[DEBUG] [scheduler   ] Starting scheduler loop..." << std::endl;
 #endif
 addEvent(&test, 1);
 while (true) tick();
}
