#include "healthdataactivitysummary.h"

HealthDataActivitySummary::HealthDataActivitySummary(QObject *parent) : QObject(parent), m_date(QDate::currentDate())
{

}

QDate HealthDataActivitySummary::date() const
{
    return m_date;
}

double HealthDataActivitySummary::energyBurned() const
{
    return m_energyBurned;
}

QString HealthDataActivitySummary::energyBurnedUnit() const
{
    return m_energyBurnedUnit;
}

int HealthDataActivitySummary::exercise() const
{
    return m_exercise;
}

int HealthDataActivitySummary::standHours() const
{
    return m_standHours;
}

void HealthDataActivitySummary::setDate(QDate date)
{
    if (m_date == date)
        return;

    m_date = date;
    emit dateChanged(m_date);
}

void HealthDataActivitySummary::setEnergyBurned(double energyBurned)
{
    if (m_energyBurned == energyBurned)
        return;

    m_energyBurned = energyBurned;
    emit energyBurnedChanged(m_energyBurned);
}

void HealthDataActivitySummary::setEnergyBurnedUnit(QString energyBurnedUnit)
{
    if (m_energyBurnedUnit == energyBurnedUnit)
        return;

    m_energyBurnedUnit = energyBurnedUnit;
    emit energyBurnedUnitChanged(m_energyBurnedUnit);
}

void HealthDataActivitySummary::setExercise(int exercise)
{
    if (m_exercise == exercise)
        return;

    m_exercise = exercise;
    emit exerciseChanged(m_exercise);
}

void HealthDataActivitySummary::setStandHours(int standHours)
{
    if (m_standHours == standHours)
        return;

    m_standHours = standHours;
    emit standHoursChanged(m_standHours);
}
