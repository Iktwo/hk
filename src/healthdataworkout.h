#ifndef HEALTHDATAWORKOUT_H
#define HEALTHDATAWORKOUT_H

#include <QObject>
#include <QDate>

class HealthDataWorkout : public QObject
{
    Q_OBJECT
public:
    explicit HealthDataWorkout(QObject *parent = nullptr);

    Q_PROPERTY(HealthDataActivityType activityType READ activityType NOTIFY activityTypeChanged)
    Q_PROPERTY(double duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(QString durationUnit READ durationUnit WRITE setDurationUnit NOTIFY durationUnitChanged)
    Q_PROPERTY(double distance READ distance NOTIFY distanceChanged)
    Q_PROPERTY(QString distanceUnit READ distanceUnit WRITE setDistanceUnit NOTIFY distanceUnitChanged)
    Q_PROPERTY(double energyBurned READ energyBurned NOTIFY energyBurnedChanged)
    Q_PROPERTY(QString energyBurnedUnit READ energyBurnedUnit WRITE setEnergyBurnedUnit NOTIFY energyBurnedUnitChanged)
    Q_PROPERTY(QDate startDate READ startDate NOTIFY startDateChanged)

    enum class HealthDataActivityType {
        Other,
        Walking,
        Cycling,
        Running,
        Soccer,
        HighIntensityIntervalTraining,
        Swimming,
        Rowing
    };


    Q_ENUM(HealthDataActivityType)

    static HealthDataActivityType stringToActivityType(const QString & string);

    HealthDataActivityType activityType() const;
    double duration() const;
    QString durationUnit() const;
    double distance() const;
    QString distanceUnit() const;
    double energyBurned() const;
    QString energyBurnedUnit() const;
    QDate startDate() const;

    void setActivityType(HealthDataActivityType activityType);
    void setDuration(double duration);
    void setDistance(double distance);
    void setEnergyBurned(double energyBurned);
    void setStartDate(QDate startDate);
    void setDurationUnit(QString durationUnit);
    void setDistanceUnit(QString distanceUnit);
    void setEnergyBurnedUnit(QString energyBurnedUnit);

signals:
    void activityTypeChanged();
    void durationChanged();
    void durationUnitChanged();
    void distanceChanged();
    void distanceUnitChanged();
    void energyBurnedChanged();
    void energyBurnedUnitChanged();
    void startDateChanged();

private:
    HealthDataActivityType m_activityType;
    double m_duration;
    double m_distance;
    double m_energyBurned;
    QDate m_startDate;
    QString m_durationUnit;
    QString m_distanceUnit;
    QString m_energyBurnedUnit;
};

#endif // HEALTHDATAWORKOUT_H
