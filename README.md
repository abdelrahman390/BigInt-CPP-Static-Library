## BigInt C++ Static Library
- is a C++ library to perform mathematical operations on integers of virtually unlimited size, overcoming the limitations of native C++ integer types
  
## Features

- Support for extremely large integers (limited only by system memory)
- Four fundamental arithmetic operations:
  - Addition (`+`, `+=`, `AddNumbers`)
  - Subtraction (`-`, `-=`, `deleteNumbers`)
  - Multiplication (`*`, `multiplication`)
  - Division (`/`, `Division`)
- Increment (`++`) and decrement (`--`) operators
- Stream output support (`<<`)
- Multiple constructor options:
  - From string (`BigInt("123")`)
  - From C-string (`BigInt("123")`)
  - From integer (`BigInt(123)`)
  - Default constructor (`BigInt()`)

  # How to use it:
  - Build the library project, and link the library probably.
  - Include this line in your main.cpp: #include "../mathLongOperations/mathLongOperations.h"
  - Example of how to use it:


  ```cpp
  int main() {  
	cout << "addition: " <<  add("10000000000000000000000000000000000000000", "100") << endl;  
	cout << "delete: " << deleteNum("1000", "100") << endl;  
	cout << "multiplication: " << multiplication("9", "100") << endl;  
	cout << "division: " << division("1000", "100") << endl;  
	//************** Direct operations **************  


	BigInt j = 1;  
	cout << "j: " << j << endl;  
	BigInt k = j;  
	cout << "k: " << k << endl;  
	BigInt m = j + k;  
	cout << "m: " << m << endl;  
	//************** Simple operation **************  

	BigInt a("123");  
	BigInt b = a++;  
	cout << "b: " << b << endl;  
	// ************** BigInt operator++(int) **************  

	BigInt o = 1;  
	o++;  
	cout << "o: " << o << endl;  
	// ************** void operator++(int) **************  

	BigInt p = 1;  
	p += 10;  
	cout << "p: " << p << endl;  
	// ************** BigInt operator += (int n) **************  

	BigInt v = 10;  
	BigInt e = 1;  
	e += v;  
	cout << "e: " << e << endl;  
	// ************** BigInt operator += (BigInt& n) **************  

	BigInt z = 10;  
	cout << "Division: " << z.Division("7") << endl; // Error  
	BigInt w = 8127;  
	cout << "Division: " << w.Division("9") << endl; // 903  
	BigInt q = "100000000000000000000000000000000000000000000000000000000000000000000000";  
	cout << "Division: " << q.Division("2") << endl; // 50000000000000000000000000000000000000000000000000000000000000000000000  
	// ************** Division **************  

	BigInt i = "1000000000000000000000000000000000000000000000000000000000000000";  
	cout << "Multiplication: " << i.multiplication("2") << endl;  
	// ************** Multiplication **************  

	BigInt u = 1999;  
	cout << "Addition: " << u.AddNumbers("1") << endl;  
	// ************** Addition **************  

	BigInt c = 2000;  
	cout << "Subtraction: " << c.deleteNumbers("1") << endl;  
	// ************** Subtraction **************  
}
```    

