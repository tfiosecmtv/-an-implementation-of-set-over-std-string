
// Lab Exercise 4.

#include "set.h"

bool set::equal( const std::string& s1, const std::string& s2 ) {
    size_t i=0,eq=0;
    if (s1.size()!=s2.size()) {
        return false;
    } else {
        while (s1[i]!='\0') {
            char c1 = _tolower(s1[i]);
            char c2 = _tolower(s2[i]);
            if (c1==c2) {
                eq++;
            }
            i++;
        }
        
        if (eq==i) {
            return true;
        }
    }
    return false;
}

set::set( std::initializer_list< std::string > init ) {
    for (std::string str : init) {
        if (this->contains(str)==false) {
            this->data.push_back(str);
        }
    }
}

bool set::contains( const std::string& el ) const {
    for (std::string a : data) {
        if (equal(a, el)) {
            return true;
        }
    }
    return false;
}
bool set::insert( const std::string& el ) {
    if (this->contains(el)==true) {
        return false;
    } else {
        data.push_back(el);
        return true;
    }
}
size_t set::insert( const set& s ) {
    size_t i = 0;
    for (std::string a : s.data) {
        if (insert(a)) {
            i++;
        }
    }
    return i;
}

bool set::remove( const std::string& el ){
    if (this->contains(el)) {
        for ( size_t i = 0; i<data.size(); ++ i) {
            if (equal(data[i], el)) {
                std::swap(data[i], data.back());
                data.pop_back();
                return true;
            }
        }
    }
    return false;
}

size_t set::remove( const set& s ) {
    size_t i = 0;
    for (std::string a : s.data) {
        if (remove(a)) {
            i++;
        }
    }
    return i;
}

size_t set::size( ) const {
    return data.size();
}
void set::clear( ) {
    data.clear();
}
std::ostream& operator << ( std::ostream& out, const set& s ) {
    out << "{";
    for (std::vector<std::string>::const_iterator a=s.begin();a<s.end(); ++ a) {
        out << *a ;
        if (a!=(s.end()-1)) { //to check when to put the comma
            out <<  ", ";
        }
    }
    out << "}";
    return out;
}
bool subset( const set& s1, const set& s2 ) {
    size_t i = 0;
    for (auto & a1 : s1) {
        if (s2.contains(a1)) {
            i++;
        }
    }
    if (i==s1.size()) {
        return true;
    }
    return false;
}

