#include "healthdataworkout.h"

HealthDataWorkout::HealthDataWorkout(QObject *parent) : QObject(parent), m_duration(0)
{
}

HealthDataWorkout::HealthDataActivityType HealthDataWorkout::stringToActivityType(const QString &string)
{
    if (string == "HKWorkoutActivityTypeWalking") {
        return HealthDataActivityType::Walking;
    } else if (string == "HKWorkoutActivityTypeCycling") {
        return HealthDataActivityType::Cycling;
    } else if (string == "HKWorkoutActivityTypeRunning") {
        return HealthDataActivityType::Running;
    } else if (string == "HKWorkoutActivityTypeSoccer") {
        return HealthDataActivityType::Soccer;
    } else if (string == "HKWorkoutActivityTypeHighIntensityIntervalTraining") {
        return HealthDataActivityType::HighIntensityIntervalTraining;
    } else if (string == "HKWorkoutActivityTypeSwimming") {
        return HealthDataActivityType::Swimming;
    } else if (string == "HKWorkoutActivityTypeRowing") {
        return HealthDataActivityType::Rowing;
    } else {
        return HealthDataActivityType::Other;
    }
}

HealthDataWorkout::HealthDataActivityType HealthDataWorkout::activityType() const
{
    return m_activityType;
}

double HealthDataWorkout::duration() const
{
    return m_duration;
}

double HealthDataWorkout::distance() const
{
    return m_distance;
}

double HealthDataWorkout::energyBurned() const
{
    return m_energyBurned;
}

void HealthDataWorkout::setActivityType(HealthDataWorkout::HealthDataActivityType activityType)
{
    m_activityType = activityType;
    emit activityTypeChanged();
}

void HealthDataWorkout::setDuration(double duration)
{
    m_duration = duration;
    emit durationChanged();
}

void HealthDataWorkout::setDistance(double distance)
{
    m_distance = distance;
    emit distanceChanged();
}

void HealthDataWorkout::setEnergyBurned(double energyBurned)
{
    m_energyBurned = energyBurned;
    emit energyBurnedChanged();
}

QDate HealthDataWorkout::startDate() const
{
    return m_startDate;
}

void HealthDataWorkout::setStartDate(QDate startDate)
{
    m_startDate = startDate;
    emit startDateChanged();
}

QString HealthDataWorkout::durationUnit() const
{
    return m_durationUnit;
}

QString HealthDataWorkout::distanceUnit() const
{
    return m_distanceUnit;
}

QString HealthDataWorkout::energyBurnedUnit() const
{
    return m_energyBurnedUnit;
}

void HealthDataWorkout::setDurationUnit(QString durationUnit)
{
    if (m_durationUnit == durationUnit)
        return;

    m_durationUnit = durationUnit;
    emit durationUnitChanged();
}

void HealthDataWorkout::setDistanceUnit(QString distanceUnit)
{
    if (m_distanceUnit == distanceUnit)
        return;

    m_distanceUnit = distanceUnit;
    emit distanceUnitChanged();
}

void HealthDataWorkout::setEnergyBurnedUnit(QString energyBurnedUnit)
{
    if (m_energyBurnedUnit == energyBurnedUnit)
        return;

    m_energyBurnedUnit = energyBurnedUnit;
    emit energyBurnedUnitChanged();
}
