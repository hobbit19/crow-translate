/*
 *  Copyright © 2018-2019 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Crow Translate.
 *
 *  Crow Translate is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QWidget>

class LangButtonGroup;
class QTextEdit;
class QToolButton;
class QComboBox;
class QShortcut;

namespace Ui {
class PopupWindow;
}

class PopupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PopupWindow(LangButtonGroup *sourceGroup, LangButtonGroup *translationGroup, int engineIndex, QWidget *parent = nullptr);
    ~PopupWindow() override;

    QTextEdit *translationEdit();
    QToolButton *swapButton();
    QComboBox *engineCombobox();

    QToolButton *addSourceLangButton();
    QToolButton *playSourceButton();
    QToolButton *stopSourceButton();
    QToolButton *copySourceButton();

    QToolButton *addTranslationLangButton();
    QToolButton *playTranslationButton();
    QToolButton *stopTranslationButton();
    QToolButton *copyTranslationButton();
    QToolButton *copyAllTranslationButton();

    LangButtonGroup *sourceButtons();
    LangButtonGroup *translationButtons();

private:
    void showEvent(QShowEvent *event) override;
    bool event(QEvent *event) override;

    Ui::PopupWindow *ui;
    QShortcut *m_closeWindowsShortcut;
    LangButtonGroup *m_sourceButtonGroup;
    LangButtonGroup *m_translationButtonGroup;
};

#endif // POPUPWINDOW_H
