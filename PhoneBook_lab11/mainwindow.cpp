#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::show_mmap()
{
	QStringList list;
	for (std::multimap<QString,int>::iterator it=mmap.begin(); it!=mmap.end(); ++it)
		list << "Имя: " + (*it).first + " \tНомер: " + QString::number((*it).second);
	ui->listWidget->clear();
	ui->listWidget->addItems(list);
	ui->listWidget->sortItems();
}

void MainWindow::on_pbAdd_clicked()
{
	bool nameOK;
	QString name = QInputDialog::getText(
				this, "Введите имя",
				"Имя:", QLineEdit::Normal,
				QString(), &nameOK);
	if (nameOK && !name.isEmpty() && !name.contains(':') && !name.contains('\t')){
		bool numOk;
		int number = QInputDialog::getInt(
					this, "Введите номер",
					"Номер:", 0, -2147483647, 2147483647, 1, &numOk);
		if (numOk){
			mmap.insert(std::pair<QString, int>(name, number));
		}
	}
	show_mmap();
}

void MainWindow::on_pbClear_clicked()
{
	mmap.clear();
	show_mmap();
}

void MainWindow::on_pbDelete_clicked()
{
	QString str = ui->listWidget->currentItem()->text();
	QStringList sides = str.split(" \t", QString::SkipEmptyParts);

	QStringList nameParts = sides.at(0).split(": ", QString::SkipEmptyParts);
	QString name = nameParts.at(1);

	QStringList numParts = sides.at(1).split(": ", QString::SkipEmptyParts);
	int number = numParts.at(1).toInt();

	std::multimap<QString,int>::iterator fit = mmap.find(name);
	qDebug() << "Searching: " << name;
	if(fit != mmap.end()){
		std::pair <std::multimap<QString,int>::iterator,
				std::multimap<QString,int>::iterator> ret = mmap.equal_range(name);
		for (std::multimap<QString,int>::iterator it = ret.first; it!=ret.second; ++it){
			if((*it).second == number){
				qDebug() << (*it).first << (*it).second;
				mmap.erase(it);
				break;
			}
		}
	}

	show_mmap();
}

void MainWindow::on_pbFind_clicked()
{
	bool nameOK;
	QString name = QInputDialog::getText(
				this, "Найти по имени",
				"Имя:", QLineEdit::Normal,
				QString(), &nameOK);
	if (nameOK && !name.isEmpty() && !name.contains(':') && !name.contains('\t')){
		QString str;
		std::pair <std::multimap<QString,int>::iterator,
				std::multimap<QString,int>::iterator> ret = mmap.equal_range(name);
		for (std::multimap<QString,int>::iterator it = ret.first; it!=ret.second; ++it){
			qDebug() << (*it).first << (*it).second;
			str += (*it).first + "\t" + QString::number((*it).second) + "\n";
		}
		if(!str.isEmpty())
			QMessageBox::information(this, "Найдено", str);
		else
			QMessageBox::information(this, "Не найдено", name);
	}
}

void MainWindow::on_pbChange_clicked()
{
	QString str = ui->listWidget->currentItem()->text();
	QStringList sides = str.split(" \t", QString::SkipEmptyParts);

	QStringList nameParts = sides.at(0).split(": ", QString::SkipEmptyParts);
	QString name = nameParts.at(1);

	QStringList numParts = sides.at(1).split(": ", QString::SkipEmptyParts);
	int number = numParts.at(1).toInt();

	std::multimap<QString,int>::iterator fit = mmap.find(name);
	qDebug() << "Searching: " << name;
	if(fit != mmap.end()){
		std::pair <std::multimap<QString,int>::iterator,
				std::multimap<QString,int>::iterator> ret = mmap.equal_range(name);
		for (std::multimap<QString,int>::iterator it = ret.first; it!=ret.second; ++it){
			if((*it).second == number){
				qDebug() << (*it).first << (*it).second;

				bool nameOK;
				QString name = QInputDialog::getText(
							this, "Введите имя",
							"Имя:", QLineEdit::Normal,
							(*it).first, &nameOK);
				if (nameOK && !name.isEmpty() && !name.contains(':') && !name.contains('\t')){
					bool numOk;
					int number = QInputDialog::getInt(
								this, "Введите номер",
								"Номер:", (*it).second, -2147483647, 2147483647, 1, &numOk);
					if (numOk){
						mmap.insert(std::pair<QString, int>(name, number));
						mmap.erase(it);
					}
				}
				break;
			}
		}
	}
	show_mmap();
}

void MainWindow::on_pbSave_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(
				this, "Сохранить", QString(),
				"Text files (*.txt)");
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QString str;
	for (std::multimap<QString,int>::iterator it=mmap.begin(); it!=mmap.end(); ++it){
		str += "Имя: " + (*it).first + " \tНомер: " + QString::number((*it).second) + "\n";
	}
	str.chop(1);
	file.write(str.toUtf8());
}
