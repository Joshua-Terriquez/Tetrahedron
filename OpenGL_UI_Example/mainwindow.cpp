#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_gl.h"
#include <QDebug>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_x_rot_slider_valueChanged(int value)
{
    Q_UNUSED(value);
    ui->openGLWidget->setRotation(
                ui->x_rot_slider->value(),
                ui->y_rot_slider->value(),
                ui->z_rot_slider->value()
                );
}

void MainWindow::on_y_rot_slider_valueChanged(int value)
{
    Q_UNUSED(value);
    ui->openGLWidget->setRotation(
                ui->x_rot_slider->value(),
                ui->y_rot_slider->value(),
                ui->z_rot_slider->value()
                );
}

void MainWindow::on_z_rot_slider_valueChanged(int value)
{
    Q_UNUSED(value);
    ui->openGLWidget->setRotation(
                ui->x_rot_slider->value(),
                ui->y_rot_slider->value(),
                ui->z_rot_slider->value()
                );
}

void MainWindow::on_x_translate_slider_valueChanged(int value){
    Q_UNUSED(value);

    ui->openGLWidget->setTranslation(
                ui->x_translate_slider->value(),
                ui->y_translate_slider->value(),
                ui->z_translate_slider->value()
                );
}
void MainWindow:: on_y_translate_slider_valueChanged(int value)
{   Q_UNUSED(value);
    ui->openGLWidget->setTranslation(
                ui->x_translate_slider->value(),
                ui->y_translate_slider->value(),
                ui->z_translate_slider->value()
                );
}
void MainWindow:: on_z_translate_slider_valueChanged(int value)
{   Q_UNUSED(value);
    ui->openGLWidget->setTranslation( ui->x_translate_slider->value(),
                ui->y_translate_slider->value(),
                ui->z_translate_slider->value()
                );
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    float y = ui->y_translate_slider->value();
    float x = ui->x_translate_slider->value();
    float y_inc = 0.0;
    float x_inc = 0.0;
    if (event->key() == Qt::Key_Up) {
        y_inc = -50.0f;
    }

    if (event->key() == Qt::Key_Down) {
        qDebug() << QString("Down");
        y_inc = +50.0f;
    }
    if (event->key() == Qt::Key_Left) {
        qDebug() << QString("Left");
        x_inc = -50.0f;
    }
    if (event->key() == Qt::Key_Right) {
        x_inc = +50.0f;
    }
    ui->openGLWidget->setTranslation(x + x_inc,y + y_inc,0);

}

void MainWindow::on_pushButton_clicked()
{
    close();
}

