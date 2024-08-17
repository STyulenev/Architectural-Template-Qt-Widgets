#include "LanguageViewModel.h"

namespace ATQW::ViewModels {

struct LanguageModel
{
    int id;
    QString name;
    QString code;
};

LanguageViewModel::LanguageViewModel(QObject* parent) :
    QAbstractListModel(parent)
{
    m_model = {
        { 1, tr("Русский"),    "ru_RU" },
        { 2, tr("Английский"), "en_EN" }
    };
}

LanguageViewModel::~LanguageViewModel()
{

}

auto LanguageViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return m_model.count();
}

auto LanguageViewModel::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::DisplayRole:
        return m_model.at(index.row()).name;
    case Qt::UserRole: // not use right now
        return m_model.at(index.row()).id;
    default:
        break;
    }

    return QVariant();
}

auto LanguageViewModel::getCodeForIndex(int index) -> QString
{
    return m_model.at(index).code;
}

} // namespace ATQW::ViewModels
