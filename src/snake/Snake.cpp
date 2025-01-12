#include "Snake.h"

#include <iostream>
#include <ostream>

Snake::Snake(const std::vector<std::pair<int, int> > &body,
             const std::pair<int, int> &direction): body(body), direction(direction) {
}

Snake &Snake::getInstance(const std::vector<std::pair<int, int> > &body,
                          const std::pair<int, int> &direction) {
    std::call_once(initFlag, [body, direction] {
        instance.reset(new Snake(body, direction));
    });
    return *instance;
}

void Snake::move() {
    std::cout << "Moved\n";
}

void Snake::grow() {
    std::cout << "Grew\n";
}

bool Snake::checkCollision(const std::pair<int, int> &point) {
    std::cout << "Checked collision\n";
    return false;
}

const std::vector<std::pair<int, int> > &Snake::getBody() const {
    return body;
}

std::unique_ptr<Snake> Snake::instance;
std::once_flag Snake::initFlag;
