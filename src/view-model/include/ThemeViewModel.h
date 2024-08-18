#pragma once

#include <QAbstractListModel>

namespace ATQW::ViewModels {

struct ThemeModel;

class ThemeViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ThemeViewModel(QObject* parent = nullptr);
    ~ThemeViewModel();

    auto rowCount(const QModelIndex& index) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;

    auto getCodeForIndex(int index) -> int;

private:
    QVector<ThemeModel> m_model;

};

} // namespace ATQW::ViewModels
