#ifndef HEALTHDATAWORKOUTS_H
#define HEALTHDATAWORKOUTS_H

#include <QAbstractListModel>
#include <QList>

#include "healthdataworkout.h"

class HealthDataWorkouts : public QAbstractListModel
{
     Q_OBJECT

public:
    explicit HealthDataWorkouts(QObject *parent = 0);

    enum Roles {
        activityTypeRole = Qt::UserRole +1,
        durationRole,
        durationUnitRole,
        distanceRole,
        distanceUnitRole,
        energyBurnedRole,
        energyBurnedUnitRole,
        startDateRole
    };

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void addWorkout(HealthDataWorkout * workout);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<HealthDataWorkout *> m_workouts;
};

#endif // HEALTHDATAWORKOUTS_H
