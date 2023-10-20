#include "vector_field2.h"

namespace big
{

    VectorField2::VectorField2()
    {
    }

    VectorField2::~VectorField2()
    {
    }
    double VectorField2::divergence(const Vector2D &x)
    {
        return 0.0;
    }

    double VectorField2::curl(const Vector2D &x) const
    {
        return 0.0;
    }

    std::function<Vector2D(const Vector2D &)> VectorField2::sampler() const
    {
        return [this](const Vector2D &x)
        {
            return this->sample(x);
        };
    }

} // namespace big
