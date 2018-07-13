#include <Cache.h>
#include <gtest/gtest.h>

TEST(Cache, cache_test) {
   Cache c;
   c.put("x", "y");

   EXPECT_STREQ(c.get("x").value_or("_").c_str(), std::string("y").c_str());
}
