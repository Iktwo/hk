#include "healthdata.h"

#include <QDebug>
#include <QFile>
#include <QUrl>
#include <QXmlStreamReader>

const QString HealthData::ExportDate = "ExportDate";
const QString HealthData::Me = "Me";
const QString HealthData::Workout = "Workout";

HealthData::HealthData(QObject *parent) : QObject(parent), m_date(QDateTime::currentDateTime())
{
    me_irl = new HealthDataMe(this);
    m_workouts = new HealthDataWorkouts(this);
}

void HealthData::open(const QUrl &fileUrl)
{
    if (fileUrl.isLocalFile()) {
        QFile file(fileUrl.path());

        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            qDebug() << "Cannot read file" << file.errorString();
            emit errorOpeningFile();
            return;
        }

        QXmlStreamReader xml(&file);

        while (!xml.atEnd()) {
            xml.readNextStartElement();

            if (xml.isStartElement()) {
                if (xml.name() == ExportDate) {
                    QString dateFormat("yyyy-MM-dd HH:mm:ss");
                    m_date = QDateTime::fromString(xml.attributes().value("value").toString().left(dateFormat.length()), dateFormat);
                    emit dateChanged();
                } else if (xml.name() == Me) {
                    QXmlStreamAttributes attrib = xml.attributes();

                    me_irl->setDateOfBirth(QDate::fromString(attrib.value("HKCharacteristicTypeIdentifierDateOfBirth").toString(), "yyyy-MM-dd"));
                    me_irl->setBiologicalSex(HealthDataMe::stringToBiologicalSex(attrib.value("HKCharacteristicTypeIdentifierBiologicalSex").toString()));
                    me_irl->setBloodType(HealthDataMe::stringToBloodType(attrib.value("HKCharacteristicTypeIdentifierBloodType").toString()));
                    me_irl->setFitzpatrickSkingType(HealthDataMe::stringToFitzpatrickSkinType(attrib.value("HKCharacteristicTypeIdentifierFitzpatrickSkinType").toString()));
                } else if (xml.name() == Workout) {
                    qDebug() << "workout value";

                    QXmlStreamAttributes attrib = xml.attributes();

                    HealthDataWorkout *workout = new HealthDataWorkout(this);
                    workout->setActivityType(HealthDataWorkout::stringToActivityType(attrib.value("workoutActivityType").toString()));

                    double duration = attrib.value("duration").toDouble();
                    double distance = attrib.value("totalDistance").toDouble();
                    double energyBurned = attrib.value("totalEnergyBurned").toDouble();
                    QString durationUnit = attrib.value("durationUnit").toString();
                    QString distanceUnit = attrib.value("totalDistanceUnit").toString();
                    QString energyBurnedUnit = attrib.value("totalEnergyBurnedUnit").toString();

                    workout->setDuration(duration);
                    workout->setDurationUnit(durationUnit);
                    workout->setDistance(distance);
                    workout->setDistanceUnit(distanceUnit);
                    workout->setEnergyBurned(energyBurned);
                    workout->setEnergyBurnedUnit(energyBurnedUnit);

                    addWorkout(workout);
                } else {
                    qDebug() << "NAME" << xml.name();
                    qDebug() << "TEXT" << xml.text();
                    qDebug() << "TOKEN" << xml.tokenString();
                    QXmlStreamAttributes attrib = xml.attributes();

                    for (int j = 0; j < attrib.size(); ++j) {
                        qDebug() << "VALUE" << attrib.at(j).name() << attrib.at(j).value();
                    }
                }
            }
        }
    }
}

QDateTime HealthData::date() const
{
    return m_date;
}

HealthDataMe * HealthData::me() const
{
    return me_irl;
}

HealthDataWorkouts * HealthData::workouts() const
{
    return m_workouts;
}

void HealthData::addWorkout(HealthDataWorkout *workout)
{
    m_workouts->addWorkout(workout);
}

