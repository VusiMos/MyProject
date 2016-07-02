%%RUN THE TEST IN THE TERMINAL :
%IMPORTANT: THIS FOLDER SHOULD CONTAIN,the %"cmake_modules","include","src" folders and "CmakeLists.txt" text file!!
%NOTE: DO NOT DELETE THE ABOVE MENTIONED FOLDERS!

%% YOU can always ensure that you delete the cmake "build" folder after every use,since the following methods will create one each time(optional),however when you delete this folder ensure to copy all the files needed to run the game in the folder,eg .png,font files etc.
%%NOTE::The build file is your executable file.

%METHOD 1:

$ cd Desktop/RefrshC++/CmakeLearn/GAME

$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./GAME1


%METHOD 2:

$ cd Desktop/RefrshC++/CmakeLearn/GAME

$ cmake -H. -Bbuild           %%creates CMAKE configuration files build
$ cmake --build build -- -j3  %% generates the output/executable file(hello) in folder build.


%Test your program:

$ ./build/GAME1
