cd clib
make && cp libuuidx.so /usr/lib64/
cd ../lib
cp resty/* /usr/local/share/lua/5.1/resty/
cd ../../
