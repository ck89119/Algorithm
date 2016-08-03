#include <iostream>

class Complex {
 public:
  Complex() {};
  Complex(double real, double image): real_(real), image_(image) {};
  Complex operator + (const Complex& a);
  Complex operator - (const Complex& a);
  Complex operator * (const Complex& a);
  Complex operator / (const Complex& a);
  friend std::ostream& operator << (std::ostream& out, const Complex& a) {
    out << a.real_ << " + " << a.image_ << "i";
    return out;
  }

 private:
  double real_, image_;
  
};

Complex Complex::operator + (const Complex& a) {
  return Complex(real_ + a.real_, image_ + a.image_);
}

Complex Complex::operator - (const Complex& a) {
  return Complex(real_ - a.real_, image_ - a.image_);
}

Complex Complex::operator * (const Complex& a) {
  return Complex(real_ * a.real_ - image_ * a.image_, real_ * a.image_ + a.real_ * image_);
}

Complex Complex::operator / (const Complex& a) {
  double s = a.real_ * a.real_ + a.image_ * a.image_;
  return Complex((real_ * a.real_ + image_ * a.image_) / s, (image_ * a.real_ - real_ * a.image_) / s);
}

// int main() {
//   Complex a(2, 3);
//   Complex b(1, -2);
//   std::cout << a / b << std::endl;
//   return 0;
// }
