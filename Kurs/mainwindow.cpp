#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->PlantInfo->setWordWrap(true);
    ui->PlantInfo->setTextFormat(Qt::RichText); // Set to handle rich text

    ui->PlantInfo->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->PlantInfo, &QLabel::customContextMenuRequested, this, &MainWindow::showContextMenu);
    QPixmap pixmap(imageInfo);
    ui->PlantImage->setPixmap(pixmap);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("plants.db");
    if (!db.open()) {
        qDebug() << "Error: Unable to open database" << db.lastError();
    }

    // Create the table if it doesn't exist
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS plants ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "name TEXT NOT NULL, "
                    "description TEXT, "
                    "image TEXT)")) {
        qDebug() << "Error: Unable to create table" << query.lastError();
    }

    ui->PlantImage->installEventFilter(this);
    ui->PlantImage->setToolTip("Click to view image in full size");

    loadPlantList();

    // Initialize network manager
    networkManager = new QNetworkAccessManager(this);

    // Connect signals
    connect(ui->Add, &QPushButton::clicked, this, &MainWindow::loadPlantInfo);
    connect(ui->ListPlants, &QListWidget::itemClicked, this, &MainWindow::displayPlantInfo);
    connect(ui->Delete, &QPushButton::clicked, this, [this]() {
        QListWidgetItem *item = ui->ListPlants->currentItem();
        if (item) {
            QString plantName = item->text();

            // Show confirmation dialog
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение удаления",
                                                                      QString("Вы действительно хотите удалить растение \"%1\"?").arg(plantName),
                                                                      QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::No) {
                return; // User cancelled deletion
            }

            // Remove the item from the list
            delete ui->ListPlants->takeItem(ui->ListPlants->row(item));

            // Delete the record from the database
            QSqlQuery query;
            query.prepare("DELETE FROM plants WHERE name = :name");
            query.bindValue(":name", plantName);
            if (query.exec()) {
                qDebug() << "Plant deleted successfully.";
            } else {
                qDebug() << "Error: Unable to delete plant" << query.lastError();
                QMessageBox::warning(this, "Ошибка", "Не удалось удалить растение из базы данных.");
            }

            // Check if there are items left in the list
            if (ui->ListPlants->count() > 0) {
                // Select the current row or the next item
                int currentRow = ui->ListPlants->currentRow();
                if (currentRow >= 0) {
                    ui->ListPlants->setCurrentRow(currentRow);
                } else {
                    ui->ListPlants->setCurrentRow(0);
                }
                // Display the selected plant's information
                displayPlantInfo(ui->ListPlants->currentItem());
            } else {
                // No items left, display main information
                ui->PlantName->setText(header);
                ui->PlantInfo->setText(info);
                QPixmap pixmap(imageInfo);
                ui->PlantImage->setPixmap(pixmap);
            }
        } else {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите растение для удаления.");
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu menu(this);
    QAction *editAction = menu.addAction("Edit Text");
    QAction *selectedAction = menu.exec(ui->PlantInfo->mapToGlobal(pos));
    if (selectedAction == editAction) {
        editText();
    }
}

void MainWindow::editText()
{
    // Get the current HTML text from PlantInfo
    QString htmlText = ui->PlantInfo->text();

    // Create a dialog for editing the HTML content
    QDialog dialog(this);
    dialog.setWindowTitle("Edit Plant Description");
    dialog.resize(600, 400);

    QTextEdit *textEdit = new QTextEdit(&dialog);
    textEdit->setHtml(htmlText);
    textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QPushButton *okButton = new QPushButton("OK", &dialog);
    QPushButton *cancelButton = new QPushButton("Cancel", &dialog);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(textEdit);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        // Get the new HTML content from the dialog
        QString newHtmlText = textEdit->toHtml();

        // Update PlantInfo with the new HTML content
        ui->PlantInfo->setText(newHtmlText);

        // Update the database with the new HTML description
        updatePlantDescription(newHtmlText);
    }
}

void MainWindow::updatePlantDescription(const QString &newDescription)
{
    QString plantName = ui->PlantName->text();
    QSqlQuery query;
    query.prepare("UPDATE plants SET description = :description WHERE name = :name");
    query.bindValue(":description", newDescription);
    query.bindValue(":name", plantName);
    if (query.exec()) {
        qDebug() << "Description updated successfully.";
    } else {
        qDebug() << "Error: Unable to update description" << query.lastError();
        QMessageBox::warning(this, "Ошибка", "Не удалось обновить описание в базе данных.");
    }
}

void MainWindow::loadPlantList()
{
    ui->ListPlants->clear();
    QSqlQuery query("SELECT name FROM plants");
    while (query.next()) {
        QListWidgetItem *item = new QListWidgetItem(query.value(0).toString(), ui->ListPlants);
        item->setTextAlignment(Qt::AlignCenter);
        ui->ListPlants->addItem(item);
    }
}

void MainWindow::displayPlantInfo(QListWidgetItem *item)
{
    if (item) {
        QString plantName = item->text();
        QSqlQuery query;
        query.prepare("SELECT name, description, image FROM plants WHERE name = :name");
        query.bindValue(":name", plantName);
        if (query.exec() && query.next()) {
            QString dbName = query.value(0).toString();
            QString description = query.value(1).toString();
            QString imagePath = query.value(2).toString();

            ui->PlantName->setText(dbName);
            ui->PlantInfo->setText(description); // Assuming description is HTML
            if (QFile::exists(imagePath)) {
                QPixmap pixmap(imagePath);
                ui->PlantImage->setPixmap(pixmap);
            } else {
                ui->PlantImage->setText("Изображение отсутствует.");
            }
        } else {
            qDebug() << "Error: Plant not found in database.";
        }
    } else {
        // Clear the widgets if no item is selected
        ui->PlantName->clear();
        ui->PlantInfo->clear();
        ui->PlantImage->setPixmap(QPixmap());
    }
}

void MainWindow::loadPlantInfo()
{
    QString plantName = ui->InputPlant->text().trimmed();

    if (plantName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите название растения.");
        return;
    }

    plantName[0] = plantName[0].toUpper();
    for (int i = 1; i < plantName.size(); ++i) {
        plantName[i] = plantName[i].toLower();
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM plants WHERE name = :name");
    query.bindValue(":name", plantName);
    if (query.exec() && query.next() && query.value(0).toInt() > 0) {
        QMessageBox::information(this, "Информация", "Растение \"" + plantName + "\" уже есть в базе данных.");
        return;
    }

    QString apiUrl = QString("https://ru.wikipedia.org/w/api.php?action=query&prop=extracts|pageimages&format=json&titles=%1&exintro=1&piprop=thumbnail&pithumbsize=300")
                         .arg(plantName);

    QNetworkRequest request(apiUrl);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply, plantName]() {
        if (reply->error() == QNetworkReply::NoError) {
            parseWikipediaResponse(reply->readAll(), plantName);
        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка загрузки информации о растении.");
            ui->PlantImage->clear();
        }
        reply->deleteLater();
    });
}


void MainWindow::parseWikipediaResponse(const QByteArray &data, const QString &plantName)
{

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonObject query = jsonDoc.object()["query"].toObject();
    QJsonObject pages = query["pages"].toObject();

    if (pages.isEmpty()) {
        QMessageBox::information(this, "Информация", "Информация о растении не найдена.");
        return;
    }

    // Iterate through pages to get the first page (assuming only one)
    for (auto it = pages.begin(); it != pages.end(); ++it) {
        QJsonObject page = it.value().toObject();
        QString extract = page["extract"].toString();
        QString thumbnailUrl = page["thumbnail"].toObject()["source"].toString();

        // Check if the description contains any of the keywords
        bool containsKeyword = false;
        for (const QString &keyword : keywords) {
            if (extract.contains(keyword, Qt::CaseInsensitive)) {
                containsKeyword = true;
                break;
            }
        }

        if (!containsKeyword) {
            QMessageBox::information(this, "Информация", "Описание растения не содержит необходимых ключевых слов.");
            return;
        }

        ui->PlantName->setText(plantName);
        ui->PlantInfo->setText(extract); // Assuming extract is HTML

        if (!thumbnailUrl.isEmpty()) {
            QNetworkRequest imgRequest(thumbnailUrl);
            QNetworkReply *imgReply = networkManager->get(imgRequest);

            connect(imgReply, &QNetworkReply::finished, this, [this, imgReply, plantName, extract]() {
                if (imgReply->error() == QNetworkReply::NoError) {
                    QByteArray imageData = imgReply->readAll();

                    QString imagePath = QString("images/%1.jpg").arg(cleanFileName(plantName));
                    QDir().mkpath("images");
                    QFile file(imagePath);
                    if (file.open(QIODevice::WriteOnly)) {
                        file.write(imageData);
                        file.close();
                    }

                    QPixmap pixmap;
                    pixmap.loadFromData(imageData);
                    ui->PlantImage->setPixmap(pixmap);

                    QSqlQuery query;
                    query.prepare("INSERT INTO plants (name, description, image) VALUES (:name, :description, :image)");
                    query.bindValue(":name", plantName);
                    query.bindValue(":description", extract);
                    query.bindValue(":image", imagePath);
                    if (!query.exec()) {
                        qDebug() << "Error: Unable to add plant" << query.lastError();
                    } else {
                        loadPlantList();
                    }
                } else {
                    QMessageBox::warning(this, "Ошибка", "Ошибка загрузки изображения.");
                }
                imgReply->deleteLater();
            });
        } else {
            QMessageBox::information(this, "Информация", "Изображение отсутствует.");
        }
    }
}

QString MainWindow::cleanFileName(const QString &fileName)
{
    QString cleanedFileName = fileName;
    cleanedFileName.replace(QRegularExpression("[\\\\/:*?\"<>|]"), "_");
    cleanedFileName.replace(" ", "_");
    return cleanedFileName;
}

void MainWindow::showFullImage() {
    QPixmap pixmap = ui->PlantImage->pixmap();
    if (!pixmap.isNull()) {
        QDialog dialog(this);
        QLabel *label = new QLabel(&dialog);
        label->setPixmap(pixmap);
        label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        label->setScaledContents(true);
        QVBoxLayout *layout = new QVBoxLayout(&dialog);
        layout->addWidget(label);
        dialog.resize(pixmap.size());
        dialog.exec();
    } else {
        QMessageBox::information(this, "Информация", "Изображение отсутствует.");
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->PlantImage && event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            showFullImage();
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}
