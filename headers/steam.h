#pragma once
#include <Windows.h>
#include "types.h"
#include  "xor/jm_xor.hpp"


namespace steam {
	bool	prepare();
	int		create_hook(void* dst, void* src, void* original);
}
