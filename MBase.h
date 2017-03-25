#define CLASS(ID) class ID{public:ID(int a) {std::cout << #ID "constructor" << std::endl;}~ID() {std::cout << #ID "destructor" << std::endl;}};


#ifndef MBASE_H
#define MBASE_H




#include<string>
#include<iostream>




namespace MBASE {


	CLASS(Base1);
	CLASS(Member1);
	CLASS(Member2);
	CLASS(Member3);
	CLASS(Member4);


	class Base {
	public:
		int f() const;
		int f(std::string) const;
		void g();
	};

	class Derived1 :public Base {
	public:void g() const;
	};


	class Derived2 :public Base {
	public:
		int f() const;
	};


	class Derived3 :public Base {
	public:
		void f() const;
	};


	class Derived4 :public Base {
	public:
		int f(int) const;
	};



	class Derived11 :public Base1 {
	private:
		Member1 m1;
		Member2 m2;
	public:
		Derived11(int);
		~Derived11();
	};



	class GameBoard {
	public:
		GameBoard();
		GameBoard(const GameBoard&);
		GameBoard &operator=(const GameBoard&);
		~GameBoard();
	};
	class Game {
	private:
		GameBoard gb;
	public:
		Game();
		Game(const Game&);
		Game(int);
		Game &operator=(const Game&);
		class Other {};
		operator Other() const;
		~Game();
	};
	class Chess:public Game{};

	void fGameOther(Game::Other);

	class Checkers :public Game {
	public:
		Checkers();
		Checkers(const Checkers&);
		Checkers &operator=(const Checkers&);
	};


	class CBase {
	public:
		~CBase();
	};

	class CDer1 :public CBase {
	public:
		~CDer1();
	};

	class CBase2 {
	public:
		virtual ~CBase2();
	};
	class CDer2 :public CBase2 {
	public:
		~CDer2();
	};

	class BBase {
	public:
		virtual ~BBase();
		virtual void f();
	};
	class BDerived :public BBase {
	public:
		~BDerived();
		virtual void f() override;
	};



	class MMatrix;
	class MScalar;
	class MVector;
	class MMath {
	public:
		virtual MMath &operator*(MMath&) = 0;
		virtual MMath &multiply(MMatrix*) = 0;
		virtual MMath &multiply(MScalar*) = 0;
		virtual MMath &multiply(MVector*) = 0;
		virtual ~MMath(){}
	};

	class MMatrix :public MMath {
	public:
		MMath &operator*(MMath &rv) override;
		MMath &multiply(MMatrix*) override;
		MMath &multiply(MScalar*) override;
		MMath &multiply(MVector*) override;
	};

	class MScalar :public MMath {
	public:
		MMath &operator*(MMath &rv) override;
		MMath &multiply(MMatrix*) override;
		MMath &multiply(MScalar*) override;
		MMath &multiply(MVector*) override;
	};


	class MVector :public MMath {
	public:
		MMath &operator*(MMath &rv) override;
		MMath &multiply(MMatrix*) override;
		MMath &multiply(MScalar*) override;
		MMath &multiply(MVector*) override;
	};




	class MObject {
	public:
		virtual ~MObject() = 0;
	};

	class MStack {
	private:
		struct Link {
			MObject *data;
			Link *next;
			Link(MObject *dat, Link *nxt) :data(dat), next(nxt) {}
		} *head;
	public:
		MStack() :head(0) {}
		~MStack() {
			while (head) {
				delete pop();
			}
		}

		void push(MObject *dat) {
			head = new Link(dat, head);
		}

		MObject *peek() const {
			return head ? head->data : 0;
		}

		MObject *pop() {
			if (!head)
				return 0;
			MObject *result = head->data;
			Link *oldHead = head;
			head = head->next;
			delete oldHead;
			return result;
		}
	};


}

#endif // !MBASE_H
