#ifndef DAY_H
#define DAY_H
#include <QString>
#include "queue.h"
#include "medicine.h"

class Day
{
public:
    QString dayname;
    QString Date;
    queue<Medicine> medicines;

    Day(const QString& dayname , const QString& date );

    void addMedicine(const Medicine& m);
    Medicine takeMedicine();
    bool hasMedicine() const;
    int medicineCount() const;

    // Getters
    QString getDate() const;
    QString getDayOfWeek() const;

    QString getMedicinesAsString() const;

};

#endif // DAY_H
