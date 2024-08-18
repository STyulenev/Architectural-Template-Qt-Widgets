#include "ThemeViewModel.h"

namespace ATQW::ViewModels {

struct ThemeModel
{
    int id;
    QString name;
};

ThemeViewModel::ThemeViewModel(QObject* parent) :
    QAbstractListModel(parent)
{
    m_model = {
        { 1, tr("Тёмная"),  },
        { 2, tr("Светлая"), }
    };
}

ThemeViewModel::~ThemeViewModel()
{

}

auto ThemeViewModel::rowCount([[maybe_unused]] const QModelIndex& index) const -> int
{
    return m_model.count();
}

auto ThemeViewModel::data(const QModelIndex& index, int role) const -> QVariant
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

auto ThemeViewModel::getCodeForIndex(int index) -> int
{
    return m_model.at(index).id;
}

} // namespace ATQW::ViewModels
