#include "medicine.h"

Medicine::Medicine() : name(""), dosage(""), time("") {}

Medicine::Medicine(const QString& n, const QString& d, const QString& t)
    : name(n), dosage(d), time(t) {}

QString Medicine::getName() const { return name; }
QString Medicine::getDosage() const { return dosage; }
QString Medicine::getTime() const { return time; }

void Medicine::setName(const QString& name) { this->name = name; }
void Medicine::setDosage(const QString& dosage) { this->dosage = dosage; }
void Medicine::setTime(const QString& time) { this->time = time; }

QString Medicine::toString() const {
    return name + " - " + dosage + " at " + time;
}
