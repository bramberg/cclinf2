
#ifndef _MODELS_UTILS_EXCEPTION_H_
#define _MODELS_UTILS_EXCEPTION_H_

#include <QString>

class Exception {
 public:
  Exception(const QString& message = "") : message_(message) {}
  ~Exception() {}

  QString GetMessage() { return message_; }

 private:
  QString message_;
};

#endif
