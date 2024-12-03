
#ifndef EXECPTION_H
#define EXECPTION_H
#include <exception>
#include <string>
#include <utility>


class AplException : public std::exception {
protected:
    std::string message;
public:
    explicit AplException(std::string message) : message(std::move(message)) {}
    ~AplException() noexcept override=default;
    [[nodiscard]] const char* what() const noexcept override { return message.c_str(); }
};


class AnswerException final : public AplException {
    public:
    explicit AnswerException(std::string message) : AplException(std::move(message)) {}
    ~AnswerException() noexcept override = default;
};

class NoAnswerException final : public AplException {
public:
    explicit NoAnswerException(std::string message) : AplException(std::move(message)) {}
    ~NoAnswerException() noexcept override = default;
};

#endif //EXECPTION_H
