git clone https://github.com/google/googletest.git

cd googletest

cmake -B build -DCMAKE_INSTALL_PREFIX=/Users/palchukovsky/Projects/webinar-gtest/project_prebuilt_gtest/googletest_prebuild

cmake --build build --target install

cd ..

cmake -B build -DGTEST_ROOT=/Users/palchukovsky/Projects/webinar-gtest/project_prebuilt_gtest/googletest_prebuild

cmake --build build

# Windows:
cmake -B build -DCMAKE_INSTALL_PREFIX=/Users/palchukovsky/Projects/webinar-gtest/project_prebuilt_gtest/googletest_prebuild -Dgtest_force_shared_crt=ON