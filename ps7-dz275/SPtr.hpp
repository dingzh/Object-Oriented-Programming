/*
 * SPtr.hpp
 *
 *  Created on: Feb 25, 2016
 *      Author: mike
 *  Modified on: Dec 1, 2018
 *      Author: Ding Zhou
 */

#include "Block.hpp"

#ifndef SPTR_HPP_
#define SPTR_HPP_

#include <iostream>
#include <exception>

#include "Serial.hpp"

class Block;
using namespace std;
using T = Block;

// ----------------------------------------------------------------------------
// Smart pointer exception class
class SPexception : std::exception {
private:
    string s;
public:
    SPexception( string s ) : s(s) {}
    virtual const char* what() const noexcept { return s.data(); }
};

// ----------------------------------------------------------------------------
// Smart pointer class
class SPtr {
private:
    unsigned* count = nullptr;    // shared object among all SPtr with same target
    T* target = nullptr;          // shared target object

public:
    SPtr():count( nullptr), target(nullptr) {}
    SPtr( T* p ): count( new unsigned(1) ), target( p ) {}
    SPtr( const SPtr& sp );
    SPtr& operator=( const SPtr& sp );
    SPtr( SPtr&& sp );
    SPtr& operator=( SPtr&& sp );
    ~SPtr() { reset(); }

    bool empty() const { return count==nullptr; };
    void reset();

    // Follow operator.
    T& operator*() const {
        if (!empty()) return *target;
        else throw SPexception("Can't follow empty SPtr");
    }

    T* operator->() const {
        if (!empty()) return target;
        else throw SPexception("Can't follow empty SPtr");
    }
};

#endif /* SPTR_HPP_ */
