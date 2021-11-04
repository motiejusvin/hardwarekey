export PICO_SDK_PATH=../pico-sdk

if [ -d "build" ]
then
    cd build
else
    mkdir build && cd build
fi

cmake ../  
