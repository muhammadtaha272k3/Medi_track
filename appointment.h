#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QString>

class Appointment {
private:
    QString date;
    QString time;
    QString doctorName;
    QString purpose;

public:
    Appointment(const QString& d, const QString& t, const QString& dn, const QString& p);

    // Getters
    QString getDate() const;
    QString getTime() const;
    QString getDoctorName() const;
    QString getPurpose() const;

    QString toString() const;
};

#endif // APPOINTMENT_H
