#include <iostream>
#include <ostream>
#include <limits>
#include <string>
#include <optional>
#include <sstream>

struct parser_state {
    std::string line;
    size_t pos;
};

void skip_whitespace(parser_state& state) {
    while (state.pos < state.line.size() && state.line[state.pos] == ' ') {
        ++state.pos;
    }
}

int parse_optional_sign(parser_state& state) {
    if (state.pos < state.line.size() && state.line[state.pos] == '-') {
        ++state.pos;
        return -1;
    }

    return 1;
}

std::optional<int> parse_digit(parser_state& state) {
    if (state.pos < state.line.size()) {
        char c = state.line[state.pos];
        if (c >= '0' && c <= '9') {
            ++state.pos;
            return c - '0';
        }
    }

    return std::nullopt;
}

struct parse_error : public std::runtime_error {
    parser_state state;
    parse_error(const char* what, const parser_state& error_state) : std::runtime_error(what), state(error_state) {
    }
};

int parse_int(parser_state& state) {
    skip_whitespace(state);
    int sign = parse_optional_sign(state);
    auto digit = parse_digit(state);
    if (!digit) {
        throw parse_error("Expected integer digit.", state);
    }

    int value = 0;
    do {
        value = value * 10 + sign * digit.value();
        if (value != 0 && ((value < 0) != (sign < 0))) {
            std::ostringstream oss;
            oss << "Only integers between " << std::numeric_limits<int>::min() << " and " << std::numeric_limits<int>::max() << " are supported.";
            throw parse_error(oss.str().c_str(), state);
        }

        digit = parse_digit(state);
        skip_whitespace(state);
    } while (digit);

    if (state.pos != state.line.size()) {
        throw parse_error("Unexpected character.", state);
    }

    return value;
}

int request_int() {
    parser_state state {};
    std::getline(std::cin, state.line);
    return parse_int(state);
}

void print_error(const std::string& message, const parser_state& state) {
    std::cerr << message << std::endl;
    std::cerr << "    " << state.line << std::endl;
    std::cerr << std::string(4 + state.pos, ' ') << "^" << std::endl;
}

int acquire_int() {
    while (true) {
        try {
            return request_int();
        } catch (parse_error err) {
            print_error(err.what(), err.state);
        }

        std::cout << "Try entering an integer value again." << std::endl;
    }
}

int main() {
    int a = acquire_int();
    int b = acquire_int();
    int remainder = a % b;
    std::cout << remainder << std::endl;
}