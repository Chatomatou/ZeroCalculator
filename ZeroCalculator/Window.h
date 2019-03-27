#pragma once

#include <QtCore/QDebug>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>

#include "CalculationManager.h"

#include <array>
 
 

class Window : public QWidget
{
Q_OBJECT

public:
	Window();
public slots:
	void updateLabel();
	void calculation(const QString& labelText);
signals:
	void reset();
private:
	CalculationManager m_manager;
	QVBoxLayout* m_contentLayoutVertical;
	QGridLayout* m_buttonLayoutGrid;

	QLabel* m_displayLabel;
	std::array<std::array<QPushButton*, 4>, 4> m_buttonArray;
};