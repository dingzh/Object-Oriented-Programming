/*
 * SPtr.cpp
 *
 *  Created on: Nov. 11, 2018
 *      Author: mike
 *  Modified on: Dec 1, 2018
 *      Author: ding zhou
 */

#include "SPtr.hpp"

//------------------------------------------------------------------------------
// Copy constructor
SPtr::SPtr(const SPtr& sp) : count(sp.count), target(sp.target) {
    ++*count;
}

//------------------------------------------------------------------------------
// Copy assignment
SPtr&
SPtr::operator=(const SPtr& sp) {
    reset();
    count = sp.count;
    target = sp.target; // copy pointer
    ++*count;
    return *this;
}

//------------------------------------------------------------------------------
// Move constructor
SPtr::SPtr(SPtr&& sp) : count(sp.count), target(sp.target) {
    sp.count = nullptr;
    sp.target = nullptr;
}

//------------------------------------------------------------------------------
// Move assignment
SPtr& SPtr::
operator=(SPtr&& sp) {
    reset();
    count = sp.count;
    target = sp.target;
    sp.count = nullptr;
    sp.target = nullptr;
    return *this;
}

//------------------------------------------------------------------------------
// Unmanage target if currently being managed and adjust count.
// If count falls to 0, delete count and target.
// Afterwards, *this is back in its default empty state.
void SPtr::reset() {
    if (empty()) return;        // already empty; nothing to do
    // Unmanage target pointer
    if (--*count > 0) return;
    // No other references, so release managed storage
    delete count;
    delete target;
    count = nullptr;
    target = nullptr;
}

