//
// Created by Carlos Gonzalez on 2024-12-01.
//

#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <vector>


class Table {

public:
    Table(int rows, int cols);
    ~Table();
    int getRows() const;
    int getCols() const;
    void setRows(int rows);
    void setCols(int cols);
    void setValue(int row, int col, std::string value);
    std::string getValue(int row, int col);
    void printContents(std::ostream& os);
    void printHeaders(std::ostream& os);


private:
    int rows;
    int cols;
    std::vector< std::vector <std::string> > data;
};





#endif //TABLE_H
