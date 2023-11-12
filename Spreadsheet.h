#ifndef SPREADSHEET
#define SPREADSHEET
#include "AbstractCell.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Spreadsheet {
    public:
        Spreadsheet() {}
        Spreadsheet(int rows, int cols) : grid(rows, std::vector<AbstractCell*>(cols)) {}

        void addRow(int numRows) {
            int numCols = (grid.empty() ? 0 : grid[0].size());
            std::vector<AbstractCell*> newRow(numCols, nullptr);
            for (int i = 0; i < numRows; ++i) {
                grid.insert(grid.begin(), newRow);
            }
        }

        void addColumn(int numCols, AbstractCell* newCell) {
            for (auto& row : grid) {
                for (int i = 0; i < numCols; ++i) {
                    row.push_back(newCell);
                }
            }
        }

        void removeRow() {
            if (!grid.empty()) {
                grid.pop_back();
            }
        }

        void removeCol() {
            if (!grid.empty() && !grid[0].empty()) {
                for (auto& row : grid) {
                    row.pop_back();
                }
            }
        }

        AbstractCell* getCell(int row, int col) {
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size()) {
                return nullptr;
            }
            return grid[row][col];
        }
        void setCell(int row, int col, AbstractCell* value) {
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
                throw std::out_of_range("Invalid row or column index.");
            }

            grid[row][col] = value;
        }        
        void print() const {
            for (size_t i = 0; i < grid.size(); ++i) {
                std::cout << " ---------------------\n|";
                for (size_t j = 0; j < grid[i].size(); ++j) {
                    if(grid[i][j] != nullptr) {
                        std::cout << " \"" << std::left << grid[i][j]->getString() << std::setw(5) << "\"";
                    } else {
                        std::cout << " " << std::setw(6) << "|";
                    }
                }
                std::cout << "\n";
            }
            std::cout << " ---------------------\n";
        }
    private:
        std::vector<std::vector<AbstractCell*>> grid;
};

#endif
