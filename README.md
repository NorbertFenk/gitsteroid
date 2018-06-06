Tasks

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
