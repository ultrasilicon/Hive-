#ifndef GUITABBLOCK_H
#define GUITABBLOCK_H

#include <QStackedWidget>
#include "Gui/Frameworks/Widgets/LabelButton.h"
#include "ChatTab.h"
#include "HomeTab.h"
#include "SettingsTab.h"


class TabBlock : public QWidget
{
  Q_OBJECT

public:
  explicit TabBlock(QWidget *parent = nullptr);
  ~TabBlock();

  HomeTab *home_tab;
  ChatTab *chat_tab;
  SettingsTab *settings_tab;

private:
  void changeBtnLine();

  int current_tab_index = 0;
  QGridLayout *tab_label_layout;
  LabelButton *left_tab_label;
  LabelButton *mid_tab_label;
  LabelButton *right_tab_label;
  QFrame *left_btn_line;
  QFrame *mid_btn_line;
  QFrame *right_btn_line;
  QStackedWidget *tab_stacked_widget;
};

#endif // GUITABBLOCK_H
