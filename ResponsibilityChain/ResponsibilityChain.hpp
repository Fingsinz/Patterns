#pragma once

/*
 * Author: Fingsinz
 * Date: 2024.07.31
 *
 * 责任链模式：允许构建一个对象链，请求从链的一端进入，沿着链上的对象依次处理，直至链上某个对象能够处理该请求。
 */

#include <iostream>

// 处理者
class Handler {
public:
    virtual ~Handler() = default;
    virtual void handleRequest(int requestId) = 0;
    virtual void setNextHandler(Handler *next) = 0;

protected:
    Handler *m_nextHandler;
};

// 具体处理者
class ConcreteHandler : public Handler {
public:
    void handleRequest(int requestId) {
        if (canHandle(requestId)) {
            std::cout << "ConcreteHandler::handleRequest() " << requestId << std::endl;
            return;
        } else if (m_nextHandler != nullptr) {
            m_nextHandler->handleRequest(requestId);
        } else {
            // 无法处理请求
        }
    }

    void setNextHandler(Handler *next) {
        m_nextHandler = next;
    }

private:
    bool canHandle(int requestId) {
        // 根据具体情况判断是否能处理请求
        return requestId > 0;
    }
};