#ifndef INTCELL
#define INTCELL
#include "AbstractCell.h"

class IntCell : public AbstractCell {
public:
    IntCell(int value) : value(value) {}
    virtual void setString(const std::string& s) override {
        try {
            value = std::stoi(s);
        }
        catch(std::exception& exep) {
            throw std::runtime_error("Conversion to int failed!");
        }
    }
    virtual std::string getString() const override {
        return std::to_string(value);
    }
private:
    int value;
};

#endif
