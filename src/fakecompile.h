#ifndef FAKECOMPILE_H
#define FAKECOMPILE_H

#if _WIN32
#define FAKECOMPILE_WINDOWS
#elif
#define FAKECOMPILE_UNIX
#endif

namespace fakecompile
{
namespace VERSION
{
    const int MAJOR = 1;
    const int MINOR = 0;
    const int PATCH = 2;

    //const int VERSION = (MAJOR * 10000 + MINOR * 100 + PATCH);

} // namespace VERSION
} // namespace fakecompile

#endif // FAKECOMPILE_H