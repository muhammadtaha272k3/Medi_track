#include "patient.h"
#include "queue.h"
#include "day.h"
#include "caretaker.h"
#include "medicine.h"
#include "appointment.h"
#include <QString>
#include <QStringList>

// Full constructor
patient::patient(const QString& first, const QString& last,
                 const QString& user, const QString& pass,
                 const QString& dob, int a, double w_kg,
                 const QString& h, const QString& bg,
                 const QString& g, const QString& contact)
    : firstname(first), lastname(last), username(user), password(pass),
    dateOfBirth(dob), age(a), weight_kg(w_kg),
    weight_lb(w_kg * 2.20462), height(h), bloodGroup(bg),
    gender(g), contactInfo(contact)
{
    caretakers[0] = caretakers[1] = nullptr;
}

patient::patient(const QString& first, const QString& last, const QString& dob , const QString user , const QString pass)
    : firstname(first), lastname(last), username(user), password(pass),
    dateOfBirth(dob), age(0), weight_kg(0), weight_lb(0),
    height(""), bloodGroup(""), gender(""), contactInfo("")
{
    caretakers[0] = caretakers[1] = nullptr;
}

// Destructor
patient::~patient() {
    for (int i = 0; i < 2; i++) {
        if (caretakers[i] != nullptr) {
            caretakers[i]->removepatient();
        }
    }
}

// Medicine management
void patient::addMedicineToDay(const QString& medName, const QString& dose,
                               const QString& time, const QString& date, const QString& dayOfWeek) {
    Day newDay(date, dayOfWeek);
    Medicine med(medName, dose, time);
    newDay.addMedicine(med);
    medicationSchedule.enqueue(newDay);
}

// Appointment management
void patient::addAppointment(const QString& date, const QString& time,
                             const QString& doctor, const QString& purpose) {
    Appointment app(date, time, doctor, purpose);
    appointmentList.enqueue(app);
}

// Caretaker management
void patient::assignCaretaker(Caretaker* ct, int index) {
    if (index >= 0 && index < 2) {
        caretakers[index] = ct;
        if (ct != nullptr) {
            ct->add_patient(this);
        }
    }
}

void patient::removeCaretaker(int index) {
    if (index >= 0 && index < 2 && caretakers[index] != nullptr) {
        caretakers[index]->removepatient();
        caretakers[index] = nullptr;
    }
}

QString patient::getFirstname() const { return firstname; }


QString patient::getLastname() const { return lastname; }

QString patient::getUsername() const { return username; }

QString patient::getPassword() const { return password; }

QString patient::getName() const { return firstname + " " + lastname; }

QString patient::getDateOfBirth() const { return dateOfBirth; }

int patient::getAge() const { return age; }
double patient::getWeightKg() const { return weight_kg; }

double patient::getWeightLb() const { return weight_lb; }

QString patient::getHeight() const { return height; }

QString patient::getBloodGroup() const { return bloodGroup; }

QString patient::getGender() const { return gender; }

QString patient::getContactInfo() const { return contactInfo; }


void patient::setFirstname(const QString& first) { firstname = first; }

void patient::setLastname(const QString& last) { lastname = last; }

void patient::setUsername(const QString& user) { username = user; }

void patient::setPassword(const QString& pass) { password = pass; }

void patient::setDateOfBirth(const QString& dob) { dateOfBirth = dob; }

void patient::setAge(int a) { age = a; }

void patient::setWeightKg(double w_kg) {
    weight_kg = w_kg;
    weight_lb = w_kg * 2.20462;
}

void patient::setHeight(const QString& h) { height = h; }

void patient::setBloodGroup(const QString& bg) { bloodGroup = bg; }

void patient::setGender(const QString& g) { gender = g; }

void patient::setContactInfo(const QString& contact) { contactInfo = contact; }

QString patient::getMedicationScheduleAsString() const {
    if (medicationSchedule.isEmpty()) return "No medication schedule";

    queue<Day> temp = medicationSchedule.copy();
    QStringList schedule;
    while (!temp.isEmpty()) {
        Day day = temp.dequeue();
        schedule << day.getDayOfWeek() + " (" + day.getDate() + "): " + day.getMedicinesAsString();
    }
    return schedule.join("\n");
}

QString patient::getAppointmentsAsString() const {
    if (appointmentList.isEmpty()) return "No appointments";

    queue<Appointment> temp = appointmentList.copy();
    QStringList appointments;
    while (!temp.isEmpty()) {
        appointments << temp.dequeue().toString();
    }
    return appointments.join("\n");
}

QString patient::getCaretakersAsString() const {
    QStringList ctList;
    for (int i = 0; i < 2; i++) {
        if (caretakers[i] != nullptr) {
            ctList << caretakers[i]->toString();
        }
    }
    return ctList.isEmpty() ? "No caretakers assigned" : ctList.join("\n");
}

QString patient::toString() const {
    return "Patient: " + getName() + " (" + QString::number(age) + " years) - " + contactInfo;
}
