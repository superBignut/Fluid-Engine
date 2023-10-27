#ifndef INCLUDE_BIG_MATRIX4X4_H_
#define INCLUDE_BIG_MATRIX4X4_H_
#include "matrix3x3.h"
#include "vector4.h"
namespace big
{
    template <typename T>
    class Matrix<T, 4, 4>
    {
    public:
        static_assert(std::is_floating_point<T>::value, "Matrix only can be instantiated with float point types.");

        Matrix();

        explicit Matrix(T s);

        Matrix(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22);

        Matrix(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33);

        Matrix(const std::initializer_list<std::initializer_list<T>> &lst);

        Matrix(const Matrix &m);

        Matrix(const Matrix3x3<T> &m33);

        //! row-major
        explicit Matrix(const T *arr);

        void set(T s);

        void set(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22);

        void set(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33);

        void set(const Matrix3x3<T> &m33);

        void set(const std::initializer_list<std::initializer_list<T>> &lst);

        void set(const Matrix &m);

        void set(const T *arr);

        void setDiagnoal(T s);

        void setOffDiagnoal(T s);

        void setRow(std::size_t i, const Vector<T, 4> &row);

        void setCol(std::size_t i, const Vector<T, 4> &col);

        bool isSimilar(const Matrix &other, double tol = std::numeric_limits<double>::epsilon()) const;

        constexpr bool isSquare() const;

        constexpr std::size_t rows() const;

        constexpr std::size_t cols() const;

        T *data();

        const T *const data() const;

        Matrix add(T val) const;

        Matrix add(const Matrix &other) const;

        Matrix sub(T val) const;

        Matrix sub(const Matrix &other) const;

        Matrix mul(T val) const;

        Matrix mul(const Matrix &other) const;

        Vector<T, 4> mul(const Vector<T, 4> &v) const;

        Matrix div(T val) const;

        Matrix radd(T val) const;

        Matrix radd(const Matrix &other) const;

        Matrix rsub(T val) const;

        Matrix rsub(const Matrix &other) const;

        Matrix rmul(T val) const;

        Matrix rmul(const Matrix &other) const;

        Matrix rdiv(T val) const;

        void iadd(T val);

        void iadd(const Matrix &other);

        void isub(T val);

        void isub(const Matrix &other);

        void imul(T val);

        void imul(const Matrix &other);

        void imul(const Matrix3x3<T> &other);

        void idiv(T val);

        void transpose();

        void invert();

        T sum() const;

        T avg() const;

        T min() const;

        T max() const;

        T absmin() const;

        T absmax() const;

        T trace() const;

        T determinant() const;

        void show() const;

        Matrix diagonal() const;

        Matrix offDiagonal() const;

        Matrix strictLowerTri() const;

        Matrix stricitUpperTri() const;

        Matrix lowerTri() const;

        Matrix upperTri() const;

        Matrix transposed() const;

        Matrix inverse() const;

        T frobeniusNorm() const;

        template <typename U>
        Matrix<U, 4, 4> castTo() const;

        Matrix &operator=(const Matrix &other);

        Matrix &operator+=(T &s);

        Matrix &operator+=(const Matrix &m);

        Matrix &operator-=(T &s);

        Matrix &operator-=(const Matrix &m);

        Matrix &operator*=(T &s);

        Matrix &operator*=(const Matrix &m);

        Matrix &operator*=(const Matrix3x3<T> &m);

        Matrix &operator/=(T &s);

        bool operator==(const Matrix &m) const;

        bool operator!=(const Matrix &other) const;

        // return is T& while matrix_expression's ()() are all T
        T &operator()(std::size_t i, std::size_t j);

        const T &operator()(std::size_t i, std::size_t j) const;

        T &operator[](std::size_t i);

        const T &operator[](std::size_t i) const;

        static Matrix makeZero();

        static Matrix makeIdentity();

        static Matrix makeScaleMatrix(T sx, T sy, T sz);

        static Matrix makeScaleMatrix(const Vector<T, 3> &s);

        static Matrix makeRotationMatrix(const Vector<T, 3> &axis, T rad);

        static Matrix makeTranslationMatrix(const Vector<T, 3> &t);

    private:
        std::array<T, 16> _elements;
    };

    template <typename T>
    using Matrix4x4 = Matrix<T, 4, 4>;

    template <typename T>
    Matrix<T, 4, 4> operator+(const Matrix<T, 4, 4> &a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Matrix<T, 4, 4> operator+(const Matrix<T, 4, 4> &a, T b);

    template <typename T>
    Matrix<T, 4, 4> operator+(T a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Matrix<T, 4, 4> operator-(const Matrix<T, 4, 4> &a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Matrix<T, 4, 4> operator-(const Matrix<T, 4, 4> &a, T b);

    template <typename T>
    Matrix<T, 4, 4> operator-(T a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Matrix<T, 4, 4> operator-(const Matrix<T, 4, 4> &a);

    template <typename T>
    Matrix<T, 4, 4> operator*(const Matrix<T, 4, 4> &a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Matrix<T, 4, 4> operator*(const Matrix<T, 4, 4> &a, T b);

    template <typename T>
    Matrix<T, 4, 4> operator*(T a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Vector<T, 4> operator*(const Matrix<T, 4, 4> &a, const Vector<T, 4> &b);

    template <typename T>
    Vector<T, 3> operator*(const Matrix<T, 4, 4> &a, const Vector<T, 3> &b);

    template <typename T>
    Matrix<T, 4, 4> operator*(const Matrix<T, 4, 4> &a, const Matrix<T, 3, 3> &b);

    template <typename T>
    Matrix<T, 4, 4> operator*(const Matrix<T, 3, 3> &a, const Matrix<T, 4, 4> &b);

    template <typename T>
    Matrix<T, 4, 4> operator/(const Matrix<T, 4, 4> &a, T b);

    template <typename T>
    Matrix<T, 4, 4> operator/(T a, const Matrix<T, 4, 4> &b);

    typedef Matrix<float, 4, 4> Matrix4x4F;

    typedef Matrix<double, 4, 4> Matrix4x4D;

} // namespace big

#include "detail/matrix4x4-inl.h"
#endif