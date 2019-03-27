#pragma once

#include <memory>

class CalculationManager
{
public:
	CalculationManager() = default;
	~CalculationManager() = default;

	void setFirstNumber(const double number) noexcept;
	void setSecondNumber(const double number) noexcept;
	void setOperator(const char op) noexcept;
	void setAlreadyNumber(const bool state);

	double getFirstNumber() const noexcept;
	double getSecondNumber() const noexcept;
	char getOperator() const noexcept;
	bool getAlreadyNumber() const noexcept;

	

	double calculation();
private:
	char m_operator;
	bool m_alreadyNumber;
	double m_firstNumber;
	double m_secondNumber;
	double m_resultNumber;
};