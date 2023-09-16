#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void fetchRandomImage();
    void onImageDownloaded(QNetworkReply* reply);

private:
    QLabel* imageLabel;
    QPushButton* fetchButton;
    QVBoxLayout* mainLayout;
    QNetworkAccessManager* networkManager;
};

#endif // MAINWINDOW_H
