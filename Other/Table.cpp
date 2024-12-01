//
// Created by Carlos Gonzalez on 2024-12-01.
//

#include "Table.h"

#include <fstream>
#include <iostream>

Table::Table(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->data = std::vector<std::vector<std::string>>(rows, std::vector<std::string>(cols, ""));

}

Table::~Table() = default;

int Table::getRows() const {
    return this->rows;
}

int Table::getCols() const {
    return this->cols;
}

void Table::setRows(int rows) {
    this->rows = rows;
}

void Table::setCols(int cols) {
    this->cols = cols;
}

void Table::setValue(int row, int col, std::string value) {
    if (row >= 0 && row < this->rows && col >= 0 && col < this->cols) {
        this->data[row][col] = value;
    } else {
        std::cout << "[!] -> Invalid row or column index: (" << row << ", " << col << ")" << std::endl;
    }
}

std::string Table::getValue(int row, int col) {
    if (row >= 0 && row < this->rows && col >= 0 && col < this->cols) {
        return this->data[row][col];
    } else {
        std::cout << "[!] -> Invalid row or column index: (" << row << ", " << col << ")" << std::endl;
        return ""; // Return an empty string for invalid indices
    }
}

void Table::printContents(std::ostream& os) {
    for (int i = 0; i < this->rows; i++) {  // For one row, this will execute once
        for (int j = 0; j < this->cols; j++) {
            os << this->data[i][j];
            if (j < this->cols - 1) {
                os << ","; // Add commas between columns
            }
        }
        os << "\n"; // Add a newline after the row
    }
}

void Table::printHeaders(std::ostream& os) {

    for (int i = 0; i < this->rows; i++) {

        // Printing only to each column, excluding index 0
        if (i!=0) {
            os << data[i][0];
        } else {
            os << ",";
        }

        // Printing at each row only at index 0
        for (int j = 0; j < this->cols; j++) {
            if (j==0) {
                os << data[i][j];
            } else {
                os << ",";
            }
        }
    }
}

