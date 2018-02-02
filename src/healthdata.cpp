#include "healthdata.h"

#include <QDebug>
#include <QFile>
#include <QUrl>
#include <QXmlStreamReader>

const QString HealthData::ExportDate = "ExportDate";
const QString HealthData::Me = "Me";
const QString HealthData::Workout = "Workout";
const QString HealthData::Summary = "ActivitySummary";

HealthData::HealthData(QObject *parent) : QObject(parent), m_date(QDateTime::currentDateTime())
{
    me_irl = new HealthDataMe(this);
    m_workouts = new HealthDataWorkouts(this);
    m_summaries = new HealthDataActivitySummaries(this);
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
                    QXmlStreamAttributes attrib = xml.attributes();

                    HealthDataWorkout *workout = new HealthDataWorkout(this);
                    workout->setActivityType(HealthDataWorkout::stringToActivityType(attrib.value("workoutActivityType").toString()));

                    QDateTime date = QDateTime::fromString(attrib.value("startDate").toString().left(19), "yyyy-MM-dd hh:mm:ss");
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
                    workout->setStartDate(date);

                    addWorkout(workout);
                } else if (xml.name() == Summary) {
                    QXmlStreamAttributes attrib = xml.attributes();

                    HealthDataActivitySummary *summary = new HealthDataActivitySummary(this);

                    QDate date = QDate::fromString(attrib.value("dateComponents").toString(), "yyyy-MM-dd");

                    if (date < me_irl->dateOfBirth()) {
                        continue;
                    }

                    int exercise = attrib.value("appleExerciseTime").toInt();

                    int standHours = attrib.value("appleStandHours").toInt();

                    double energyBurned = attrib.value("activeEnergyBurned").toDouble();

                    QString energyBurnedUnit = attrib.value("activeEnergyBurnedUnit").toString();


                    summary->setDate(date);

                    summary->setExercise(exercise);

                    summary->setStandHours(standHours);

                    summary->setEnergyBurned(energyBurned);

                    summary->setEnergyBurnedUnit(energyBurnedUnit);

                    addSummary(summary);
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

HealthDataActivitySummaries *HealthData::summaries() const
{
    return m_summaries;
}

void HealthData::addSummary(HealthDataActivitySummary *summary)
{
    m_summaries->addSummary(summary);
}

