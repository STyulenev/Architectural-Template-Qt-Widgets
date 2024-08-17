#pragma once

#include <QAbstractListModel>

namespace ATQW::ViewModels {

struct LanguageModel;

class LanguageViewModel : public QAbstractListModel 
{
    Q_OBJECT

public:
    LanguageViewModel(QObject* parent = nullptr);
    ~LanguageViewModel();

    auto rowCount(const QModelIndex& index) const -> int override;
    auto data(const QModelIndex& index, int role) const -> QVariant override;

    auto getCodeForIndex(int index) -> QString;

private:
    QVector<LanguageModel> m_model;

};

} // namespace ATQW::ViewModels
