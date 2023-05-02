#pragma once
#include "../libMta.h"

namespace LibMta
{
	class scopeGuard : public NonCopyable
	{
	public:
		explicit scopeGuard(std::function<void()>&& onExitScope) 
		{
			onExitScope = std::move(onExitScope);
			dismissed_ = false;
		}

		~scopeGuard()
		{
			if (!dismissed_)
			{
				onExitScope_();
			}
		}
		void Dismiss()
		{
			dismissed_ = true;
		}
	private:
		std::function<void()> onExitScope_;
		bool dismissed_;

	};
}

#define SCOPEGUARD_LINENAME_CAT(name, line) name##line
#define SCOPEGUARD_LINENAME(name, line) SCOPEGUARD_LINENAME_CAT(name, line)
#define ON_SCOPE_EXIT(callback) LibMta::scopeGuard SCOPEGUARD_LINENAME(EXIT, __LINE__)(callback)