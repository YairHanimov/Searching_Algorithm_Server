//
// Created by eyal on 16.1.2020.
//

#ifndef SEARCHING_ALGORITHM_SERVER_CELL_H
#define SEARCHING_ALGORITHM_SERVER_CELL_H


class Cell {
private:
    int row;
    int col;
public:
    bool operator==(Cell other) {
        if(this->row == other.getRow() && this->col == other.getCol()) {
            return true;
        }
        return false;
    }
    Cell(int row_input, int col_input){
        this->row = row_input;
        this->col = col_input;
    }
    int getRow() {
        return this->row;
    }
    int getCol() {
        return this->col;
    }
};


#endif //SEARCHING_ALGORITHM_SERVER_CELL_H
