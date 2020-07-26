#include "megray/core/context.h"

#ifdef MEGRAY_WITH_HIP

#include <hip/hip_runtime.h>

#define HIP_CHECK(expr)                                 \
    do {                                                \
        hipError_t status = (expr);                     \
        if (status != hipSuccess) {                     \
            MEGRAY_ERROR("hip error [%d]: %s", status,  \
                hipGetErrorString(status));             \
            return MEGRAY_HIP_ERR;                      \
        }                                               \
    } while (0)

#define HIP_ASSERT(expr)                                \
    do {                                                \
        hipError_t status = (expr);                     \
        if (status != hipSuccess) {                     \
            MEGRAY_ERROR("hip error [%d]: %s", status,  \
                hipGetErrorString(status));             \
            MEGRAY_THROW("hip error");                  \
        }                                               \
    } while (0)

namespace MegRay{

class HipContext: public Context{
public:
    virtual ContextType type() const override{
        return MEGRAY_CTX_HIP;
    }
    hipStream_t& stream(){
        return m_stream;
    }
private:
    hipStream_t m_stream;
};

}

#endif