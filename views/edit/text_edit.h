#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>

class TextEdit : public QTextEdit {
  Q_OBJECT
 public:
  TextEdit(QWidget *parent = 0);
  //~TextEdit();
};

#endif  // TEXTEDIT_H
