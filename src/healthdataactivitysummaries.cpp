#include "healthdataactivitysummaries.h"

#include <QDebug>

HealthDataActivitySummaries::HealthDataActivitySummaries(QObject *parent) : QAbstractListModel(parent)
{

}

int HealthDataActivitySummaries::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_summaries.count();
}

QVariant HealthDataActivitySummaries::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_summaries.count())
        return QVariant();

    switch (role) {
    case dateRole:
        return qobject_cast<HealthDataActivitySummary*>(m_summaries.at(index.row()))->date();
        break;
    case energyBurnedRole:
        return qobject_cast<HealthDataActivitySummary*>(m_summaries.at(index.row()))->energyBurned();
        break;
    case energyBurnedUnitRole:
        return qobject_cast<HealthDataActivitySummary*>(m_summaries.at(index.row()))->energyBurnedUnit();
        break;
    case exerciseRole:
        return qobject_cast<HealthDataActivitySummary*>(m_summaries.at(index.row()))->exercise();
        break;
    case standHoursRole:
        return qobject_cast<HealthDataActivitySummary*>(m_summaries.at(index.row()))->standHours();
        break;
    }
    return QVariant();
}

void HealthDataActivitySummaries::addSummary(HealthDataActivitySummary *summary)
{
    beginInsertRows(QModelIndex(), m_summaries.count(), m_summaries.count());
    m_summaries.append(summary);
    endInsertRows();

    QModelIndex top = createIndex(m_summaries.count() - 1, 0);
    QModelIndex bottom = createIndex(m_summaries.count() - 1, 0);

    emit dataChanged(top, bottom);
}

QHash<int, QByteArray> HealthDataActivitySummaries::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[dateRole] = "date";
    roles[energyBurnedRole] = "energyBurned";
    roles[energyBurnedUnitRole] = "energyBurnedUnit";
    roles[exerciseRole] = "exercise";
    roles[standHoursRole] = "standHours";
    return roles;
}
