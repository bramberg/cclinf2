
#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <QException>

namespace exceptions {

class Exception : public QException {
 public:
  Exception(const QString& message = "") : message_(message) {}
  Exception(const Exception& other) : message_(other.message_) {}
  ~Exception() {}

  void raise() const { throw * this; }
  Exception* clone() const { return new Exception(*this); }

  QString GetMessage() { return message_; }
  const char* what() const _GLIBCXX_USE_NOEXCEPT {
    return message_.toStdString().c_str();
  }

 private:
  QString message_;
};

class ParsingError : public Exception {
 public:
  ParsingError(const QString& message = "") : Exception(message) {}
};

class CouldNotOpenFileForReading : public QException {};
class CouldNotOpenFileForWriting : public Exception {};
class FileHasInvalidVersion : public QException {};
}

#endif
