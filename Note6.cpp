 Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    
     Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    
    Conversion Operator
    
    operator float() const {
        return float(num) / float(den);
    }
    
     Fraction f(2, 5);
    float val = f;
    cout << val;
