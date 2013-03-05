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
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
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

class Event {
 // TODO
};

class Scheduler {
private:
 unsigned long start;
 Event events[];
 unsigned long elapsedTime(void);
 void tick(void);
public:
 Scheduler();
 void reset(void);
 int addEvent(void *, int);
 void delEvent(int);
};

#endif /* SCHEDULER_H */
