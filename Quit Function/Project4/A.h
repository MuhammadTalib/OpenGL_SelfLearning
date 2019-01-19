class A {
public:
	template <class T>
	int getit(int i, T * it) {
		return i;
	}
	template int A::getit<double>(int i, double * it);   // C2252  
														 // try the following line instead  
														 // template <> int A::getit<double>(int i, double * it);  

};


