#include "Spreadsheet.h"
#include "AbstractCell.h"
#include "DoubleCell.h"
#include "IntCell.h"
#include "StringCell.h"
#include <iostream>

int main() {
    Spreadsheet ob; 
    ob.addRow(2);
    StringCell* newStringCell = new StringCell("");
    ob.addColumn(2, newStringCell);

    ob.setCell(0, 0, new StringCell("hello"));
    ob.setCell(1, 0, new DoubleCell(3.14));
    ob.setCell(1, 1, new StringCell("val"));
    ob.setCell(0, 1, new IntCell(100));

    ob.print();

    AbstractCell* cell = ob.getCell(1, 1);
    if (cell != nullptr) {
        cell->setString("new");
    }    
    ob.print();
    delete newStringCell;

    return 0;
}
