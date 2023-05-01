// libMta.cpp: 定义应用程序的入口点。
//
#pragma once
#include "../libMta.h"

namespace libMta
{

	//解包变长模板
#define FOR_EACH_ARGS(FUNC) std::initializer_list<int>{([&]{FUNC}(),0)...}

}





