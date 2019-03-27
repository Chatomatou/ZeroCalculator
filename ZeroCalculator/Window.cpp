#include "Window.h"

Window::Window() : m_manager{}, QWidget{}
{
	setWindowTitle("Calculator");

 
	m_contentLayoutVertical = new QVBoxLayout;
	m_buttonLayoutGrid = new QGridLayout;

	m_displayLabel = new QLabel;

	m_buttonLayoutGrid->addWidget(m_displayLabel, 0, 0, 1, 4);
	m_displayLabel->setFrameStyle(QFrame::Box);
	m_displayLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	m_displayLabel->setFont(QFont{ "Ubuntu", 18, QFont::Bold, false });

	std::array<QString, 4> op1{ "7", "8", "9", "/" };
	std::array<QString, 4> op2{ "4", "5", "6", "*" };
	std::array<QString, 4> op3{ "1", "2", "3", "-" };
	std::array<QString, 4> op4{ "=", "0", ".", "+" };



	for (auto i{ 0 }; i < m_buttonArray.size(); i++)
	{
		for (auto j{ 0 }; j < m_buttonArray.size(); j++)
		{
			m_buttonArray[i][j] = new QPushButton;
			m_buttonArray[i][j]->setFont(QFont{ "Ubuntu", 18, QFont::Bold, false });
			m_buttonArray[i][j]->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
			m_buttonLayoutGrid->addWidget(m_buttonArray[i][j], i+1, j);
 			QObject::connect(m_buttonArray[i][j], &QPushButton::clicked, this, &Window::updateLabel);
			switch (i)
			{
			case 0:
				m_buttonArray[i][j]->setText(op1[j]);
				break;
			case 1:
				m_buttonArray[i][j]->setText(op2[j]);
				break;
			case 2:
				m_buttonArray[i][j]->setText(op3[j]);
				break;
			case 3:
				m_buttonArray[i][j]->setText(op4[j]);
				break;
			}
		 
		}
	}

	//m_contentLayoutVertical->addLayout(m_buttonLayoutGrid);
	setLayout(m_buttonLayoutGrid);

}

void Window::calculation(const QString& labelText)
{
	QStringList number = labelText.split("+");
 
	for (auto & data : number)
		qDebug() << data;
}

void Window::updateLabel()
{
	QStringList list = m_displayLabel->text().split(m_manager.getOperator());

	QPushButton* button = static_cast<QPushButton*>(QObject::sender());
	
	if (m_displayLabel->text().isEmpty() && button->text() == ".")
	{
		m_displayLabel->setText("0.");
	}
	else
	{
		QChar buttonContent = button->text().at(0);
	 
		if (button->text() == "." && m_displayLabel->text().isEmpty())
		{
				m_displayLabel->setText("0.");
		}
		else
		{
			switch (buttonContent.toLatin1())
			{
			case '+':
				if (list.length() < 2)
				{
					if (m_manager.getAlreadyNumber())
					{
						m_manager.setOperator('+');

						if (!m_displayLabel->text().contains("-") && !m_displayLabel->text().contains("+") && !m_displayLabel->text().contains("*") && !m_displayLabel->text().contains("/"))
							m_displayLabel->setText(m_displayLabel->text() + "+");
						else
							m_displayLabel->setText(m_displayLabel->text().mid(0, m_displayLabel->text().length() - 1) + "+");
					}
				}
				 
				 
				break;
			case '-':
				if (list.length() < 2)
				{
					if (m_manager.getAlreadyNumber())
					{
						m_manager.setOperator('-');
						if (!m_displayLabel->text().contains("-") && !m_displayLabel->text().contains("+") && !m_displayLabel->text().contains("*") && !m_displayLabel->text().contains("/"))
							m_displayLabel->setText(m_displayLabel->text() + "-");
						else
							m_displayLabel->setText(m_displayLabel->text().mid(0, m_displayLabel->text().length() - 1) + "-");
					}
				}

				break;
			case '*':
				if (list.length() < 2)
				{
					if (m_manager.getAlreadyNumber())
					{
						m_manager.setOperator('*');
						if (!m_displayLabel->text().contains("-") && !m_displayLabel->text().contains("+") && !m_displayLabel->text().contains("*") && !m_displayLabel->text().contains("/"))
							m_displayLabel->setText(m_displayLabel->text() + "*");
						else
							m_displayLabel->setText(m_displayLabel->text().mid(0, m_displayLabel->text().length() - 1) + "*");
					}
				}
				 
				break;
			case '/':
				if (list.length() < 2)
				{
					if (m_manager.getAlreadyNumber())
					{
						m_manager.setOperator('/');
						if (!m_displayLabel->text().contains("-") && !m_displayLabel->text().contains("+") && !m_displayLabel->text().contains("*") && !m_displayLabel->text().contains("/"))
							m_displayLabel->setText(m_displayLabel->text() + "/");
						else
							m_displayLabel->setText(m_displayLabel->text().mid(0, m_displayLabel->text().length() - 1) + "/");
					}
				}
				 
				break;
			case '=':

				if (!m_displayLabel->text().isEmpty())
				{
					if (list.length() == 2)
					{
						m_manager.setFirstNumber(list.at(0).toDouble());
						m_manager.setSecondNumber(list.at(1).toDouble());
						m_displayLabel->setText(QString::number(m_manager.calculation()));
					}
					 
				}
				break;
			default:
				m_displayLabel->setText(m_displayLabel->text() + button->text());
				m_manager.setAlreadyNumber(true);
				break;
			}
		}
	}
}