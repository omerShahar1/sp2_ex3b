#include <iostream>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        vector<vector<double>> mat;
        int length;
        int width;

    public:
        Matrix(vector<double>, int, int);
        double at(size_t, size_t) const;
        int get_length() const;
        int get_width() const;

        Matrix operator + (Matrix const &temp)const; // A + B
        Matrix operator + (double)const;
        Matrix operator + ()const; // +A

        Matrix operator - (Matrix const &temp)const; // A - B
        Matrix operator - (double)const;
        Matrix operator - ()const; // -B

        Matrix operator += (Matrix const &temp); // A += B
        Matrix operator += (double);
        Matrix operator -= (Matrix const &temp); // A -= B
        Matrix operator -= (double);

        bool operator == (Matrix const &temp)const; // A == B
        bool operator >= (Matrix const &temp)const; // A >= B
        bool operator <= (Matrix const &temp)const; // A <= B
        bool operator < (Matrix const &temp)const; // A < B
        bool operator > (Matrix const &temp)const; // A > B
        bool operator != (Matrix const &temp)const; // A != B

        Matrix operator -- ();  // --A
        Matrix operator ++ ();  // ++A
        Matrix operator -- (int);  //  A--
        Matrix operator ++ (int);  //  A++
        
        Matrix operator * (Matrix const &temp)const; // A * B
        Matrix operator * (double)const; // A * 3
        Matrix operator *= (Matrix const &temp); // A *= B
        Matrix operator *= (double); // A *= 3

        friend ostringstream &operator << (ostringstream &output, Matrix const &temp);
        friend istringstream &operator >> (istringstream &input, Matrix &temp);
    };
    
    Matrix operator * (double num, Matrix const &temp); // 3 * A
    Matrix operator *= (double num, Matrix &temp); // 3 *= A
}