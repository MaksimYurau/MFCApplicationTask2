#pragma once
#include <vector>
#include <exception>
#include <string>

class CalculatorException : public std::exception
{
public:
	enum class ExceptionType : char { None=0, DividedByZero };
	CalculatorException(std::string textWhat, ExceptionType exceptionType) : 
		m_textWhat(textWhat), m_exceptionType(exceptionType)
	{
	}
	virtual const char* what() const throw()
	{
		return m_textWhat.c_str();
	}
private:
	std::string m_textWhat;
	ExceptionType m_exceptionType{ ExceptionType::None };
};

class Calculator
{
public:

	enum class ActionType : char {Number, Plus, Minus, Multiply, Divide, Equals, None};
	struct Action
	{
		ActionType actionType;
		double value;
	};

	void reset();
	bool addInput(const Action& input);
	Action getLastInput() const;

	double getCurrentResult() const;
	bool hasLeftTermValue() const { return m_leftTerm.hasValue(); }
	bool hasLeftExpressionValue() const { return m_leftExpression.hasValue(); }
	bool isOperation(ActionType action) const;
	// actions
	int getActionsSize() { return static_cast<int>(m_actions.size()); }
	const Action& getAction(int i) { return m_actions.at(i);  }
private:
	bool isTerm(ActionType action) const;
	bool isExpression(ActionType action) const;
	ActionType getLastOperation();


	class LeftExpression
	{
	public:
		void reset();
		void set(double value);
		void add(double value);
		double getValue() const { return m_value; }
		bool hasValue() const { return m_hasValue; }
	private:
		bool m_hasValue = false;
		double m_value = 0.0;
	};

	class LeftTerm
	{
	public:
		void reset();
		void set(double value);
		void multiplyBy(double value);
		double getValue() const { return m_value; }
		bool hasValue() const { return m_hasValue; }
	private:
		bool m_hasValue = false;
		double m_value;
	};


	std::vector<Action> m_actions; 
	LeftExpression m_leftExpression;
	LeftTerm m_leftTerm;
};

inline void Calculator::LeftExpression::reset() 
{
	m_hasValue = false;
	m_value = 0.0;
}

inline void Calculator::LeftExpression::set(double value) 
{
	m_hasValue = true;
	m_value = value;
}

inline void Calculator::LeftExpression::add(double value)
{
	set(m_value + value);
}

inline void Calculator::LeftTerm::reset() 
{
	m_hasValue = false;
	m_value = 0.0;
}

inline void Calculator::LeftTerm::set(double value) 
{
	m_hasValue = true;
	m_value = value;
}

inline void Calculator::LeftTerm::multiplyBy(double value)
{
	set(m_value * value);
}

