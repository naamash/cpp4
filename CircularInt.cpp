#include <iostream>
#include <math.h>
#include "CircularInt.hpp"
using namespace std;


CircularInt Normalization(CircularInt& cir){
    int numVal = cir.end - cir.start + 1;
    if(cir.current > cir.end){
        while(cir.current > cir.end)
            cir.current -= numVal;
    }
    else if(cir.current < cir.start){
        while(cir.current < cir.start)
            cir.current += numVal;  
    }
    return cir;
}

CircularInt operator~ (CircularInt const& cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = ~cir.current;
    return Normalization(temp);
}

CircularInt operator- (CircularInt const cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = (-1)*cir.current;
    return Normalization(temp);
}

istream& operator>> (istream& is, CircularInt& cir){
	int temp;
	is >> temp;
	if(temp>cir.end || temp<cir.start)
		throw std::invalid_argument( "value not in range\n" );
	cir.current = temp;
	return is;
}

ostream& operator<< (ostream& os, const CircularInt& cir){
    return os << cir.current;
}

void CircularInt::operator=(int n){
    current = n;
    int numVal = end - start + 1;
    if(current > end){
        while(current > end)
            current -= numVal;
    }
    else if(current < start){
        while(current < start)
            current += numVal;    
    }    
}

void CircularInt::operator=(CircularInt cir){
    current = cir.current;
    int numVal = end - start + 1;
    if(current > end){
        while(current > end)
            current -= numVal;
    }
    else if(current < start){
        while(current < start)
            current += numVal;    
    }    
}

CircularInt& CircularInt :: operator++(){
    if(current+1 <= end)
        current += 1;
    else current = start;    
    return *this;
}

CircularInt CircularInt :: operator++(int){
	CircularInt ans(*this);
    ++(*this);
	return ans;
}

CircularInt& CircularInt :: operator--(){
    if(current-1 >= start)
        current -= 1;
    else current = end;    
    return *this;
}

CircularInt CircularInt :: operator--(int){
	CircularInt ans(*this);
    --(*this);
	return ans;
}

bool operator< (CircularInt const& hours1, CircularInt const& hours2){
    if (hours1.current < hours2.current){
        return true;
    }
    return false;
}

bool operator> (CircularInt const& hours1, CircularInt const& hours2){
    if (hours1.current > hours2.current){
        return true;
    }
    return false;
}

bool operator== (CircularInt const& hours1, CircularInt const& hours2){
    if ((hours1.start == hours2.start)&&(hours1.end == hours2.end)&&(hours1.current == hours2.current)){
        return true;
    }
    return false;
}

bool operator!= (CircularInt const& hours1, CircularInt const& hours2){
    if ((hours1.start != hours2.start)||(hours1.end != hours2.end)||(hours1.current != hours2.current)){
        return true;
    }
    return false;
}

bool operator<= (CircularInt const& hours1, CircularInt const& hours2){
    if (hours1.current <= hours2.current){
        return true;
    }
    return false;
}

bool operator>= (CircularInt const& hours1, CircularInt const& hours2){
    if (hours1.current >= hours2.current){
        return true;
    }
    return false;
}

bool operator< (CircularInt const& hours1, int const& num){
    if (hours1.current < num){
        return true;
    }
    return false;
}

bool operator> (CircularInt const& hours1, int const& num){
    if (hours1.current > num){
        return true;
    }
    return false;
}

bool operator== (CircularInt const& hours1, int const& num){
    if (hours1.current == num){
        return true;
    }
    return false;
}

bool operator!= (CircularInt const& hours1, int const& num){
    if (hours1.current != num){
        return true;
    }
    return false;
}

bool operator<= (CircularInt const& hours1, int const& num){
    if (hours1.current <= num){
        return true;
    }
    return false;
}

bool operator>= (CircularInt const& hours1, int const& num){
    if (hours1.current >= num){
        return true;
    }
    return false;
}

bool operator< (int const& num, CircularInt const& hours1){
    if (num < hours1.current){
        return true;
    }
    return false;
}

bool operator> (int const& num, CircularInt const& hours1){
    if (num > hours1.current){
        return true;
    }
    return false;
}

bool operator== (int const& num, CircularInt const& hours1){
    if (num == hours1.current){
        return true;
    }
    return false;
}

bool operator!= (int const& num, CircularInt const& hours1){
    if (num != hours1.current){
        return true;
    }
    return false;
}

bool operator<= (int const& num, CircularInt const& hours1){
    if (num <= hours1.current){
        return true;
    }
    return false;
}

bool operator>= (int const& num, CircularInt const& hours1){
    if (num >= hours1.current){
        return true;
    }
    return false;
}

CircularInt operator+ (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current += cir2.current;
    return Normalization(temp);
}

CircularInt operator- (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current - cir2.current;
    return Normalization(temp);
	
}

CircularInt operator* (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current * cir2.current;
    return Normalization(temp);
}

CircularInt operator/ (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    CircularInt temp2 {cir1.start, cir1.end};
    temp2.current = cir1.current;
    int c = 0;
    for(int i = cir1.start; i <= cir1.end; i++){
        temp.current = i;
        if(c > 0) break;
        else{
            if((temp*cir2) == cir1){
                temp2.current = temp.current;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    return temp2;
}

CircularInt operator% (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current % cir2.current;
    return Normalization(temp);
}

CircularInt operator^ (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current ^ cir2.current;
    return Normalization(temp);
}

CircularInt operator| (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current | cir2.current;
    return Normalization(temp);
}

CircularInt operator& (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current & cir2.current;
    return Normalization(temp);
}

CircularInt operator<< (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current << cir2.current;
    return Normalization(temp);
}

CircularInt operator>> (CircularInt cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    temp.current = cir1.current;
    temp.current = temp.current >> cir2.current;
    return Normalization(temp);
}

CircularInt operator+= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current += cir2.current; 
	return Normalization(cir1);
}

CircularInt operator-= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current -= cir2.current; 
	return Normalization(cir1);
}

CircularInt operator*= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current *= cir2.current;
    return Normalization(cir1);
}

CircularInt operator/= (CircularInt& cir1, CircularInt const& cir2){
    CircularInt temp {cir1.start, cir1.end};
    int c = 0;
    for(int i = cir1.start; i <= cir1.end; i++){
        temp.current = i;
        if(c > 0) break;
        else{
            if((temp*cir2) == cir1){
                cir1.current = temp.current;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    return cir1;
}

CircularInt operator%= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current %= cir2.current;
    return Normalization(cir1);
}

CircularInt operator^= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current ^= cir2.current;
    return Normalization(cir1);
}

CircularInt operator|= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current |= cir2.current;
    return Normalization(cir1);
}

CircularInt operator&= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current &= cir2.current;
    return Normalization(cir1);
}

CircularInt operator<<= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current <<= cir2.current;
    return Normalization(cir1);
}

CircularInt operator>>= (CircularInt& cir1, CircularInt const& cir2){
    cir1.current >>= cir2.current;
    return Normalization(cir1);
}

CircularInt operator+ (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current + num;
    return Normalization(temp);
}

CircularInt operator- (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current - num;
    return Normalization(temp);
	
}

CircularInt operator* (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current * num;
    return Normalization(temp);
}

CircularInt operator/ (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    CircularInt temp2 {cir.start, cir.end};
    CircularInt temp3 {cir.start, cir.end};
    temp2.current = cir.current;
    temp3.current = cir.current;
    int c = 0;
    for(int i = cir.start; i <= cir.end; i++){
        temp.current = i;
        if(c > 0) break;
        else{
            if((temp*num) == cir){
                temp2.current = temp.current;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
    temp3.current = temp2.current;
	return temp3;
}

CircularInt operator% (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current % num;
    return Normalization(temp);
}

CircularInt operator^ (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current ^ num;
    return Normalization(temp);
}

CircularInt operator| (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current | num;
    return Normalization(temp);
}

CircularInt operator& (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current & num;
    return Normalization(temp);
}

CircularInt operator<< (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current << num;
    return Normalization(temp);
}

CircularInt operator>> (CircularInt cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current >> num;
    return Normalization(temp);
}

CircularInt operator+= (CircularInt& cir, int const& num){
    cir.current += num;
    return Normalization(cir); 
}

CircularInt operator-= (CircularInt& cir, int const& num){
    cir.current -= num;
    return Normalization(cir); 
}

CircularInt operator*= (CircularInt& cir, int const& num){
    cir.current *= num;
    return Normalization(cir); 
}

CircularInt operator/= (CircularInt& cir, int const& num){
    CircularInt temp {cir.start, cir.end};
    int c = 0;
    for(int i = cir.start; i <= cir.end; i++){
        temp.current = i;
        if(c > 0) break;
        else{
            if((temp*num) == cir){
                cir.current = temp.current;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
	return cir;
}

CircularInt operator%= (CircularInt& cir, int const& num){
    cir.current %= num;
    return Normalization(cir);
}

CircularInt operator^= (CircularInt& cir, int const& num){
    cir.current ^= num;
    return Normalization(cir);
}

CircularInt operator|= (CircularInt& cir, int const& num){
    cir.current |= num;
    return Normalization(cir);
}

CircularInt operator&= (CircularInt& cir, int const& num){
    cir.current &= num;
    return Normalization(cir);
}

CircularInt operator<<= (CircularInt& cir, int const& num){
    cir.current <<= num;
    return Normalization(cir);
}

CircularInt operator>>= (CircularInt& cir, int const& num){
    cir.current >>= num;
    return Normalization(cir);
}

CircularInt operator+ (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current + num;
    return Normalization(temp);
}

CircularInt operator- (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num - temp.current;
    return Normalization(temp);
	
}

CircularInt operator* (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = temp.current * num;
    return Normalization(temp);
}

CircularInt operator/ (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    CircularInt temp2 {cir.start, cir.end};
    CircularInt temp3 {cir.start, cir.end};
    temp2.current = cir.current;    
    int c = 0;
    for(int i = cir.start; i <= cir.end; i++){
        temp.current = i;
        if(c > 0) break;
        else{
            if((temp*cir) == num){
                temp2.current = temp.current;
                c++;
            }
        }
    }
    if(c == 0){
        throw invalid_argument("THERE IS NO SUCH NUMBER!");
    }
	temp3.current = temp2.current;
	return temp3;
}

CircularInt operator% (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num % temp.current;
    return Normalization(temp);
}

CircularInt operator^ (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num ^ temp.current;
    return Normalization(temp);
}

CircularInt operator| (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num | temp.current;
    return Normalization(temp);
}

CircularInt operator& (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num & temp.current;
    return Normalization(temp);
}

CircularInt operator<< (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num << temp.current;
    return Normalization(temp);
}

CircularInt operator>> (int const& num, CircularInt cir){
    CircularInt temp {cir.start, cir.end};
    temp.current = cir.current;
    temp.current = num >> temp.current;
    return Normalization(temp);
}