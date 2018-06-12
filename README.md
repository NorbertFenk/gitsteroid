## Prerequisite

**NOTE: SFML 2.5 handles CMake on a different way than 2.4. This tutorial was made on Xubuntu 17.10 where the repository contains the 2.4 version, so the project CMake files made according to that version. In the next section I will provide description to configure booth of them.**

### Install SFML to your computer
https://www.sfml-dev.org/tutorials/2.5/start-linux.php

### SFML 2.4 section

If you successfully compile the link's main.cpp with the g++ command your installation is good. On the other hand, this project uses CMake for the build so you may have to check the following file.

```
whereis SFML
```
The command will show where are the SFML related files.

Output:

```
SFML: /usr/include/SFML /usr/share/SFML
```

/usr/share/SFML should contains a cmake folder

```
cd /usr/share/SFML/cmake/Modules/
```
check the FindSFML.cmake file.

If there is no cmake and Moduels folders or the FindSFML.cmake does not exist, please create the folders and copy there the file.
Here you can find the correct FindSFML.cmake file https://github.com/SFML/SFML-Game-Development-Book/blob/master/CMake/FindSFML.cmake

### SFML 2.5 section

According to this link: https://en.sfml-dev.org/forums/index.php?topic=24070.0 you should modify the **CMakeLists.txt** files.

The **project root folder CMakeLists.txt** should looks like this:
```
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SFML_DIR "/usr/include/SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics system REQUIRED)

include_directories(src)

add_subdirectory(src)
```

The **src folder CMakeLists.txt** should look like this:
```
set(SOURCES
        main.cpp
        gameobject.cpp
        ship.cpp
        bullet.cpp
        game.cpp
        asteroid.cpp
        )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(gitsteroid ${SOURCES})

target_link_libraries(gitsteroid sfml-graphics sfml-system)
```


## Tasks

* GS-1 branch will help you to render a ship and provide functions to control it.
    * Use the ```git checkout master && git merge --no-ff GS-1-add-spaceship```
    ```
    NOTE:
    FAST-FORWARD MERGE
       Often the current branch head is an ancestor of the named commit. This is the most common case especially when invoked from git pull: you are tracking an upstream repository, you have committed no local changes, and
       now you want to update to a newer upstream revision. In this case, a new commit is not needed to store the combined history; instead, the HEAD (along with the index) is updated to point at the named commit, without
       creating an extra merge commit.

       This behavior can be suppressed with the --no-ff option.
    ```

* GS-2 branch will provide bullets and introduce the new Game class to manage game related objects and so on
    * Your task is to do an interactive rebase to the new master after you have merged the GS-1 branch. Please read carefully the information section.
    * Use ```git rebase --interactive master``` and see what happens.
    * Commits are in reverse order.

* GS-3 will be a hotfix branch where some of our customer wanted to see White spaceship instead of the the current black
    * Your task is to make some little mistake while modify the code and use the ```git commit --fixup <commit-id>``` command to make some commits with !fixup prefix.
    * !fixup prefixed commits are not welcomed on the glorious master branch so you should use ```git rebase --interactive --autosquash <commit-id>``` to squash them.
    * pay attention to that you should see the commit and !fixup <commit msg> in this order.

* GS-4 will be a branch where you should use the ```git bisect``` command
    help:
    ```
    https://git-scm.com/docs/git-bisect
    https://dockyard.com/blog/2016/07/26/how-to-bisect-ember
    example
    cd <git directory>
    git bisect start
    git bisect bad  # this command will assume the HEAD in this case
    git bisect good <commit id of a good commit>
    git bisect run ./<arbitrary scrip>
      e.g.
      ```
        #!/bin/sh

        cd build
        cmake .. && make -j4
      ```
    git bisect reset # to stop bisect session -> by default it will By default it will reset the HEAD to where it was before you started https://stackoverflow.com/questions/23156415/how-do-i-stop-git-bisect
    ```
