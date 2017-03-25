#include "stdafx.h"
#include "Vector.hpp"

namespace stroustrup
{

	namespace tutorial
	{
		Vector::Vector(std::initializer_list<double> list)
			: _elems(new double[list.size()])
			, _size(list.size())
		{
			std::copy(list.begin(), list.end(), _elems);
		}

		Vector::Vector(int size = 0)
			: _elems(new double[size])
			, _size(size)
		{}

		Vector::Vector(const Vector& other)
			: _elems(new double(other._size))
			, _size(other._size)
		{
			for (auto i = 0; i < other._size; ++i)
			{
				_elems[i] = other._elems[i];
			}
		}

		Vector& Vector::operator=(const Vector& other)
		{
			auto * tmp = new double[other._size];
			for (auto i = 0; i < other._size; ++i)
			{
				tmp[i] = other._elems[i];
			}
			delete[] _elems;
			_elems = tmp;
			_size = other._size;
			return *this;
		}

		Vector::Vector(Vector&& other)
			: _elems(other._elems)
			, _size(other._size)
		{
			other._elems = nullptr;
			other._size = 0;
		}

		Vector& Vector::operator=(Vector&& other)
		{
			_elems = other._elems;
			_size = other._size;

			other._elems = nullptr;
			other._size = 0;

			return *this;
		}
		
		void Vector::push_back(double val)
		{
			
			//if (_size < _capacity)
			//{
				_elems[_size + 1] = val;
				_size++;
			//}
			//else
			//{
			//	auto tmp = new double[_size * 2];
			//	for (auto i = 0; i < _size; ++i)
			//	{
			//		tmp[i] = _elems[i];
			//	}
			//	tmp[_size + 1] = val;
			//	_size++;
			//	_elems = tmp;
			//}
		}

	} // namespace tutorial

} // namespace stroustrup