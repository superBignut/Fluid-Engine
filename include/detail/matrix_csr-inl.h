#ifndef INCLUDE_BIG_MATRIXCSR_INL_H_
#define INCLUDE_BIG_MATRIXCSR_INL_H_
namespace big
{
    template <typename T, typename VE>
    MatrixCsrVectorMul<T, VE>::MatrixCsrVectorMul(const MatrixCsr<T> &m, const VE &v) : _m(m), _v(v)
    {
        assert(_m.cols() == _v.size());
    }

    template <typename T, typename VE>
    MatrixCsrVectorMul<T, VE>::MatrixCsrVectorMul(const MatrixCsrVectorMul &other) : _m(other._m), _v(other._v) {}

    template <typename T, typename VE>
    std::size_t MatrixCsrVectorMul<T, VE>::size() const
    {
        return _m.rows();
    }

    template <typename T, typename VE>
    T MatrixCsrVectorMul<T, VE>::operator[](std::size_t i) const
    {
        auto nnz = _m.nonZeroBegin();
        auto rp = _m.rowPointerBegin();
        auto ci = _m.colIndexBegin();

        std::size_t colBegin = rp[i];
        std::size_t colEnd = rp[i + 1];
        T sum = 0;
        for (std::size_t j = colBegin; j < colEnd; ++j)
        {
            std::size_t jj = ci[j];
            sum += nnz[j] * _v[jj];
        }
        return sum;
    }

    template <typename T, typename ME>
    MatrixCsrMatrixMul<T, ME>::MatrixCsrMatrixMul(const MatrixCsr<T> &m1, const ME &m2)
        : _m1(m1),
          _m2(m2),
          _nnz(m1.nonZeroData()),
          _rp(m1.rowPointerData()),
          _ci(m1.colIndexData())
    {
        assert(m1.cols() == m2.rows());
    }

    template <typename T, typename ME>
    Size2 MatrixCsrMatrixMul<T, ME>::size() const
    {
        return Size2(_m1.rows(), _m2.cols());
    }

    template <typename T, typename ME>
    std::size_t MatrixCsrMatrixMul<T, ME>::rows() const
    {
        return _m1.rows();
    }

    template <typename T, typename ME>
    std::size_t MatrixCsrMatrixMul<T, ME>::cols() const
    {
        return _m2.cols();
    }

    template <typename T, typename ME>
    T MatrixCsrMatrixMul<T, ME>::operator()(std::size_t i, std::size_t j) const
    {
        std::size_t colBegin = _rp[i];
        std::size_t colEnd = _rp[i + 1];
        T sum = 0;
        for (std::size_t k = colBegin; k < colEnd; ++k)
        {
            std::size_t col = _ci[k];
            sum += _nnz[k] * _m2(col, j);
        }
        return sum;
    }

    template <typename T>
    MatrixCsr<T>::Element::Element()
        : i(0), j(0), value(0) {}

    template <typename T>
    MatrixCsr<T>::Element::Element(std::size_t i_, std::size_t j_, const T &value_)
        : i(i_), j(j_), value(value_) {}

    template <typename T>
    MatrixCsr<T>::MatrixCsr()
    {
        clear();
    }
    template <typename T>
    MatrixCsr<T>::MatrixCsr(const std::initializer_list<std::initializer_list<T>> &lst, T epslion)
    {
        compress(lst, epslion);
    }

    template <typename T>
    template <typename E>
    MatrixCsr<T>::MatrixCsr(const MatrixExpression<T, E> &other, T epslion)
    {
        compress(other, epslion);
    }

    template <typename T>
    MatrixCsr<T>::MatrixCsr(const MatrixCsr &other, T epslion)
    {
        compress(other, epslion);
    }

    template <typename T>
    MatrixCsr<T>::MatrixCsr(const MatrixCsr &&other)
    {
        *this = std::move(other);
    }

    template <typename T>
    void MatrixCsr<T>::clear()
    {
        _size = {0, 0};
        _nonZeros.clear();
        _colIndex.clear();
        _rowPtr.clear();
        _rowPtr.push_back(0);
    }
    template <typename T>
    void MatrixCsr<T>::set(T s)
    {
        std::fill(_nonZeros.begin(), _nonZeros.end(), s);
    }

    template <typename T>
    void MatrixCsr<T>::set(const MatrixCsr &other)
    {
        _size = other._size;
        _nonZeros = other._nonZeros;
        _colIndex = other._colIndex;
        _rowPtr = other._rowPtr;
    }

    template <typename T>
    void MatrixCsr<T>::reserve(std::size_t rows, std::size_t cols, std::size_t numNonZeros)
    {
        _size = {rows, cols};
        _nonZeros.resize(numNonZeros);
        _colIndex.resize(numNonZeros);
        _rowPtr.resize(rows + 1);
    }

    template <typename T>
    void MatrixCsr<T>::compress(const std::initializer_list<std::initializer_list<T>> &lst, T epslion)
    {
        std::size_t numRows = lst.size();
        std::size_t numCols = numRows != 0 ? lst.begin()->size() : 0;

        _size = {numRows, numCols};
        _nonZeros.clear();
        _colIndex.clear();
        _rowPtr.clear();

        auto rowIter = lst.begin();
        for (std::size_t i = 0; i < numRows; ++i)
        {
            assert(rowIter->size() == numCols && "lst has different columns.");
            _rowPtr.push_back(_nonZeros.size());
            auto col_ptr = rowIter->begin();
            for (std::size_t j = 0; j < numCols; ++j)
            {
                if (std::fabs(*col_ptr) > epslion)
                {
                    _nonZeros.push_back(*col_ptr);
                    _colIndex.push_back(j);
                }
                ++col_ptr;
            }
            ++rowIter;
        }
        _rowPtr.push_back(_nonZeros.size()); // which is seted for colEnd = _rp[i + 1];
    }

    template <typename T>
    template <typename E>
    void MatrixCsr<T>::compress(const MatrixExpression<T, E> &other, T epslion)
    {
        const E &m = other();
        std::size_t numRows = m.rows();
        std::size_t numCols = m.cols();

        _size = {numRows, numCols};
        _nonZeros.clear();
        _colIndex.clear();
        _rowPtr.clear();
        for (std::size_t i = 0; i < numRows; ++i)
        {
            _rowPtr.push_back(_nonZeros.size());
            for (std::size_t j = 0; j < numCols; ++j)
            {
                if (std::fabs(m(i, j)) > epslion)
                {
                    _nonZeros.push_back(m(i, j));
                    _colIndex.push_back(j);
                }
            }
        }
        _rowPtr.push_back(_nonZeros.size()); // which is seted for colEnd = _rp[i + 1];
    }

    template <typename T>
    void MatrixCsr<T>::show() const
    {
        // std::cout <<_nonZeros.size()<<std::endl;
        // for(int i =0; i< _nonZeros.size();++i)
        //     std::cout << _nonZeros[i];
    }

    template <typename T>
    void MatrixCsr<T>::addElement(std::size_t i, std::size_t j, T value)
    {
        addElement({i, j, value});
    }
    template <typename T>
    void MatrixCsr<T>::addElement(const Element &element)
    {
        ssize_t numRowsToAdd = (ssize_t)element.i - (ssize_t)_size.x + 1;
        if (numRowsToAdd > 0)
        {
            for (ssize_t i = 0; i < numRowsToAdd; ++i)
            {
                addrow({}, {});
            }
        }

        _size.y = std::max(_size.y, element.j + 1);
        std::size_t rowBegin = _rowPtr[element.i + 1];
        std::size_t rowEnd = _rowPtr[element.i + 1];

        auto colIndexIter = std::lower_bound(_colIndex.begin() + rowBegin, _colIndex.end() + rowEnd, element.j);
        auto offset = colIndexIter - _colIndex.begin();
        _colIndex.insert(colIndexIter, element.j);
        _nonZeros.insert(_nonZeros.begin() + offset, element.value);
        for (std::size_t i = element.i + 1; i < _rowPtr.size(); ++i)
        {
            ++_rowPtr[i];
        }
    }

    template <typename T>
    void MatrixCsr<T>::addRow(const NonZeroContainterType &nonZeros, const IndexContainterType &columnIndex)
    {
        assert(nonZeros.size() == columnIndex.size());
        ++_size.x;
        std::vector<std::pair<T, std::size_t>> zipped;
        for (std::size_t i = 0; i < nonZeros.size(); ++i)
        {
            zipped.emplace_back(nonZeros[i], columnIndex[i]);
            _size.y = std::max(_size.y, nonZeros.size()); //_size.y is just allowed bigger
        }
        std::sort(zipped.begin(), zipped.end(), [](std::pair<T, std::size_t> a, std::pair<T, std::size_t> b)
                  { return a.second < b.second; });
        for (std::size_t i = 0; i < zipped.size(); ++i)
        {
            _nonZeros.push_back(zipped[i].first);
            _colIndex.push_back(zipped[i].second);
        }
        _rowPtr.push_back(_nonZeros.size());
    }

} // namespace big

#endif