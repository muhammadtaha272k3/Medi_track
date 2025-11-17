#include "day.h"
#include <QStringList>



Day:: Day(const QString& dayname , const QString& date ) : Date(date), dayname(dayname) {}


void Day::addMedicine(const Medicine& m) {
    medicines.enqueue(m);
}

Medicine Day::takeMedicine() {
    if (!medicines.isEmpty()) {
        return medicines.dequeue();
    }
    return Medicine();
}

bool Day::hasMedicine() const {
    return !medicines.isEmpty();
}

int Day::medicineCount() const {
    return medicines.size();
}
QString Day::getDate() const { return Date; }
QString Day::getDayOfWeek() const { return dayname; }

QString Day::getMedicinesAsString() const {
    if (medicines.isEmpty()) {
        return "No medicines scheduled";
    }

    queue<Medicine> temp = medicines;
    QStringList medicines;
    while (!temp.isEmpty()) {
        Medicine med = temp.dequeue();
        medicines << med.toString();
    }
    return medicines.join("; ");
}


