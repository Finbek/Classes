#include "int_matrix.hpp"

int_matrix::~int_matrix() {
    for (unsigned int i = 0; i < row; i++) {
        delete [] _buf[i];
    }
    delete [] _buf;
}

int_matrix::int_matrix(int row, int col, int a[]){
   this->row = row;
   this->col= col;
   _buf=new int*[row];
   for(int k=0; k<row; k++){
        _buf[k]=new int[col];
   }
   int z=0;
   for(int i=0; i<row; i++){
        for(int m=0; m<col; m++){
                _buf[i][m]=a[z];
                z++;
        }
   }
}

int_matrix::int_matrix(int row, int col, int num){
   this->row= row;
   this->col=col;
   _buf=new int*[row];
   for(int k=0; k<row; k++){
        _buf[k]=new int[col];
   }
   for(int i=0; i<row; i++){
        for(int m=0; m<col; m++){
                _buf[i][m]=num;
        }
   }
}

int int_matrix::at(int i,int j){
   return _buf[i][j];
}

int int_matrix::getRow(){
  return row;
}

int int_matrix::getColumn(){
  return col;
}

int* int_matrix::operator[](int i) {
  return *(_buf + i);
}
