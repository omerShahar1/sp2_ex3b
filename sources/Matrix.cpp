#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Matrix.hpp"

using namespace std;

namespace zich
{
    int Matrix::get_length() const// return matrix length
    {
        return length;
    }

    int Matrix::get_width() const// return matrix width
    {
        return width;
    }

    double Matrix::at(size_t i, size_t j) const// return the element in the [i][j] cell in the matrix.
    {
        return mat[i][j];
    }

    Matrix::Matrix(vector<double> arr, int length, int width) // constructor accept the array of nums, length and width of the metrix
    {
        if(length<=0 || width<=0) // check invalid parameters
        {
            throw invalid_argument("arguments need to be positive");
        }
        if(arr.size() == 1)
        {
            while(arr.size() < length*width)
            {
                arr.push_back(0);
            }
        }
        if(arr.size() != length*width) // check arr size is smaller then length and width parameters
        {
            throw invalid_argument("arr size is not in line with the length and width arguments");
        }

        mat = vector<vector<double>>((size_t)length, vector<double>((size_t)width, 0.0)); // create the matrix as vetor of double value vectors.
        size_t i=0;
        size_t j=0;
        size_t k=0;

        for(i=0; i<length; i++) // insert elements from arr to the matrix object.
        {
            for(j=0; j<width; j++)
            {
                mat[i][j] = (double)arr[k++];
            }
        }
        this->width = width;
        this->length = length;
    }
    
    Matrix Matrix::operator + (Matrix const &temp) const //operator of matrix + matrix (return the new matrix).
    {
        if(length != temp.length || width != temp.width) // check both matrixed are the same size.
        {
            throw invalid_argument("the matrix need to be in the same size");
        }

        vector<double> arr((size_t)width*(size_t)length, 0.0); // the elements of the new matrix
        size_t i=0;
        size_t j=0;
        size_t k=0; // used to go over the elements of the new, returned matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                arr[k++] = mat[i][j] + temp.mat[i][j];
            }
        }
        return Matrix(arr, length, width);
    }
    
    Matrix Matrix::operator + (double num) const// operator of matrix + num
    {
        vector<double> arr((size_t)length*(size_t)width, 0);
        size_t i=0;
        size_t j=0;
        size_t k=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                arr[k++] = mat[i][j] + num;
            }
        }
        return Matrix(arr, length, width);
    }
    
    Matrix Matrix::operator + () const// operator of +matrix (unary plus, return new matrix).
    {
        vector<double> arr((size_t)width*(size_t)length, 0); // the elements of the new matrix
        size_t i=0;
        size_t j=0;
        size_t k=0;  // used to go over the elements of the new, returned matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                arr[k++] = mat[i][j] * 1;
            }
        }
        return Matrix(arr, length, width);
    }

    Matrix Matrix::operator - (Matrix const &temp) const//operator of matrix - matrix (return a new matrix).
    {
        if(length != temp.length || width != temp.width) // check both matrixed are the same size.
        {
            throw invalid_argument("the matrix need to be in the same size");
        }

        vector<double> arr((size_t)width*(size_t)length, 0); // the elements of the new matrix
        size_t i=0;
        size_t j=0;
        size_t k=0;  // used to go over the elements of the new, returned matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                arr[k++] = mat[i][j] - temp.mat[i][j];
            }
        }
        return Matrix(arr, length, width);
    }
    
    Matrix Matrix::operator - (double num) const// operator of matrix - num
    {
        vector<double> arr((size_t)length*(size_t)width, 0);
        size_t i=0;
        size_t j=0;
        size_t k=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                arr[k++] = mat[i][j] - num;
            }
        }
        return Matrix(arr, length, width);
    }
    
    Matrix Matrix::operator - () const// operator of -matrix (unary minus return new matrix).
    {
        vector<double> arr((size_t)width*(size_t)length, 0); // the elements of the new matrix
        size_t i=0;
        size_t j=0;
        size_t k=0;
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                arr[k++] = mat[i][j] * (-1);
            }
        }
        return Matrix(arr, length, width);
    }

    Matrix Matrix::operator += (Matrix const &temp) //operator of matrix += matrix
    {
        if(length != temp.length || width != temp.width) // check both matrixes are the same size
        {
            throw invalid_argument("the matrix need to be in the same size");
        }

        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                mat[i][j] += temp.mat[i][j];
            }
        }
        return *this;
    }
    
    Matrix Matrix::operator += (double num) // operator of matrix += num
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                mat[i][j] += num;
            }
        }
        return *this;
    }
    
    Matrix Matrix::operator -= (Matrix const &temp) //operator of matrix -= matrix
    {
        if(length != temp.length || width != temp.width) // check same size
        {
            throw invalid_argument("the matrix need to be in the same size");
        }

        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                mat[i][j] -= temp.mat[i][j];
            }
        }
        return *this;
    }
    
    Matrix Matrix::operator -= (double num) // operator of matrix -= num
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                mat[i][j] -= num;
            }
        }
        return *this;
    }
    
    bool Matrix::operator == (Matrix const &temp) const // operator matrix == matrix
    {
        if(length != temp.length || width != temp.width) // if matrixes size is diferent throw error.
        {
            throw invalid_argument("matrixes need to be the same size");
        }
        
        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                if(mat[i][j] != temp.mat[i][j]) // if one cell is diferent in the matrixes, then they are not equel.
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Matrix::operator != (Matrix const &temp) const // operator matrix != matrix
    {
        if(length != temp.length || width != temp.width) // if matrixes size is diferent throw error.
        {
            throw invalid_argument("matrixes need to be the same size");
        }
        size_t i=0;
        size_t j=0;

        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                if(mat[i][j] != temp.mat[i][j]) // if one cell is diferent in the matrixes, then they are not equel.
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool Matrix::operator >= (Matrix const &temp) const // operator matrix >= matrix
    {
        if(length != temp.length || width != temp.width) // if matrixes size is diferent throw error.
        {
            throw invalid_argument("matrixes need to be the same size");
        }
        
        size_t i=0;
        size_t j=0;
        double sum1=0; // sum the elements of the left matrix
        double sum2=0; // sum the elements of the right matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                sum1 += mat[i][j];
                sum2 += temp.mat[i][j];
            }
        }
        return(sum1 >= sum2);
    }

    bool Matrix::operator <= (Matrix const &temp) const // operator matrix <= matrix
    {
        if(length != temp.length || width != temp.width) // if matrixes size is diferent throw error.
        {
            throw invalid_argument("matrixes need to be the same size");
        }
        
        size_t i=0;
        size_t j=0;
        double sum1=0; // sum the elements of the left matrix
        double sum2=0; // sum the elements of the right matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                sum1 += mat[i][j];
                sum2 += temp.mat[i][j];
            }
        }
        return(sum1 <= sum2);
    }
    
    bool Matrix::operator < (Matrix const &temp) const // operator matrix < matrix
    {
        if(length != temp.length || width != temp.width) // if matrixes size is diferent throw error.
        {
            throw invalid_argument("matrixes need to be the same size");
        }
        
        size_t i=0;
        size_t j=0;
        double sum1=0; // sum the elements of the left matrix
        double sum2=0; // sum the elements of the right matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                sum1 += mat[i][j];
                sum2 += temp.mat[i][j];
            }
        }
        return(sum1 < sum2);
    }
    
    bool Matrix::operator > (Matrix const &temp) const // operator matrix > matrix
    {
        if(length != temp.length || width != temp.width) // if matrixes size is diferent throw error.
        {
            throw invalid_argument("matrixes need to be the same size");
        }
        
        size_t i=0;
        size_t j=0;
        double sum1=0; // sum the elements of the left matrix
        double sum2=0; // sum the elements of the right matrix
        for(i=0; i<length; i++)
        {
            for(j=0; j<width; j++)
            {
                sum1 += mat[i][j];
                sum2 += temp.mat[i][j];
            }
        }
        return(sum1 > sum2);
    }
    
    Matrix Matrix::operator -- ()  // --x (first change and then return the matrix)
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                mat[i][j]--;
            }
        }
        return *this;
    }
    
    Matrix Matrix::operator ++ ()  // ++x (first change and then return the matrix)
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                mat[i][j]++;
            }
        }
        return *this;
    }
    
    Matrix Matrix::operator -- (int)  //  x-- (first return the matrix and then change it)
    {
        size_t i=0;
        size_t j=0;
        vector<double> tempArr((size_t)width*(size_t)length, 0); // create a copy of the matrix to return
        Matrix temp = Matrix(tempArr, length, width);
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                temp.mat[i][j] = mat[i][j]; // copy old values of the matrix
                mat[i][j]--;
            }
        }
        return temp;
    }
    
    Matrix Matrix::operator ++ (int)  //  x++ (first return the matrix and then change it)
    {
        size_t i=0;
        size_t j=0;
        vector<double> tempArr((size_t)width*(size_t)length, 0); // create a copy of the matrix to return
        Matrix temp = Matrix(tempArr, length, width);
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                temp.mat[i][j] = mat[i][j]; // copy old values of the matrix
                mat[i][j]++;
            }
        }
        return temp;
    }
    
    Matrix Matrix::operator * (Matrix const &temp) const // operator matrix * matrix
    {
        if(width != temp.length) // check same size
        {
            throw invalid_argument("left matrix width need to be equel to right matrix length");
        }

        vector<double> arr((size_t)length*(size_t)(temp.width), 0); // the new matrix
        Matrix ans = Matrix(arr, length, temp.width);
        size_t i=0;
        size_t j=0;
        size_t h=0;
        double sum=0;

        for(i=0; i<length; i++) // go over the main matrix rows
        {
            for(h=0; h<temp.width; h++) // go over the second matrix colums
            {
                for(j=0; j<temp.length; j++) // go over the main matrix elements in the current row, and the second matrix elements in the current colum 
                {
                    sum += (mat[i][j] * temp.mat[j][h]);
                }
                ans.mat[i][h] = sum;
                sum=0;
            }
        }
        return ans;
    }
    
    Matrix Matrix::operator * (double num) const // operator matrix * double
    {
        vector<double> arr((size_t)length*(size_t)width, 0);
        size_t i=0;
        size_t j=0;
        size_t k=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                arr[k++] = mat[i][j] * num;
            }
        }
        return Matrix(arr, length, width);
    }
    
    Matrix Matrix::operator *= (Matrix const &temp) // operator matrix *= matrix
    {
        if(width != temp.length) // check same size
        {
            throw invalid_argument("left matrix width need to be equel to right matrix length");
        }

        vector<double> arr((size_t)length*(size_t)(temp.width), 0); // the new matrix
        Matrix ans = (*this) * temp;
        size_t i=0;
        size_t h=0;

        mat = ans.mat;
        length = ans.length;
        width = ans.width;
        return *this;
    }
    
    Matrix Matrix::operator *= (double num) // operator matrix *= double
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<length; i++) // go over matrix rows
        {
            for(j=0; j<width; j++) // go over matrix colums
            {
                mat[i][j] *= num;
            }
        }
        return *this;
    }
    
    ostringstream &operator << (ostringstream &output, Matrix const &temp) // output the matrix
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<temp.length; i++) // go over matrix rows
        {
            output << "[";
            for(j=0; j<temp.width; j++) // go over matrix collums
            {
                output << temp.mat[i][j];
                if(j != temp.width-1) // saperete cells with ' ' unless it is the last cell in the row.
                {
                    output << " ";
                }
            }
            output << "]";
            if(i != temp.length-1) // saperete rows with '\n' unless it is the last row.
            {
                output << "\n";
            }
        }
        return output;
    }
    
    istringstream &operator >> (istringstream &input, Matrix &temp) // input the matrix
    {   
        if(input.eof()) // if input is empty
        {
            throw invalid_argument("input cant be empty");
        }

        string str = string(1, input.get()); // string represent the value we put in a spesific cell.
        if(str != "[") // need to start with '['
        {
            throw invalid_argument("each raw start with '['");
        }
        str.clear();

        size_t rows=0;
        size_t colls=0;
        size_t colls_first_row=0;
        char c=0;        
        double num=0;
        bool first_row = true;
        vector<double> arr;

        while(!input.eof()) // go over the input untill it is over and put values in to array
        {
            c = input.get();
            if(c==' ') // represent new cell in the raw.
            {
                try
                {
                    arr.push_back(stod(str)); // new element to the array
                }
                catch(const std::exception& e)
                {
                    throw invalid_argument("invalid input");
                }
                colls++;
                str.clear();
            }
            else if(c == ']') // represent new row in the matrix.
            {
                try
                {
                    arr.push_back(stod(str)); // new element to the array
                }
                catch(const std::exception& e)
                {
                    throw invalid_argument("invalid input");
                }
                rows++;
                colls++;
                str.clear();
                if(first_row) // if this is the first raw we build
                {
                    colls_first_row = colls; // we now know how many cells each row need to have
                    first_row = false;
                }
                else if(colls != colls_first_row) // if the current raw has diferent number of cells in it then we throw error.
                {
                    throw invalid_argument("all raws need to have the same number of cells");
                }
    
                while(!input.eof() && c!='[')
                {
                    c = input.get();
                    str += string(1, c); 
                }

                if(input.eof() && str.size()==2)
                {
                    break;
                }
                if(str != ", [")
                {
                    throw invalid_argument("invalid input");
                }
                str.clear();
                colls = 0;
                continue;
            }
            str += string(1, c);
        }
        temp = Matrix(arr, rows, colls_first_row);
        return input;
    }

    Matrix operator * (double num, Matrix const &temp) // if we want to do (3 * matrix) for example. 
    {
        Matrix new_mat = temp * num;
        return new_mat;
    }

    Matrix operator *= (double num, Matrix &temp) // if we want to do (3 *= matrix) for example. 
    {
        return (temp*=num);
    }
}