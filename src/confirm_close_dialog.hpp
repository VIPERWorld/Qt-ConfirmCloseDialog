/**
 * \file
 *
 * \author Mattia Basaglia
 *
 * \copyright Copyright (C) 2012-2015 Mattia Basaglia
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DIALOG_CONFIRM_CLOSE_HPP
#define DIALOG_CONFIRM_CLOSE_HPP

#include <QDialog>

/**
 * \brief A dialog asking to whether to save multiple files
 */
class ConfirmCloseDialog : public QDialog
{
    Q_OBJECT
    
public:

    explicit ConfirmCloseDialog(QWidget *parent = nullptr);
    ~ConfirmCloseDialog();

    /**
     * \brief Insert file to be saved
     * \param index  An identifier used by the caller to associate to the file
     * \param name   File name
     * \post  has_file() == true
     * \note  \c index should be unique, for a single file
     */
    void addFile(int index, QString name);

    bool hasFiles() const;

    /**
     * \brief Get files to be saved
     * \return A list of indices representing the files that need to be saved
     */
    QList<int> saveFiles() const;
    
protected:
    void changeEvent(QEvent *e) override;

private slots:
    void on_button_dont_save_clicked();
    
private:
    class Private;
    Private* p;
};

#endif // DIALOG_CONFIRM_CLOSE_HPP
