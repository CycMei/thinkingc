

#include"MBase.h"







namespace MBASE {

	inline int Base::f() const {
		std::cout << "base::f()" << std::endl;
		return 1;
	}

	inline int Base::f(std::string str) const {
		std::cout << "base::f(std::string)" << std::endl;
		return 1;
	}

	inline void Base::g() {
		std::cout << "base::g" << std::endl;
	}



	inline void Derived1::g() const {
		std::cout << "derived1::g" << std::endl;
	}


	inline int Derived2::f() const {
		std::cout << "derived2::f()" << std::endl;
		return 1;
	}


	inline void Derived3::f() const {
		std::cout << "derived3::f()" << std::endl;
	}



	inline int Derived4::f(int i) const {
		std::cout << "derived4::f()" << std::endl;
		return 1;
	}


	inline Derived11::Derived11(int i) :m2(1), m1(2), Base1(3) {
		std::cout << "derived11 constructor.." << std::endl;
	}

	inline Derived11::~Derived11() {
		std::cout << "Derived11 destrcutor  " << std::endl;
	}






	inline GameBoard::GameBoard() {
		std::cout << "GameBoard()" << std::endl;
	}

	inline GameBoard::GameBoard(const GameBoard&) {
		std::cout << "GameBoard(const GameBoard&)" << std::endl;
	}

	inline GameBoard &GameBoard::operator=(const GameBoard&) {
		std::cout << "GameBoard::operator=" << std::endl;
		return *this;
	}

	inline GameBoard::~GameBoard() {
		std::cout << "GameBoard::~GameBoard" << std::endl;
	}






	inline Game::Game() {
		std::cout << "Game::Game()" << std::endl;
	}

	inline Game::Game(const Game &g) :gb(g.gb) {
		std::cout << ":Game(const Game &g" << std::endl;
	}

	inline Game::Game(int) {
		std::cout << ":Game(int)" << std::endl;
	}

	inline Game &Game::operator=(const Game &g) {
		gb = g.gb;
		std::cout << "Game::operator=" << std::endl;
		return *this;
	}


	inline Game::operator Other() const {
		std::cout << "Game::operator Other()" << std::endl;
		return Other();
	}
	

	inline Game::~Game() {
		std::cout << "Game::~Game()" << std::endl;
	}






	void fGameOther(Game::Other) {

	}

	inline Checkers::Checkers() {
		std::cout << "Checkers::Checkers" << std::endl;
	}

	inline Checkers::Checkers(const Checkers &c) :Game(c) {
		std::cout << "Checkers(const Checkers &c)" << std::endl;
	}

	inline Checkers &Checkers::operator=(const Checkers &c) {
		Game::operator=(c);
		std::cout << "Checkers::operator=(" << std::endl;
		return *this;
	}

	inline CBase::~CBase() {
		std::cout << "CBase::~CBase" << std::endl;
	}

	inline CDer1::~CDer1() {
		std::cout << "CDer1::~CDer1" << std::endl;
	}

	inline CBase2::~CBase2() {
		std::cout << "CBase2::~CBase2" << std::endl;
	}

	inline CDer2::~CDer2() {
		std::cout << " CDer2::~CDer2()" << std::endl;
	}


	inline BBase::~BBase() {
		std::cout << "BBase::~BBase()" << std::endl;
		f();
	}

	inline void BBase::f() {
		std::cout << "BBase::f()" << std::endl;
	}

	inline BDerived::~BDerived() {
		std::cout << "BDerived::~BDerived()" << std::endl;
	}

	inline void BDerived::f() {
		std::cout << " BDerived::f()" << std::endl;
	}




	inline MMath &MMatrix::operator*(MMath &rv){
		return rv.multiply(this);
	}

	inline MMath &MMatrix::multiply(MMatrix*) {
		std::cout << "MMatrix * MMatrix" << std::endl;
		return *this;
	}

	inline MMath &MMatrix::multiply(MScalar*) {
		std::cout << "MScalar * MMatrix" << std::endl;
		return *this;
	}

	inline MMath &MMatrix::multiply(MVector*) {
		std::cout << "MVector * MMatrix" << std::endl;
		return *this;
	}


	inline MMath &MScalar::operator*(MMath &rv) {
		return rv.multiply(this);
	}

	inline MMath &MScalar::multiply(MMatrix*) {
		std::cout << "MMatrix * MScalar" << std::endl;
		return *this;
	}

	inline MMath &MScalar::multiply(MScalar*) {
		std::cout << "MScalar * MScalar" << std::endl;
		return *this;
	}

	inline MMath &MScalar::multiply(MVector*) {
		std::cout << "MVector * MScalar" << std::endl;
		return *this;
	}



	inline MMath &MVector::operator*(MMath &rv) {
		return rv.multiply(this);
	}

	inline MMath &MVector::multiply(MMatrix*) {
		std::cout << "MMatrix * MVector" << std::endl;
		return *this;
	}

	inline MMath &MVector::multiply(MScalar*) {
		std::cout << "MScalar * MVector" << std::endl;
		return *this;
	}

	inline MMath &MVector::multiply(MVector*) {
		std::cout << "MVector * MVector" << std::endl;
		return *this;
	}



	inline MObject::~MObject() {

	}


}


void MBaseTest1() {
	using namespace MBASE;
	std::string s("hello");
	Derived1 d1;
	int x = d1.f();
	d1.f(s);
	d1.g();

	std::cout << std::endl;

	Derived2 d2;
	x = d2.f();
	//d2.f(s);
	std::cout << std::endl;

	Derived3 d3;
	d3.f();

	std::cout << std::endl;

	Derived4 d4;
	d4.f(2);


	std::cout << std::endl;
	Derived11 d11(x);

}

void MBaseTest2() {
	using namespace MBASE;
	Chess d1;
	Chess d2(d1);
	//Chess d3(1);
	d1 = d2;
	fGameOther(d1);
	Game::Other go;
	//d1 = go;
	Checkers c1, c2(c1);
	c1 = c2;
}

void MBaseTest3() {
	using namespace MBASE;
	CBase *bp = new CDer1();
	delete bp;
	CBase2 *bp1 = new CDer2();

	delete bp1;

}

void MBaseTest4() {
	using namespace MBASE;
	BBase *bp = new BDerived();
	delete bp;
}


void MBaseTest5() {
	using namespace MBASE;
	MMatrix m;
	MVector v;
	MScalar s;
	MMath *math[] = { &m,&v,&s };
	for (int i = 0; i != 3; ++i) {
		for (int j = 0; j != 3; ++j) {
			MMath &m1 = *math[i];
			MMath &m2 = *math[j];
			m1*m2;
		}
	}

}