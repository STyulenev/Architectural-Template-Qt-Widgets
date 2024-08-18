#pragma once

#include <QObject>

namespace ATQW::Controllers {

class LoggingController final
{
private:
    static LoggingController* self;

    explicit LoggingController();
    ~LoggingController();

public:
    LoggingController(const LoggingController&) = delete;
    LoggingController& operator=(LoggingController&) = delete;
    LoggingController(const LoggingController&&) = delete;
    LoggingController&& operator=(LoggingController&&) = delete;

    static LoggingController* instance();
    static auto myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& messageText) -> void;

    auto setDebugMessageHandler() -> void;

private:
    auto printToLogFile(const QString& messageText) -> void;
    auto clearLogFile() -> void;

    QString m_logFileName;

};

} // namespace ATQW::Controllers
