#include "CalculationManager.h"
 
void CalculationManager::setFirstNumber(const double number) noexcept
{
	m_firstNumber = std::move(number);
}
void CalculationManager::setSecondNumber(const double number) noexcept
{
	m_secondNumber = std::move(number);

}
void CalculationManager::setOperator(const char op) noexcept
{
	m_operator = std::move(op);
}
void CalculationManager::setAlreadyNumber(const bool state)
{
	m_alreadyNumber = state;
}

double CalculationManager::getFirstNumber() const noexcept
{
	return m_firstNumber;
}
double CalculationManager::getSecondNumber() const noexcept
{
	return m_secondNumber;
}
char CalculationManager::getOperator() const noexcept
{
	return m_operator;
}
bool CalculationManager::getAlreadyNumber() const noexcept
{
	return m_alreadyNumber;
}


double CalculationManager::calculation()
{
	double result = 0.0;

	switch (m_operator)
	{
	case '+':
		result = m_firstNumber + m_secondNumber;
		break;
	case '-':
		result = m_firstNumber - m_secondNumber;
		break;
	case '*':
		result = m_firstNumber * m_secondNumber;
		break;
	case '/':
		result = m_firstNumber / m_secondNumber;
		break;
	}

	return result;
}