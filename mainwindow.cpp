#include "mainwindow.h"
#include <QNetworkRequest>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Random Image Viewer");

    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);

    fetchButton = new QPushButton("Fetch Random Image", this);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(fetchButton);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    networkManager = new QNetworkAccessManager(this);

    connect(fetchButton, &QPushButton::clicked, this, &MainWindow::fetchRandomImage);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onImageDownloaded);
}

MainWindow::~MainWindow()
{
}

void MainWindow::fetchRandomImage()
{
    // Replace this URL with the URL of an image you want to fetch
    QUrl imageUrl("https://source.unsplash.com/random");

    QNetworkRequest request(imageUrl);
    networkManager->get(request);
}

void MainWindow::onImageDownloaded(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        // Load the downloaded image into the QLabel
        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        imageLabel->setPixmap(pixmap);
    }
    else
    {
        qDebug() << "Error downloading image:" << reply->errorString();
    }

    reply->deleteLater();
}
