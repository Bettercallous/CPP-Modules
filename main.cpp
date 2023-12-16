#include <iostream>

class Base {
	protected:
		int a;
	public:
		Base() {
			// std::cout << &this->a << std::endl;
		}
		Base(int a) : a(a) {
			// this->a = a;
			std::cout << "Base : " << this << std::endl;
		}
		virtual ~Base() {}

		void	print() {
			std::cout << this->a << std::endl;
		}
		void sett() {
			a = 200;
		}
};

class Child: public Base {
	public:
		Child() {
			std::cout << "Child : " << &a << std::endl;
		}
		Child(int a) : Base(a) {
			std::cout << "Child :"  << this + sizeof(Base) << std::endl;
		};
		~Child() {
			// std::cout << "Child destructor called" << std::endl;
		}
		void	print() {
			std::cout << this->a << std::endl;
		}
		void sett() {
			a = 500;
		}
};

int main()
{
	// Base *b1 = new Child();

	// Base b(10);
	Child c(12);


	c.sett();

	// b.print();
	c.print();

}


// #include <iostream>
 
// class base {
// public:
// 	virtual ~base() = 0;
//     void fun_1() { std::cout << "base-1\n"; }
//     virtual void fun_2() { std::cout << "base-2\n"; }
//     virtual void fun_3() { std::cout << "base-3\n"; }
//     virtual void fun_4() { std::cout << "base-4\n"; }
// };
 
// base::~base() {
// 	std::cout << "hello" << std::endl;
// }

// class derived : public base {
// public:
// 	~derived() {}
//     void fun_1() { std::cout << "derived-1\n"; }
//     void fun_2() { std::cout << "derived-2\n"; }
//     void fun_4(int x) { std::cout << "derived-4\n"; }
// };
 
// int main()
// {
//     base* p;
//     derived obj1;
//     p = &obj1;
 
//     // Early binding because fun1() is non-virtual
//     // in base
//     p->fun_1();
 
//     // Late binding (RTP)
//     p->fun_2();
 
//     // Late binding (RTP)
//     p->fun_3();
 
//     // Late binding (RTP)
//     p->fun_4();
 
//     // Early binding but this function call is
//     // illegal (produces error) because pointer
//     // is of base type and function is of
//     // derived class
//     // p->fun_4(5);
 
//     return 0;
// }