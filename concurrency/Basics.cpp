#include "stdafx.h"

#include "Basics.h"

namespace concurrency
{

	namespace basics
	{
		namespace
		{
			
			void foo()
			{
				std::cout << "Function which executes in different thread" << std::endl;
			}

			class Worker
			{
			public:
				void operator()() const
				{
					std::cout << "Function object which executes in different thread" << std::endl;
				}
			};

			class WorkerWithCounter
			{
			public:
				WorkerWithCounter(int counter) : _counter(counter) {}

				void operator()()
				{
					std::cout << "Function object which executes in different thread" << std::endl;
					_counter += 10;
				}

				int counter() const
				{
					return _counter;
				}

			private:
				int _counter;
			};

		}

		/* Constructors
			thread();

			(1)	(since C++11)
			thread( thread&& other );

			(2)	(since C++11)
			template< class Function, class... Args >
			explicit thread( Function&& f, Args&&... args );

			(3)	(since C++11)
			thread(const thread&) = delete;
		*/
		void launching_threads()
		{
			std::thread t1(foo);
			t1.join();

			std::thread t2((Worker()));
			t2.join();

			WorkerWithCounter wwc(100);
			std::thread t3(std::ref(wwc));
			t3.join();
			std::cout << wwc.counter() << std::endl;
		}

	} // basics

} // concurrency