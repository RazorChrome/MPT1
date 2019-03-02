#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <map>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	std::multimap<QString, int> mmap;

private slots:
	void show_mmap();

	void on_pbAdd_clicked();

	void on_pbClear_clicked();

	void on_pbDelete_clicked();

	void on_pbFind_clicked();

	void on_pbChange_clicked();

	void on_pbSave_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
