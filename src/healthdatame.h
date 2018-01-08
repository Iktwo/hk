#ifndef HEALTHDATAME_H
#define HEALTHDATAME_H

#include <QObject>
#include <QDate>

class HealthDataMe : public QObject
{
    Q_OBJECT
public:
    explicit HealthDataMe(QObject *parent = nullptr);

    enum class HealthDataBiologicalSex {
        NotSet,
        Female,
        Male,
        Other
    };

    enum class HealthDataBloodType {
        NotSet,
        APositive,
        ANegative,
        BPositive,
        BNegative,
        ABPositive,
        ABNegative,
        OPositive,
        ONegative
    };

    enum class HealthDataFitzpatrickSkinType {
        NotSet,
        I,
        II,
        III,
        IV,
        V,
        VI
    };


    Q_ENUM(HealthDataBiologicalSex)
    Q_ENUM(HealthDataBloodType)
    Q_ENUM(HealthDataFitzpatrickSkinType)

    HealthDataMe(QObject *parent, QDate dateOfBirth,
                 HealthDataBiologicalSex biologicalSex,
                 HealthDataBloodType bloodType,
                 HealthDataFitzpatrickSkinType fitzpatrickSkinType);

    Q_PROPERTY(QDate dateOfBirth READ dateOfBirth NOTIFY dateOfBirthChanged)
    Q_PROPERTY(HealthDataBiologicalSex biologicalSex READ biologicalSex NOTIFY biologicalSexChanged)
    Q_PROPERTY(HealthDataBloodType bloodType READ bloodType NOTIFY bloodTypeChanged)
    Q_PROPERTY(HealthDataFitzpatrickSkinType fitzpatrickSkinType READ fitzpatrickSkinType NOTIFY fitzpatrickSkinTypeChanged)

    static HealthDataBiologicalSex stringToBiologicalSex(const QString &string);
    static HealthDataBloodType stringToBloodType(const QString &string);
    static HealthDataFitzpatrickSkinType stringToFitzpatrickSkinType(const QString &string);

    QDate dateOfBirth();
    HealthDataBiologicalSex biologicalSex();
    HealthDataBloodType bloodType();
    HealthDataFitzpatrickSkinType fitzpatrickSkinType();

    void setDateOfBirth(QDate date);
    void setBiologicalSex(HealthDataBiologicalSex biologicalSex);
    void setBloodType(HealthDataBloodType bloodType);
    void setFitzpatrickSkingType(HealthDataFitzpatrickSkinType fitzpatrickSkinType);

signals:
    void dateOfBirthChanged();
    void biologicalSexChanged();
    void bloodTypeChanged();
    void fitzpatrickSkinTypeChanged();

private:
    QDate m_dateOfBirth;
    HealthDataBiologicalSex m_biologicalSex;
    HealthDataBloodType m_bloodType;
    HealthDataFitzpatrickSkinType m_fitzpatrickSkinType;
};

#endif // HEALTHDATAME_H
