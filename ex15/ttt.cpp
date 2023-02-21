
template <class T = double>
class Complex {
  T real;
  T imag;

public:
  Complex(T real, T imag) : real(real), imag(imag) {}

  T getReal() const { return real; }
  T getImag() const { return imag; }
};

int main() {
  Complex<> u(1,1);
  return 0;
}
