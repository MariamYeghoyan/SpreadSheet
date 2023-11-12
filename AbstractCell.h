#ifndef ABSTRACTCELL
#define ABSTRACTCELL
#include <string>

class AbstractCell {
public:
    virtual ~AbstractCell() = default;
    virtual void setString(const std::string& s) = 0;
    virtual std::string getString() const = 0;
};

#endif
