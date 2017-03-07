#include <iostream>

namespace stroustrup
{
	namespace chapter3
	{
		namespace N2_1_1
		{
			class complex
			{
			public:
				complex(double re, double im)
					: _re(re)
					, _im(im)
				{}

				complex(double re)
					: _re(re)
					, _im(0)
				{}

				complex()
					: _re(0)
					, _im(0)
				{}

			public:
				double real() const
				{
					return _re;
				}

				double imag() const
				{
					return _im;
				}

				void real(double re)
				{
					_re = re;
				}

				void imag(double im)
				{
					_im = im;
				}

			public:
				complex& operator+=(const complex& other)
				{
					_re += other._re;
					_im += other._im;
					return *this;
				}

				complex& operator-=(const complex& other)
				{
					_re -= other._re;
					_im -= other._im;
					return *this;
				}

				complex& operator*=(const complex& other);
				
				complex& operator/=(const complex& other);

			private:
				double _re;
				double _im;
			};

			inline complex operator+(const complex& c1, const complex& c2)
			{
				complex c3;
				return (c3 += c1) += c2;
			}
		}
	}
}