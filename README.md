example cmake and gtest with conan
===

gtest 1.7 runs, 1.8 crashes with same configuration and code

```
/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test --gtest_filter=Cache.*:Cache/*.*:*/Cache.*/*:*/Cache/*.* --gtest_color=no
*** Error in `/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test': munmap_chunk(): invalid pointer: 0x000000000175bc90 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7f7f2353b7e5]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x1a8)[0x7f7f23548698]
/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test[0x40598a]
/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test[0x40563d]
/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test[0x4056c3]
/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test[0x431eed]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x7f)[0x7f7f234e47bf]
/home/wassj/dev/code/jw3/scratch/example-gtest-conan/cmake-build-debug/test/cache_test[0x4050a9]

```

also some strangeness when linking a trivial test like

```
   TEST(Foo, foo) {
      EXPECT_EQ(1, 1);
   }
```

```
/cache_test.dir/CacheTest.cpp.o: In function `testing::AssertionResult testing::internal::CmpHelperEQ<int, int>(char const*, char const*, int const&, int const&)':
/home/wassj/.conan/data/gtest/1.7.0/bincrafters/stable/package/2de3d908e1d9b246c9b2b6ea5c083ff1297f138b/include/gtest/gtest.h:1460: undefined reference to `testing::internal::EqFailure(char const*, char const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, bool)'
```
