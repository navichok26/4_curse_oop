#include <iostream>
#include <memory>
#include <string>

class ILogger {
public:
    virtual void Log(const std::string &logText) = 0;
    virtual ~ILogger() {}
};

class FileLogger : public ILogger {
public:
    void Log(const std::string &logText) override {
        std::cout << "FileLogger: сохранение лога в файле: " << logText << std::endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void Log(const std::string &logText) override {
        std::cout << "DatabaseLogger: сохранение лога в базе данных: " << logText << std::endl;
    }
};

class SmtpMailer {
private:
    std::shared_ptr<ILogger> logger;
public:
    SmtpMailer(std::shared_ptr<ILogger> logger) : logger(logger) {}

    void SendMessage(const std::string &message) {
        std::cout << "SmtpMailer: отправка сообщения: " << message << std::endl;
        if (logger) {
            logger->Log(message);
        } else {
            std::cout << "Нет логгера для записи сообщения." << std::endl;
        }
    }
};

int main() {
    std::shared_ptr<ILogger> fileLogger = std::make_shared<FileLogger>();
    SmtpMailer mailerFile(fileLogger);
    mailerFile.SendMessage("Это письмо через FileLogger!");

    std::shared_ptr<ILogger> dbLogger = std::make_shared<DatabaseLogger>();
    SmtpMailer mailerDB(dbLogger);
    mailerDB.SendMessage("Это письмо через DatabaseLogger!");

    return 0;
}