#ifndef DIAGONAL_MATRIX_HPP
#define DIAGONAL_MATRIX_HPP

#include "Base.hpp"
#include "Triangular_data.hpp"

namespace linarg
{

    template<typename T, typename Tr>
    class Triangular_matrix : public Base<Triangular_tag, T, Array<T>>
    {
        static_assert (traits::is_one_of<Tr, Lower, Upper, Diagonal>(),
                       "Ivalid type of second parameter- must be one of: Lower, Upper or Diagonal.");

    private:

        using self_type         = Triangular_matrix<T, Tr>;

    public:

        using triangular_fill_type = Tr;
        using base                 = Base<Triangular_tag, T, Array<T>>;
        using matrix_type          = typename base::matrix_type;
        using value_type           = typename base::value_type;
        using reference            = typename base::reference;
        using const_reference      = typename base::const_reference;
        using pointer              = typename base::pointer;
        using const_pointer        = typename base::const_pointer;
        using size_type            = typename base::size_type;
        using allocator_type       = typename base::allocator_type;

        explicit Triangular_matrix(const allocator_type& alloc = allocator_type{});

        explicit Triangular_matrix(size_type size, value_type value, const allocator_type& alloc = allocator_type{});

        explicit Triangular_matrix(const Square_size& size, value_type value, const allocator_type& alloc = allocator_type{});

        template<typename U, typename = std::enable_if_t<std::is_same_v<U, typename traits::Get_type<is_complex<T>::value, T>::type>>>
        explicit Triangular_matrix(size_type size, Random<U> random, const allocator_type& alloc = allocator_type());

        template<typename Function>
        explicit Triangular_matrix(size_type size, Function function, const allocator_type& alloc = allocator_type{});

        explicit Triangular_matrix(const std::vector<T>& vector, const allocator_type& alloc = allocator_type{});

        explicit Triangular_matrix(const Vector<T>& vector, const allocator_type& alloc = allocator_type{});

        explicit Triangular_matrix(const Triangular_matrix& copy);

        explicit Triangular_matrix(Triangular_matrix&& move);

        Triangular_matrix& operator=(const Triangular_matrix& rhs);

        Triangular_matrix& operator=(Triangular_matrix&& rhs);

        template<typename U>
        Triangular_matrix& operator=(Random<U> random);

        virtual reference operator()(size_type i, size_type j) override;

        virtual const_reference operator()(size_type i, size_type j) const override;

        virtual reference at(size_type i, size_type j) override;
    };

} // namespace linarg

#endif // DIAGONAL_MATRIX_HPP
