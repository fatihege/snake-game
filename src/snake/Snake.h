#pragma once

#include <memory>
#include <mutex>
#include <vector>

class Snake {
    static std::unique_ptr<Snake> instance;
    static std::once_flag initFlag;

    Snake(const std::vector<std::pair<int, int> > &body, const std::pair<int, int> &direction);

    std::vector<std::pair<int, int> > body;
    std::pair<int, int> direction;

public:
    static Snake &getInstance(const std::vector<std::pair<int, int> > &body, const std::pair<int, int> &direction);

    Snake(const Snake&) = delete;

    Snake& operator=(const Snake&) = delete;

    void move();

    void grow();

    bool checkCollision(const std::pair<int, int> &point);

    const std::vector<std::pair<int, int> > &getBody() const;
};
