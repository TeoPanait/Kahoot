#ifndef EXECPTION_H
#define EXECPTION_H

#include <exception>
#include <string>
#include <utility>

// Base class for custom exceptions
class AplException : public std::exception {
protected:
    std::string message;  // Exception message
public:
    explicit AplException(std::string message) : message(std::move(message)) {}
    ~AplException() noexcept override = default;

    // Returns the exception message
    [[nodiscard]] const char* what() const noexcept override { return message.c_str(); }
};

// Specific exception for answers
class AnswerException final : public AplException {
public:
    explicit AnswerException(std::string message) : AplException(std::move(message)) {}
    ~AnswerException() noexcept override = default;
};

// Specific exception for names
class NameException final : public AplException {
public:
    explicit NameException(std::string message) : AplException(std::move(message)) {}
    ~NameException() noexcept override = default;
};

// Specific exception for quiz
class QuizException final : public AplException {
public:
    explicit QuizException(std::string message) : AplException(std::move(message)) {}
    ~QuizException() noexcept override = default;
};

#endif //EXECPTION_H
