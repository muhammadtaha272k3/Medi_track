#ifndef PATIENT_H
#define PATIENT_H

#include "medicine.h"
#include "day.h"
#include "caretaker.h"
#include "appointment.h"
#include "queue.h"
#include <QString>

class patient {
private:
    QString firstname;
    QString lastname;
    QString username;
    QString password;
    QString dateOfBirth;
    int age;
    double weight_kg;
    double weight_lb;
    QString height;//storing height in cm by default;
    QString bloodGroup;
    QString gender;
    QString contactInfo;

    queue<Day> medicationSchedule;
    Caretaker* caretakers[2];
    queue<Appointment> appointmentList;

public:
    // Constructors
    patient(const QString& first, const QString& last,
            const QString& user, const QString& pass,
            const QString& dob, int a, double w_kg,
            const QString& h, const QString& bg,
            const QString& g, const QString& contact);

    patient(const QString& first, const QString& last,
            const QString& dob, const QString& user, const QString& pass);

    // Destructor
    ~patient();

    // ---------------- Medicine management ----------------
    void addMedicineToDay(const QString& medName, const QString& dose,
                          const QString& time, const QString& date, const QString& dayOfWeek);

    // ---------------- Appointment management ----------------
    void addAppointment(const QString& date, const QString& time,
                        const QString& doctor, const QString& purpose);

    // ---------------- Caretaker management ----------------
    void assignCaretaker(Caretaker* ct, int index);
    void removeCaretaker(int index);

    // ---------------- Getters ----------------
    QString getFirstname() const;
    QString getLastname() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getName() const;
    QString getDateOfBirth() const;
    int getAge() const;
    double getWeightKg() const;
    double getWeightLb() const;
    QString getHeight() const;
    QString getBloodGroup() const;
    QString getGender() const;
    QString getContactInfo() const;

    QString getMedicationScheduleAsString() const;
    QString getAppointmentsAsString() const;
    QString getCaretakersAsString() const;

    // ---------------- Setters ----------------
    void setFirstname(const QString& first);
    void setLastname(const QString& last);
    void setUsername(const QString& user);
    void setPassword(const QString& pass);
    void setDateOfBirth(const QString& dob);
    void setAge(int a);
    void setWeightKg(double w_kg);
    void setWeightlb(double w_lb);
    void setHeight(const QString& h);
    void setBloodGroup(const QString& bg);
    void setGender(const QString& g);
    void setContactInfo(const QString& contact);

    // ---------------- Utility ----------------
    QString toString() const;
};

#endif // PATIENT_H
