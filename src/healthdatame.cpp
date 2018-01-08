#include "healthdatame.h"

HealthDataMe::HealthDataBloodType HealthDataMe::stringToBloodType(const QString &string)
{
    if (string == "HKBloodTypeAPositive") {
        return HealthDataBloodType::APositive;
    } else if (string == "HKBloodTypeANegative") {
        return HealthDataBloodType::ANegative;
    } else if (string == "HKBloodTypeBPositive") {
        return HealthDataBloodType::BPositive;
    } else if (string == "HKBloodTypeBNegative") {
        return HealthDataBloodType::BNegative;
    } else if (string == "HKBloodTypeABPositive") {
        return HealthDataBloodType::ABPositive;
    } else if (string == "HKBloodTypeABNegative") {
        return HealthDataBloodType::ABNegative;
    } else if (string == "HKBloodTypeOPositive") {
        return HealthDataBloodType::OPositive;
    } else if (string == "HKBloodTypeONegative") {
        return HealthDataBloodType::ONegative;
    } else {
        return HealthDataBloodType::NotSet;
    }
}

HealthDataMe::HealthDataBiologicalSex HealthDataMe::stringToBiologicalSex(const QString &string)
{
    if (string == "HKBiologicalSexFemale") {
        return HealthDataBiologicalSex::Female;
    } else if (string == "HKBiologicalSexMale") {
        return HealthDataBiologicalSex::Male;
    } else if (string == "HKBiologicalSexOther") {
        return HealthDataBiologicalSex::Other;
    } else {
        return HealthDataBiologicalSex::NotSet;
    }
}

HealthDataMe::HealthDataFitzpatrickSkinType HealthDataMe::stringToFitzpatrickSkinType(const QString &string)
{
    if (string == "HKFitzpatrickSkinTypeI") {
        return HealthDataFitzpatrickSkinType::I;
    } else if (string == "HKFitzpatrickSkinTypeII") {
        return HealthDataFitzpatrickSkinType::II;
    } else if (string == "HKFitzpatrickSkinTypeIII") {
        return HealthDataFitzpatrickSkinType::III;
    } else if (string == "HKFitzpatrickSkinTypeIV") {
        return HealthDataFitzpatrickSkinType::IV;
    } else if (string == "HKFitzpatrickSkinTypeV") {
        return HealthDataFitzpatrickSkinType::V;
    } else if (string == "HKFitzpatrickSkinTypeVI") {
        return HealthDataFitzpatrickSkinType::VI;
    } else {
        return HealthDataFitzpatrickSkinType::NotSet;
    }
}

HealthDataMe::HealthDataMe(QObject *parent) : QObject(parent),
    m_dateOfBirth(QDate::currentDate()),
    m_biologicalSex(HealthDataBiologicalSex::NotSet),
    m_bloodType(HealthDataBloodType::NotSet),
    m_fitzpatrickSkinType(HealthDataFitzpatrickSkinType::NotSet)
{
}

HealthDataMe::HealthDataMe(QObject *parent, QDate dateOfBirth, HealthDataMe::HealthDataBiologicalSex biologicalSex,
                           HealthDataMe::HealthDataBloodType bloodType, HealthDataMe::HealthDataFitzpatrickSkinType fitzpatrickSkinType) : QObject(parent),
    m_dateOfBirth(dateOfBirth),
    m_biologicalSex(biologicalSex),
    m_bloodType(bloodType),
    m_fitzpatrickSkinType(fitzpatrickSkinType)
{
}

QDate HealthDataMe::dateOfBirth()
{
    return m_dateOfBirth;
}

HealthDataMe::HealthDataBiologicalSex HealthDataMe::biologicalSex()
{
    return m_biologicalSex;
}

HealthDataMe::HealthDataBloodType HealthDataMe::bloodType()
{
    return m_bloodType;
}

HealthDataMe::HealthDataFitzpatrickSkinType HealthDataMe::fitzpatrickSkinType()
{
    return m_fitzpatrickSkinType;
}

void HealthDataMe::setDateOfBirth(QDate date)
{
    m_dateOfBirth = date;
    emit dateOfBirthChanged();
}

void HealthDataMe::setBiologicalSex(HealthDataMe::HealthDataBiologicalSex biologicalSex)
{
    m_biologicalSex = biologicalSex;
    emit biologicalSexChanged();
}

void HealthDataMe::setBloodType(HealthDataMe::HealthDataBloodType bloodType)
{
    m_bloodType = bloodType;
    bloodTypeChanged();
}

void HealthDataMe::setFitzpatrickSkingType(HealthDataMe::HealthDataFitzpatrickSkinType fitzpatrickSkinType)
{
    m_fitzpatrickSkinType = fitzpatrickSkinType;
    fitzpatrickSkinTypeChanged();
}
