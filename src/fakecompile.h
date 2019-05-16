#ifndef FAKECOMPILE_H
#define FAKECOMPILE_H

#if _WIN32
#define FAKECOMPILE_WINDOWS
#else
#define FAKECOMPILE_UNIX
#endif

#if 0
#define FAKECOMPILE_DEBUG
#endif

namespace fakecompile
{
namespace VERSION
{
    const int MAJOR = 1;
    const int MINOR = 1;
    const int PATCH = 0;

    //const int VERSION = (MAJOR * 10000 + MINOR * 100 + PATCH);

} // namespace VERSION
} // namespace fakecompile

#endif // FAKECOMPILE_H