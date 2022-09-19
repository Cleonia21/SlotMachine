# /bin/bash

mkdir SDL/build
cd SDL/build
../configure
make
sudo make install

cd ../..
mkdir SDL_image/build
cd SDL_image/build
../configure
make
sudo make install

cd ../..
make