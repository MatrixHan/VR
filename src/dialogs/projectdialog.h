#ifndef PROJECTDIALOG_H
#define PROJECTDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
    class ProjectDialog;
}

class MainWindow;
class SettingsManager;
class Database;

class ProjectDialog : public QDialog
{
    Q_OBJECT

public:
    ProjectDialog(QDialog *parent = nullptr);
    ~ProjectDialog();

    MainWindow *window;

    void setSettingsManager(SettingsManager* settings);
    QString loadProjectDelegate();
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
    SettingsManager* getSettingsManager();
    SettingsManager* settings;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

protected slots:
    void newScene();
    void openProject();
    void openRecentProject(QListWidgetItem*);
    void openSampleProject(QListWidgetItem*);

private:
    Ui::ProjectDialog *ui;
    Database *db;
};

#endif // PROJECTDIALOG_H
