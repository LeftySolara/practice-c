# Set up and run unity tests

if [ ! -d "./unity" ]
then
    echo "Downloading unity testing framework..."
    curl -L https://github.com/ThrowTheSwitch/Unity/archive/master.zip -o unity.zip --silent
    echo "Unpacking unity..."
    unzip -qq unity.zip
    mv Unity-master unity
    rm unity.zip
fi

if [ ! -d "./build" ]
then
    echo "Creating build directory..."
    mkdir -p build/Debug
fi

cd build/Debug
echo "Building targets..."
cmake ../.. && make
make test

cd ../..
echo "Done."
