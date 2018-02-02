#ifndef HEALTHDATAACTIVITYSUMMARY_H
#define HEALTHDATAACTIVITYSUMMARY_H

#include <QObject>
#include <QDate>

class HealthDataActivitySummary : public QObject
{
    Q_OBJECT

public:
    explicit HealthDataActivitySummary(QObject *parent = nullptr);

    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(double energyBurned READ energyBurned WRITE setEnergyBurned NOTIFY energyBurnedChanged)
    Q_PROPERTY(QString energyBurnedUnit READ energyBurnedUnit WRITE setEnergyBurnedUnit NOTIFY energyBurnedUnitChanged)
    Q_PROPERTY(int exercise READ exercise WRITE setExercise NOTIFY exerciseChanged)
    Q_PROPERTY(int standHours READ standHours WRITE setStandHours NOTIFY standHoursChanged)

    QDate date() const;
    double energyBurned() const;
    QString energyBurnedUnit() const;
    int exercise() const;
    int standHours() const;

signals:
    void dateChanged(QDate date);
    void energyBurnedChanged(double energyBurned);
    void energyBurnedUnitChanged(QString energyBurnedUnit);
    void exerciseChanged(int exercise);
    void standHoursChanged(int standHours);

public slots:
    void setDate(QDate date);
    void setEnergyBurned(double energyBurned);
    void setEnergyBurnedUnit(QString energyBurnedUnit);
    void setExercise(int exercise);
    void setStandHours(int standHours);

private:
    QDate m_date;
    double m_energyBurned;
    QString m_energyBurnedUnit;
    int m_exercise;
    int m_standHours;
};

#endif // HEALTHDATAACTIVITYSUMMARY_H
