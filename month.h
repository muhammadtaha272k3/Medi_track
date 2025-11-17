#ifndef MONTH_H
#define MONTH_H

#include "day.h"
#include "queue.h"
class month
{
public:
    int x ;
    queue<Day> days;

    month();
};

#endif // MONTH_H
