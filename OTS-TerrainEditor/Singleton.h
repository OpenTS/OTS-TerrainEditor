/* 
 * File:   Singleton.h
 * Author: Maikel
 *
 * Created on 3 maart 2013, 14:05
 */

#include "base.h"
#include <cassert>

#ifndef SINGLETON_H
#define	SINGLETON_H

namespace OTS
{

    template <typename T> class Singleton
    {
        private:
            Singleton(const Singleton<T> &);
            Singleton& operator=(const Singleton<T> &);
       
        protected:
                static T* _singleton;
                
         public:
                    Singleton(void) 
                    {
                        assert(!_singleton);
                        _singleton = static_cast<T*> (this);
                    }
                    
                    ~Singleton(void)
                    {
                        assert(_singleton);
                        _singleton = 0;
                    }
                    
                    static T* getSingletonPointer( void )
                    {
                        return _singleton;
                    }
    };
}

#endif        /* SINGLETON_H */