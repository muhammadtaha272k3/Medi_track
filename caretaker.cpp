#include "caretaker.h"
#include "patient.h"
#include <QString>
#include <QMessageBox>


Caretaker::Caretaker(const QString& n, const QString& c)
    : name(n), contactinfo(c)  {
    for(int i = 0 ; i < 3 ; i++){
        assignedPatients[i] = nullptr;
    }
}

void Caretaker::add_patient(patient* p) {
    int i = 0;
    while(i < 3 && assignedPatients[i] != nullptr) {
        i++;
    }
    if (i < 3) {
        assignedPatients[i] = p;
    } else {
        QMessageBox::warning(nullptr, "Error", "No available slots for new patient!");
    }
}
void Caretaker::removepatient(const QString& p) {
    bool found = false;
    for(int i = 0; i < 3; i++) {
        if(assignedPatients[i] != nullptr && assignedPatients[i]->getName() == p) {
            assignedPatients[i] = nullptr;
            int j = i;
            while(j < 2 && assignedPatients[j + 1] != nullptr) {
                assignedPatients[j] = assignedPatients[j + 1];
                j++;
            }
            assignedPatients[j] = nullptr;
            found = true;
            break;
        }
    }
    if(!found){
        QMessageBox::warning(nullptr,"error","no patient found of the name");
    }
}

void Caretaker ::removepatient(){
    for (int i = 0 ; i < 3 ; i++ ){

    }
}

QString Caretaker::getname() const { return name; }
QString Caretaker::getcontact_info() const { return contactinfo; }


QString Caretaker::toString() const {
    return name + " - " + contactinfo;
}
