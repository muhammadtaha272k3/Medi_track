#ifndef MEDICINE_H
#define MEDICINE_H

#include <QString>

class Medicine {
private:
    QString name;
    QString dosage;
    QString time;
    bool taken;

public:
    Medicine();
    Medicine(const QString& n, const QString& d, const QString& t);

    // Getters
    QString getName() const;
    QString getDosage() const;
    QString getTime() const;
    bool gettake() const;

    // Setters
    void setName(const QString& name);
    void setDosage(const QString& dosage);
    void setTime(const QString& time);
    bool settake(const bool& check);
    QString toString() const;
};

#endif // MEDICINE_H
