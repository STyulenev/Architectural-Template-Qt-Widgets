#include <LoggingController.h>

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QTime>

namespace ATQW::Controllers {

LoggingController* LoggingController::self = 0;

LoggingController::LoggingController()
{
    // Если требуется очищать файл
    //clearLogFile();
}

LoggingController::~LoggingController()
{

}

LoggingController* LoggingController::instance()
{
    if (!self) {
        self = new LoggingController();
    }

    return self;
}

auto LoggingController::clearLogFile() -> void
{
    FILE* logFile = fopen(qPrintable(m_logFileName), "w+");

    if (!logFile) {
        fclose(logFile);
    }
}

auto LoggingController::printToLogFile(const QString& messageText) -> void
{
    FILE* logFile = fopen(qPrintable(m_logFileName), "a+");

    if (!logFile) {
        printf("Log %s file not writable\n", qPrintable(m_logFileName));
        return;
    }

    fprintf(logFile, "%s", qPrintable(messageText));
    fclose(logFile);
}

auto LoggingController::myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& messageText) -> void
{
    Q_UNUSED(context)

    QString logMessage;

    switch (type) {
    case QtMsgType::QtDebugMsg:
        logMessage = QString("[%1] [DEBUG] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtWarningMsg:
        logMessage = QString("[%1] [WARNING] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtCriticalMsg:
        logMessage = QString("[%1] [CRITICAL] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtFatalMsg:
        logMessage = QString("[%1] [FATAL ERROR] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    case QtMsgType::QtInfoMsg:
        logMessage = QString("[%1] [NFORMATION] %2\n").arg(QTime::currentTime().toString("hh:mm:ss")).arg(messageText);
        break;
    }

#ifdef QT_DEBUG
    QTextStream(stdout) << logMessage;
#else
    self->printToLogFile(logMessage);
#endif

    if (type == QtMsgType::QtFatalMsg)
        exit(-1);
}

auto LoggingController::setDebugMessageHandler() -> void
{
    m_logFileName = qApp->applicationDirPath() + "/log.txt";

    qInstallMessageHandler(&myMessageOutput);
}

} // namespace ATQW::Controllers
