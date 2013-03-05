/*
 * =====================================================================================
 *
 *       Filename:  scheduler.h
 *
 *    Description:  TouchNet 2 scheduler headers
 *
 *        Version:  0.1
 *        Created:  05/03/13 15:55:37
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <daniel.bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "config.h"

// Standard headers
#include <iostream>
#include <time.h>
#include <vector>

struct Event {
 int id;
 unsigned long start;
 void (*func)(void);
 int timeout;
};

class Scheduler {
private:
 std::vector<Event *> events;
 unsigned long elapsedTime(Event *);
 void tick(void);
public:
 Scheduler();
 int addEvent(void (*)(void), int);
 void delEvent(int);
};

#endif /* SCHEDULER_H */
