#include "AbstractCell.h"

class DoubleCell : public AbstractCell {
public:
    DoubleCell(double value) : value(value) {}
    virtual void setString(const std::string& s) override {
        try {
            value = std::stod(s);
        }
        catch(std::exception& exep) {
            throw std::runtime_error("Conversion to double failed!");
        }
    }
    virtual std::string getString() const override {
        return std::to_string(value);
    }
private:
    double value;
};
