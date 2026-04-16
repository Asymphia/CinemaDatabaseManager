#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <vector>

class BaseUI {
protected:
    void clearScreen() const;
    void pause() const;
    void printTitle(const std::string& title) const;

    int readInt() const;
    std::string readLine(const std::string& label, const std::string& defaultValue = "") const;

    virtual void show() = 0;
    virtual ~BaseUI() = default;
};