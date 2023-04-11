# how to install googletest

## Method 1

```bash
apt-get install libgtest-dev
```

## Method 2

```bash
git clone https://github.com/google/googletest
cd googletest
mkdir build
cd build
cmake .. -DCMAKE_CXX_STANDARD=17
make
make install
```