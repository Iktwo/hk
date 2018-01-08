#include "healthdataworkouts.h"

HealthDataWorkouts::HealthDataWorkouts(QObject *parent) :
    QAbstractListModel(parent)
{

}

int HealthDataWorkouts::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_workouts.count();
}

QVariant HealthDataWorkouts::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_workouts.count())
        return QVariant();

    switch (role) {
    case activityTypeRole:
        return int(qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->activityType());
        break;
    case durationRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->duration();
        break;
    case durationUnitRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->durationUnit();
        break;
    case distanceRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->distance();
        break;
    case distanceUnitRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->distanceUnit();
        break;
    case energyBurnedRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->energyBurned();
        break;
    case energyBurnedUnitRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->energyBurnedUnit();
        break;
    case startDateRole:
        return qobject_cast<HealthDataWorkout*>(m_workouts.at(index.row()))->startDate();
        break;
    }
    return QVariant();
}

void HealthDataWorkouts::addWorkout(HealthDataWorkout *workout)
{
    beginInsertRows(QModelIndex(), m_workouts.count(), m_workouts.count());
    m_workouts.append(workout);
    endInsertRows();

    QModelIndex top = createIndex(m_workouts.count() - 1, 0);
    QModelIndex bottom = createIndex(m_workouts.count() - 1, 0);

    emit dataChanged(top, bottom);
}

QHash<int, QByteArray> HealthDataWorkouts::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[activityTypeRole] = "activityType";
    roles[durationRole] = "duration";
    roles[durationUnitRole] = "durationUnit";
    roles[distanceRole] = "distance";
    roles[distanceUnitRole] = "distanceUnit";
    roles[energyBurnedRole] = "energyBurned";
    roles[energyBurnedUnitRole] = "energyBurnedUnit";
    roles[startDateRole] = "startDate";
    return roles;
}
