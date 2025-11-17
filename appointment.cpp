#include "appointment.h"

Appointment::Appointment(const QString& d, const QString& t, const QString& dn, const QString& p)
    : date(d), time(t), doctorName(dn), purpose(p) {}

QString Appointment::getDate() const { return date; }
QString Appointment::getTime() const { return time; }
QString Appointment::getDoctorName() const { return doctorName; }
QString Appointment::getPurpose() const { return purpose; }

QString Appointment::toString() const {
    return date + " " + time + " - Dr. " + doctorName + " - " + purpose;
}
