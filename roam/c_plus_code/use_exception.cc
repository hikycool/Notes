#include <iostream>

class matrix {
public:
  matrix(size_t nrows, size_t ncols)
    : data_(new float[nrows * ncols]),
      nrows_(nrows),
      ncols_(ncols) {}
  
  ~matrix() {
    delete[] data_;
    data_ = nullptr;
  }

  friend matrix operator* (const matrix& lm,
			   const matrix& rm)
  {
    if (lm.ncols_ != rm.nrows_) {
      throw std::runtime_error("matrix sizes mismatch");
    }

    return lm;
  }

private:
  float *data_;
  size_t nrows_;
  size_t ncols_;

};

int main() {
  return 0;
}
