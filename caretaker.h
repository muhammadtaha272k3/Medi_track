#ifndef CARETAKER_H
#define CARETAKER_H


#include <QString>

class patient;

class Caretaker
{
public:
    patient* assignedPatients[3];  // max 3 patients
    QString name;
    QString contactinfo;

    Caretaker(const QString& n, const QString& c);

    void add_patient (patient* p);
    void removepatient ( const QString &name);
    // in case if want to empty whole patient list
    void removepatient ();
    QString getname() const;
    QString getcontact_info() const;
    QString toString() const;
};

#endif // CARETAKER_H
