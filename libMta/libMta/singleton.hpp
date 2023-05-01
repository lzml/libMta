#pragma once
#include "nonCopyable.h"

namespace libMta 
{
	template <typename T>
	class Singleton : public LibMta::NonCopyable
	{
	public:
	 template<typename ... Args>
	 static T* Instance(Args ... args)
	 {
		 if (m_pInstance == nullptr)
		 {
			 m_pInstance = new T(std::forward<Args>(args) ...);
		 }
		 return m_pInstance;
	 }

	 static T* getInstance()
	 {
		 if (m_pInstance == nullptr)
		 {
			 throw std::logic_error("The Singleton is not init");
		 }
		 return m_pInstance;
	 }

	 static void DestroyInstance()
	 {
		 if (m_pInstance)
		 {
			 delete m_pInstance;
			 m_pInstance = nullptr;
		 }
	 }
		
	private:
		static T* m_pInstance;

	};


	template<typename T>T* Singleton<T>::m_pInstance = nullptr;
}





