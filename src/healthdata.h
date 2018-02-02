#ifndef HEALTHDATA_H
#define HEALTHDATA_H

#include <QObject>
#include <QDateTime>

#include "healthdatame.h"
#include "healthdataworkout.h"
#include "healthdataworkouts.h"
#include "healthdataactivitysummary.h"
#include "healthdataactivitysummaries.h"

class QURL;
class QFile;

class HealthData : public QObject
{
    Q_OBJECT
public:
    explicit HealthData(QObject *parent = nullptr);

    enum class HealthDataType {
        ExportDate,
        Me,
        Workout,
        Summary
    };

    Q_ENUM(HealthDataType)

    Q_PROPERTY(QDateTime date READ date NOTIFY dateChanged)
    Q_PROPERTY(HealthDataMe * me READ me NOTIFY meChanged)
    Q_PROPERTY(HealthDataWorkouts * workouts READ workouts NOTIFY workoutsChanged)
    Q_PROPERTY(HealthDataActivitySummaries * summaries READ summaries NOTIFY summariesChanged)

    Q_INVOKABLE void open(const QUrl &fileUrl);

    static const QString ExportDate;
    static const QString Me;
    static const QString Workout;
    static const QString Summary;

    QDateTime date() const;
    HealthDataMe * me() const;

    HealthDataWorkouts * workouts() const;

    void addWorkout(HealthDataWorkout *workout);

    HealthDataActivitySummaries * summaries() const;

    void addSummary(HealthDataActivitySummary *summary);

signals:
    void errorOpeningFile();
    void dateChanged();
    void meChanged();
    void workoutsChanged();
    void summariesChanged();

private:
    QDateTime m_date;
    HealthDataMe * me_irl;
    HealthDataWorkouts * m_workouts;
    HealthDataActivitySummaries * m_summaries;
};

#endif // HEALTHDATA_H
