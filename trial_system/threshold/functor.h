#ifndef FUNCTOR_H
#define FUNCTOR_H

#include "thresh.h"

struct ThreshComp {
	bool operator()(const std::Thresh& lhs, const std::Thresh& rhs);
};

#endif