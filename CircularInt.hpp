#ifndef CIRCULARINT_HPP
#define CIRCULARINT_HPP

#pragma once
#include <iostream>
using namespace std;


class CircularInt {
    
	friend CircularInt operator~ (CircularInt const c);
	friend CircularInt operator- (CircularInt const c);
	friend istream& operator>> (istream& is, CircularInt& c);		
	friend ostream& operator<< (ostream& os, const CircularInt& c);	
	
	friend bool operator< (CircularInt const& c1, CircularInt const& c2); 	friend bool operator< (CircularInt const& c, int const& num);	friend bool operator< (int const& num, CircularInt const& c);			
	friend bool operator> (CircularInt const& c1, CircularInt const& c2);	friend bool operator> (CircularInt const& c, int const& num);	friend bool operator> (int const& num, CircularInt const& c);
	friend bool operator== (CircularInt const& c1, CircularInt const& c2);	friend bool operator== (CircularInt const& c, int const& num);	friend bool operator== (int const& num, CircularInt const& c);
	friend bool operator!= (CircularInt const& c1, CircularInt const& c2);	friend bool operator!= (CircularInt const& c, int const& num);	friend bool operator!= (int const& num, CircularInt const& c);
	friend bool operator<= (CircularInt const& c1, CircularInt const& c2);	friend bool operator<= (CircularInt const& c, int const& num);	friend bool operator<= (int const& num, CircularInt const& c);
	friend bool operator>= (CircularInt const& c1, CircularInt const& c2);	friend bool operator>= (CircularInt const& c, int const& num);	friend bool operator>= (int const& num, CircularInt const& c);
	
	friend CircularInt operator+  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator+  (CircularInt c, int const& num);		friend CircularInt operator+  (int const& num, CircularInt c);
	friend CircularInt operator-  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator-  (CircularInt c, int const& num);		friend CircularInt operator-  (int const& num, CircularInt c);
	friend CircularInt operator*  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator*  (CircularInt c, int const& num);		friend CircularInt operator*  (int const& num, CircularInt c);
	friend CircularInt operator/  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator/  (CircularInt c, int const& num);		friend CircularInt operator/  (int const& num, CircularInt c);
	friend CircularInt operator%  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator%  (CircularInt c, int const& num);		friend CircularInt operator%  (int const& num, CircularInt c);
	friend CircularInt operator^  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator^  (CircularInt c, int const& num);		friend CircularInt operator^  (int const& num, CircularInt c);
	friend CircularInt operator|  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator|  (CircularInt c, int const& num);		friend CircularInt operator|  (int const& num, CircularInt c);
	friend CircularInt operator&  (CircularInt c1, CircularInt const& c2);		friend CircularInt operator&  (CircularInt c, int const& num);		friend CircularInt operator&  (int const& num, CircularInt c);
	friend CircularInt operator<< (CircularInt c1, CircularInt const& c2);		friend CircularInt operator<< (CircularInt c, int const& num);		friend CircularInt operator<< (int const& num, CircularInt c);
	friend CircularInt operator>> (CircularInt c1, CircularInt const& c2);		friend CircularInt operator>> (CircularInt c, int const& num);		friend CircularInt operator>> (int const& num, CircularInt c);
	friend CircularInt operator+=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator+=  (CircularInt& c, int const& num);	
	friend CircularInt operator-=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator-=  (CircularInt& c, int const& num);	 
	friend CircularInt operator*=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator*=  (CircularInt& c, int const& num);	
	friend CircularInt operator/=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator/=  (CircularInt& c, int const& num);	
	friend CircularInt operator%=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator%=  (CircularInt& c, int const& num);	
	friend CircularInt operator^=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator^=  (CircularInt& c, int const& num);	
	friend CircularInt operator|=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator|=  (CircularInt& c, int const& num);	
	friend CircularInt operator&=  (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator&=  (CircularInt& c, int const& num);	
	friend CircularInt operator<<= (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator<<= (CircularInt& c, int const& num);	
	friend CircularInt operator>>= (CircularInt& c1, CircularInt const& c2);	friend CircularInt operator>>= (CircularInt& c, int const& num);	
    
    public:
	
	int start, end, current;

	CircularInt (int first, int last) : start(first), end(last){
		int temp;
		current = start;
		if(start > end){
			temp = end;
			end = start;
			start = temp;
		}
	}
	
	CircularInt Normalization(CircularInt& cir);
	void operator=(CircularInt cir);
	void operator= (int n);
	CircularInt& operator++();   	//prefix - ++a
	CircularInt	operator++(int); 	//postfix - a++
	CircularInt& operator--();   	//prefix - --a
	CircularInt	operator--(int); 	//postfix - a--
};

#endif