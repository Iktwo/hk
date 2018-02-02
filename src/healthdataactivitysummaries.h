#ifndef HEALTHDATAACTIVITYSUMMARIES_H
#define HEALTHDATAACTIVITYSUMMARIES_H

#include <QAbstractListModel>
#include <QList>

#include "healthdataactivitysummary.h"

class HealthDataActivitySummaries : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit HealthDataActivitySummaries(QObject *parent = nullptr);

    enum Roles {
        dateRole = Qt::UserRole +1,
        energyBurnedRole,
        energyBurnedUnitRole,
        exerciseRole,
        standHoursRole
    };

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void addSummary(HealthDataActivitySummary * summary);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<HealthDataActivitySummary *> m_summaries;
};

#endif // HEALTHDATAACTIVITYSUMMARIES_H
