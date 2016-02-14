#ifndef GUICOMBWIDGET_H
#define GUICOMBWIDGET_H

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "GlobalData.h"
#include "GuiLabelButton.h"
#include "GuiAvatarButton.h"

class GuiCombWidget : public QWidget
{
  Q_OBJECT

public:
  explicit GuiCombWidget(QStringList usrInfoStrList, QWidget *parent = 0);
  ~GuiCombWidget();

  QStringList usrInfo();

protected:
  void paintEvent(QPaintEvent*);

  void mouseReleaseEvent(QMouseEvent *);
  void enterEvent(QEvent *);
  void leaveEvent(QEvent *);
  void dragMoveEvent(QEvent *);

private:
  GuiAvatarButton *avatar;
  QLabel *usr_name_label;
  QLabel *ip_addr_label;
  QLabel *status_label;
  QVBoxLayout *usr_info_layout;
  QHBoxLayout *ip_status_layout;
  QHBoxLayout *main_layout;

  QPalette hover_palette;
  QColor window_color = GlobalData::g_tabColor;
  QColor default_window_color = GlobalData::g_tabColor;
  QColor hovered_window_color = QColor(255,175,0,161);

  bool selected = false;
  bool hovered  = false;

  ///data
  QStringList usr_info_str_list;



signals:
  void clicked(QString usrKey);



};

#endif // GUICOMBWIDGET_H
